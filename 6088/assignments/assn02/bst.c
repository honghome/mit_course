#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/*
 * Creates a new node from a given value, allocating heap memory for it.
 */
node_t* make_tree(int val) {
  node_t* new_tree = malloc(sizeof(node_t));
  new_tree->val = val;
  new_tree->left = NULL;
  new_tree->right = NULL;
  return new_tree;
}

/*
 * Inserts a new value into a given binary search tree, allocating heap memory
 * for it.
 */
node_t* insert(int val, node_t* cur_root) {
  /* YOUR CODE HERE */  
  /*if (cur_root == NULL) {
    cur_root = new_node;
  }
  node_t* cur = cur_root;
  while (true) {
    if (cur->val == val) break;
    if (cur->val > val) {
      if (cur->left == NULL) {
        cur->left = new_node;
        break;
      } else {
        cur = cur->left;
      }
    } else {
      if (cur->right == NULL) {
        cur->right = new_node;
      } else {
        cur = cur->right;
        break;
      }
    }
  }
  return cur_root;*/

  if (cur_root == NULL) {
    node_t* new_node = make_tree(val);
    cur_root = new_node;
  } else {
    if (cur_root->val > val) {
      cur_root->left = insert(val, cur_root->left);
    } else if (cur_root->val < val){
      cur_root->right = insert(val, cur_root->right);
    }
  }
  return cur_root;
}

bool find_val(int val, node_t* root) {
  /* YOUR CODE HERE */
  if (root == NULL) return FALSE;
  if (root->val == val) return TRUE;
  else if (root->val > val) return find_val(val, root->left);
  return find_val(val, root->right);
}

/*
 * Given a pointer to the root, frees the memory associated with an entire tree.
 */
void delete_bst(node_t* root) {
  /* YOUR CODE HERE */
  if (root) {
    delete_bst(root->left);
    delete_bst(root->right);
    free(root);
  }
}

/* Given a pointer to the root, prints all o fthe values in a tree. */
void print_bst(node_t* root) {
  if (root != NULL) {
    printf("%d ", root->val);
    print_bst(root->left);
    print_bst(root->right);
  }
  return;
}
