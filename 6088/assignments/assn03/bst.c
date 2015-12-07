#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/* Returns a bst_t structure with an int array vals of size "size" and the
 * size field set appropriately. */
bst_t* make_tree(int size) {
	if (size <= 0) {
		return NULL ;
	}

	bst_t* new_bst = (bst_t*)malloc(sizeof(bst_t));
	new_bst->size = size;
	new_bst->vals = (int*)malloc(sizeof(int)*size);

	return new_bst;
}

/*
 * Initialize the binary search tree.
 * HINT: What should we initialize values to?  What requirements might we have
 * to add to the tree specification?
 */
void init_tree(bst_t* tree) {
	if (tree == NULL) {
		return ;
	}

	int i;
	for (i = 0; i < tree->size; i++) {
		tree->vals[i] = -1;
	}
}

/*
 * Inserts a new value into a given tree.
 */
void insert(int val, bst_t* tree) {
	if (tree == NULL) {
		return ;
	}

	int index = 1;
	int size = tree->size;
	int* vals = tree->vals;
	int* p = tree->vals;

	while (*p != -1) {
		if (*p == val) {
			return ;
		}

		if (*p > val) {
			index = index * 2;
		} else {
			index = index * 2 + 1;
		}

		if (index >= size) {
			return ;
		}

		p = vals + index - 1;
	}

	*p = val;
}

bool find_val(int val, bst_t* tree) {
	if (tree == NULL) {
		return FALSE;
	}

	int index = 1;
	int size = tree->size;
	int* vals = tree->vals;
	int* p = tree->vals;

	while (*p != val) {
		if (*p == -1) {
			return FALSE;
		}

		if (*p > val) {
			index = index * 2;
		} else {
			index = index *2 + 1;
		}

		if (index >= size) {
			return FALSE;
		}

		p = vals + index - 1;
	}

	return TRUE;
}

/*
 * Given a pointer to the root, frees the memory associated with an entire list.
 */
void delete_bst(bst_t* tree) {
	if (tree == NULL) {
		return ;
	}

	free(tree->vals);
	free(tree);
}
/* Given a pointer to the root, prints all of the values in a list. */
void print_bst(bst_t* tree) {
	if (tree == NULL) {
		return ;
	}

	int i;
	int size = tree->size;
	int* vals = tree->vals;

	for (i = 0; i < size; i++) {
		printf("%d ", vals[i]);
	}
	printf("\n");
}
