/*
 * BST.cpp
 *
 *  Created on: Apr 15, 2019
 *      Author: d-w-h
 */

#include <iostream>
#include <cstdlib>
#include "../inc/BST.hpp"
#include "../inc/BST_support.hpp"
#include "../inc/Data.hpp"

BST::BST() {
    this->root = NULL;
    this->size = 0;
}

void BST::insert_node(int key) {
    try {
        BST::insert_node_fcn(key);
    }
    catch (const char * s) {
        std::cout << "Unable to insert node: "
                  << s << std::endl;
    }
}

void BST::delete_node(int key) {
    try {
        nd* node_ptr = BST::search_node(key);
        BST::delete_node_fcn(node_ptr);
    }
    catch (const char * s) {
        std::cout << "Unable to delete node: "
                  << s << std::endl;
    }
}

nd* BST::search_node(int key) {
    nd* node_x = this->root;
    bool key_found = false;
    while(node_x != NULL) {
        if(key == node_x->key) {
            key_found = true;
            return node_x;
        }
        else if(key < node_x->key)
            node_x = node_x->left_child;
        else if(key > node_x->key)
            node_x = node_x->right_child;
        else
            throw "Invalid key";
    }
    if(key_found == false)
        throw "Node not found";

    return node_x;
}

void BST::set_data_node(int key, Data data) {
    try {
        nd* node_ptr = BST::search_node(key);
        if(node_ptr->has_data == false) {
            node_ptr->data = data;
            node_ptr->has_data = true;
        }
        else
            throw "Node contains data";
    }
    catch (const char * s) {
        std::cout << "Unable to set data: "
                  << s << std::endl;
    }
}

void BST::print_data_node(int key) {
    try {
        nd* node_ptr = BST::search_node(key);
        Data data = node_ptr->data;
        std::cout << "height: " << data.height << std::endl
                  << "name: "   << data.name   << std::endl;
    }
    catch (const char * s) {
        std::cout << "Unable to print data: "
                  << s << std::endl;
    }
}

void BST::print_tree() {
    nd* node_x = BST::tree_minimum();
    while(node_x != NULL) {
        std::cout << "key " << node_x->key;
        if(node_x->left_child != NULL)
            std::cout << ", left_key " << node_x->left_child->key;
        if(node_x->right_child != NULL)
            std::cout << ", right_key " << node_x->right_child->key;
        if(node_x->parent != NULL)
            std::cout << ", parent_key " << node_x->parent->key;
        node_x = BST::successor(node_x);
        if(node_x != NULL)
            std::cout << ", successor " << node_x->key;
        std::cout << std::endl;
    }

    std::cout << "size tree " << this->size << std::endl;
}

void BST::print_tree_reverse() {
    nd* node_x = BST::tree_maximum();
    while(node_x != NULL && this->size > 0) {
        std::cout << "key " << node_x->key << std::endl;
        node_x = BST::predecessor(node_x);
    }
}

bool BST::verify_bst_invariant() {
    bool is_bst = true;
    nd* node_x = BST::tree_minimum();
    while(node_x != NULL) {
        if(node_x->left_child != NULL &&
                node_x->left_child->key > node_x->key) {
            is_bst = false;
        }
        if(node_x->right_child != NULL &&
                node_x->right_child->key < node_x->key) {
            is_bst = false;
        }
        node_x = BST::successor(node_x);
    }

    return is_bst;
}

nd* BST::subtree_minimum(nd* node) {
    if(node != NULL) {
        while(node->left_child != NULL) {
            node = node->left_child;
        }
    }

    return node;
}

nd* BST::subtree_maximum(nd* node) {
    if(node != NULL) {
        while(node->right_child != NULL) {
            node = node->right_child;
        }
    }

    return node;
}

nd* BST::tree_minimum() {
    nd* node_x = this->root;
    if(node_x != NULL) {
        while(node_x->left_child != NULL) {
            node_x = node_x->left_child;
        }
    }

    return node_x;
}

nd* BST::tree_maximum() {
    nd* node_x = this->root;
    if(node_x != NULL) {
        while(node_x->right_child != NULL) {
            node_x = node_x->right_child;
        }
    }

    return node_x;
}

nd* BST::successor(nd* node) {
    if(node->right_child != NULL) {
        return BST::subtree_minimum(node->right_child);
    }
    nd* node_y = node->parent;
    while(node_y != NULL && node == node_y->right_child) {
        node = node_y;
        node_y = node_y->parent;
    }

    return node_y;
}

