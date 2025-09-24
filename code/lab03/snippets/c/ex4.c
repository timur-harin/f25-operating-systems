#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>

// Global type flag so operators know which datatype to operate on
typedef enum { TYPE_INT = 0, TYPE_DOUBLE = 1 } AggregateType;
static AggregateType g_current_type = TYPE_INT;

static void *sum_op(const void *a, const void *b) {
    static int result_i;
    static double result_d;
    if (g_current_type == TYPE_INT) {
        result_i = *(const int *)a + *(const int *)b;
        return &result_i;
    } else {
        result_d = *(const double *)a + *(const double *)b;
        return &result_d;
    }
}

static void *mul_op(const void *a, const void *b) {
    static int result_i;
    static double result_d;
    if (g_current_type == TYPE_INT) {
        result_i = *(const int *)a * *(const int *)b;
        return &result_i;
    } else {
        result_d = *(const double *)a * *(const double *)b;
        return &result_d;
    }
}

static void *max_op(const void *a, const void *b) {
    static int result_i;
    static double result_d;
    if (g_current_type == TYPE_INT) {
        result_i = *(const int *)a > *(const int *)b ? *(const int *)a : *(const int *)b;
        return &result_i;
    } else {
        result_d = *(const double *)a > *(const double *)b ? *(const double *)a : *(const double *)b;
        return &result_d;
    }
}

static void *aggregate(void *base, size_t size, int n, void *initial_value,
                       void *(*opr)(const void *, const void *)) {
    if (!base || n <= 0 || !initial_value || !opr) return NULL;

    if (size == sizeof(int)) {
        g_current_type = TYPE_INT;
        static int acc_i; // return lives long enough
        acc_i = *(int *)initial_value;
        int *arr = (int *)base;
        for (int i = 0; i < n; i++) {
            const int *tmp = (const int *)opr(&acc_i, &arr[i]);
            acc_i = *tmp;
        }
        return &acc_i;
    } else if (size == sizeof(double)) {
        g_current_type = TYPE_DOUBLE;
        static double acc_d;
        acc_d = *(double *)initial_value;
        double *arr = (double *)base;
        for (int i = 0; i < n; i++) {
            const double *tmp = (const double *)opr(&acc_d, &arr[i]);
            acc_d = *tmp;
        }
        return &acc_d;
    }
    return NULL; // only int/double supported per slides
}

int main(void) {
    int ai[5] = {1, 2, 3, 4, 5};
    double ad[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    int init_add_i = 0;
    int init_mul_i = 1;
    int init_max_i = INT_MIN;

    double init_add_d = 0.0;
    double init_mul_d = 1.0;
    double init_max_d = -DBL_MAX;

    void *r;

    r = aggregate(ai, sizeof(int), 5, &init_add_i, sum_op);
    printf("int sum: %lld\n", *(long long *)r);
    r = aggregate(ai, sizeof(int), 5, &init_mul_i, mul_op);
    printf("int mul: %lld\n", *(long long *)r);
    r = aggregate(ai, sizeof(int), 5, &init_max_i, max_op);
    printf("int max: %d\n", *(int *)r);

    r = aggregate(ad, sizeof(double), 5, &init_add_d, sum_op);
    printf("double sum: %.6f\n", *(double *)r);
    r = aggregate(ad, sizeof(double), 5, &init_mul_d, mul_op);
    printf("double mul: %.6f\n", *(double *)r);
    r = aggregate(ad, sizeof(double), 5, &init_max_d, max_op);
    printf("double max: %.6f\n", *(double *)r);

    return 0;
}


