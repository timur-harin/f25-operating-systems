#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

static double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

static double area(Point a, Point b, Point c) {
    return 0.5 * fabs(a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y);
}

int main(void) {
    Point A = {2.5, 6.0};
    Point B = {1.0, 2.2};
    Point C = {10.0, 6.0};

    double dAB = distance(A, B);
    double areaABC = area(A, B, C);

    printf("Distance AB: %.6f\n", dAB);
    printf("Area ABC: %.6f\n", areaABC);
    return 0;
}