nd* BST::predecessor(nd* node) {
    if(node->left_child != NULL) {
        return BST::subtree_maximum(node->left_child);
    }
    nd* node_y = node->parent;
    while(node_y != NULL && node == node_y->left_child) {
        node = node_y;
        node_y = node_y->parent;
    }

    return node_y;
}

void BST::insert_node_fcn(int key) {
    if(this->size == 0) {
        /*Case: Insert root node*/
        nd* node_ptr = new nd;
        node_ptr->key = key;
        node_ptr->has_data = false;
        this->root = node_ptr;
        this->size++;
    }
    else {
        /*Case: Insert second and greater nodes*/
        nd* node_ptr = new nd;
        node_ptr->key = key;
        node_ptr->has_data = false;
        nd* node_y = NULL;
        nd* node_x = this->root;
        while(node_x != NULL) {
            /*Case: Node key is unique*/
            if(key != node_x->key) {
                node_y = node_x;
                if(key < node_x->key)
                    node_x = node_x->left_child;
                else
                    node_x = node_x->right_child;
            }
            /*Case: Node key is taken*/
            else {
                throw "Node key taken";
            }
        }
        node_ptr->parent = node_y;
        if(node_ptr->key < node_y->key)
            node_y->left_child = node_ptr;
        else
            node_y->right_child = node_ptr;
        this->size++;
    }
}

void BST::delete_node_fcn(nd* node) {
    /*Case: Root node when size tree is 1*/
    if(node == this->root && this->size == 1) {
        this->root = NULL;
        nullify_node (node);
        delete node;
        this->size--;
    }
    /*Case: Root node when size tree is greater than 1*/
    else if(node == this->root && this->size > 1) {
        nd* node_ptr = BST::successor(node);
        /*Case: Root node has successor*/
        if(node_ptr != NULL) {
            update_links_successor(node_ptr);
        }
        /*Case: Root node has no successor*/
        else {
            node_ptr = BST::predecessor(node);
            update_links_predecessor(node_ptr);
        }
        node_ptr->parent = NULL;
        update_children(node_ptr, node);
        this->root = node_ptr;
        nullify_node(node);
        delete node;
        this->size--;
    }
    /*Case: Node has no children and is not root node*/
    else if(node->left_child == NULL && node->right_child == NULL &&
            node != this->root) {
        /*Case: Node is left child*/
        if(node->key < node->parent->key)
            node->parent->left_child = NULL;
        /*Case: Node is right child*/
        else
            node->parent->right_child = NULL;
        nullify_node(node);
        delete node;
        this->size--;
    }
    /*Case: Node has right child and is not root node*/
    else if(node->left_child == NULL && node->right_child != NULL &&
            node != this->root) {
        /*Case: Node is left child*/
        if(node->key < node->parent->key) {
            node->parent->left_child = node->right_child;
            node->right_child->parent = node->parent;
        }
        /*Case: Node is right child*/
        else {
            node->parent->right_child = node->right_child;
            node->right_child->parent = node->parent;
        }
        nullify_node(node);
        delete node;
        this->size--;
    }
    /*Case: Node has left child and is not root node*/
    else if(node->left_child != NULL && node->right_child == NULL &&
            node != this->root) {
        /*Case: Node is left child*/
        if(node->key < node->parent->key) {
            node->parent->left_child = node->left_child;
            node->left_child->parent = node->parent;
        }
        /*Case: Node is right child*/
        else {
            node->parent->right_child = node->left_child;
            node->left_child->parent = node->parent;
        }
        nullify_node(node);
        delete node;
        this->size--;
    }
    /*Case: Node has left and right child and is not root node*/
    else if(node->left_child != NULL && node->right_child != NULL &&
            node != this->root) {
        /*Case: Node is left child*/
        if(node->key < node->parent->key) {
            nd* node_ptr = BST::successor(node);
            update_links_successor(node_ptr);
            node->parent->left_child = node_ptr;
            node_ptr->parent = node->parent;
            update_children(node_ptr, node);
        }
        /*Case: Node is right child*/
        else {
            nd* node_ptr = BST::successor(node);
            update_links_successor(node_ptr);
            node->parent->right_child = node_ptr;
            node_ptr->parent = node->parent;
            update_children(node_ptr, node);
        }
        nullify_node(node);
        delete node;
        this->size--;
    }
    else {};
}

void BST::make_empty() {
    while(this->root != NULL) {
        BST::delete_node_fcn(this->root);
    }
}
