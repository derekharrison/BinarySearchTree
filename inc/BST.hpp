/*
 * BST.hpp
 *
 *  Created on: Apr 15, 2019
 *      Author: d-w-h
 */

#ifndef BST_HPP_
#define BST_HPP_

#include <cstdlib>
#include "../inc/Data.hpp"

typedef struct Node {
    int key;
    bool has_data;
    Data data;
    Node* left_child = NULL;
    Node* right_child = NULL;
    Node* parent = NULL;
} nd;

class BST {
private:
    nd* root;
    int size;

    nd* subtree_minimum(nd* node);
    nd* subtree_maximum(nd* node);
    nd* tree_minimum();
    nd* tree_maximum();
    nd* successor(nd* node);
    nd* predecessor(nd* node);
    void insert_node_fcn(int key);
    void delete_node_fcn(nd* node);
public:
    BST();
    void insert_node(int key);
    void delete_node(int key);
    nd* search_node(int key);
    void set_data_node(int key, Data data);
    void print_data_node(int key);
    void print_tree();
    void print_tree_reverse();
    bool verify_bst_invariant();
};

#endif /* BST_HPP_ */
