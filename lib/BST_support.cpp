/*
 * BST_support.cpp
 *
 *  Created on: Apr 18, 2019
 *      Author: d-w-h
 */

#include "../inc/BST.hpp"

void update_linkage(nd* node_ptr) {
	/*Case: successor is left child and has no right child*/
	if(node_ptr->key < node_ptr->parent->key && node_ptr->right_child == NULL) {
		node_ptr->parent->left_child = NULL;
	}
	/*Case: successor is left child and has right child*/
	else if(node_ptr->key < node_ptr->parent->key && node_ptr->right_child != NULL) {
		node_ptr->parent->left_child = node_ptr->right_child;
		node_ptr->right_child->parent = node_ptr->parent;
	}
	/*Case: successor is right child and has no right child*/
	else if(node_ptr->key > node_ptr->parent->key && node_ptr->right_child == NULL) {
		node_ptr->parent->right_child = NULL;
	}
	/*Case: successor is right child and has right child*/
	else if(node_ptr->key > node_ptr->parent->key && node_ptr->right_child != NULL) {
		node_ptr->parent->right_child = node_ptr->right_child;
		node_ptr->right_child->parent = node_ptr->parent;
	}
	else {};
}

void nullify_node (nd* node) {
	node->left_child = NULL;
	node->right_child = NULL;
	node->parent = NULL;
}

void update_children(nd* node_ptr, nd* node) {
	if(node->left_child != NULL) {
		node_ptr->left_child = node->left_child;
		node->left_child->parent = node_ptr;
	}
	if(node->right_child != NULL) {
		node_ptr->right_child = node->right_child;
		node->right_child->parent = node_ptr;
	}
}
