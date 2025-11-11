#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int value;
	struct node *left;
	struct node *right;
} node;

static node* make(int value, node *left, node *right) {
	node *n = (node*)malloc(sizeof(node));
	n->value = value;
	n->left = left;
	n->right = right;
	return n;
}

static void print_pre(const node *n) {
	if (!n) { printf("."); return; }
	printf("(%d ", n->value);
	print_pre(n->left);
	printf(" ");
	print_pre(n->right);
	printf(")");
}

static node* cow_update(const node *root, int path_mask, int new_value) {
	// path_mask: bit=0 -> go left, bit=1 -> go right; from msb to lsb for depth
	if (!root) return NULL;
	node *copy = make(root->value, root->left, root->right);
	node *cur = copy;
	for (int bit = 2; bit >= 0; bit--) { // depth 3 demo
		int dir = (path_mask >> bit) & 1;
		if (bit == 0) {
			if (dir == 0) {
				cur->left = make(new_value, NULL, NULL);
			} else {
				cur->right = make(new_value, NULL, NULL);
			}
		} else {
			if (dir == 0) {
				cur->left = make(cur->left ? cur->left->value : 0, cur->left ? cur->left->left : NULL, cur->left ? cur->left->right : NULL);
				cur = cur->left;
			} else {
				cur->right = make(cur->right ? cur->right->value : 0, cur->right ? cur->right->left : NULL, cur->right ? cur->right->right : NULL);
				cur = cur->right;
			}
		}
	}
	return copy;
}

static void free_tree(node *n) {
	if (!n) return;
	free_tree(n->left);
	free_tree(n->right);
	free(n);
}

int main(void) {
	// base tree
	node *root = make(1, make(2, NULL, NULL), make(3, NULL, NULL));
	printf("[CoW] Base tree: ");
	print_pre(root); printf("\n");
	// snapshot A
	node *snapA = root;
	// update on copy: change right->left to 99 using path: right(1),left(0),stop
	node *updated = cow_update(root, 0b100, 99);
	printf("[CoW] Updated tree: ");
	print_pre(updated); printf("\n");
	printf("[CoW] Snapshot A unchanged: ");
	print_pre(snapA); printf("\n");
	return 0;
}


