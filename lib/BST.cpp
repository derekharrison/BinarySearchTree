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

Tree::Tree() {
    this->root = NULL;
    this->size = 0;
}

void Tree::insert_node(nd node) {
    if(this->size == 0) {
        /*Case: Insert root node*/
        nd* node_ptr = new nd;
        node_ptr->key = node.key;
        node_ptr->data = node.data;
        this->root = node_ptr;
        this->size++;
    }
    else {
        /*Case: Insert second and greater nodes*/
        nd* node_ptr = new nd;
        node_ptr->key = node.key;
        node_ptr->data = node.data;
        nd* node_y = NULL;
        nd* node_x = this->root;
        while(node_x != NULL) {
            if(node.key != node_x->key) {
                node_y = node_x;
                if(node.key < node_x->key)
                    node_x = node_x->left_child;
                else
                    node_x = node_x->right_child;
            }
            else {
                throw "node key taken";
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

void Tree::delete_node(nd* node) {
    /*Case: Root node when size tree is 1*/
    if(node == this->root && this->size == 1) {
        nullify_node (node);
        this->root = NULL;
        delete node;
        this->size--;
    }
    /*Case: Root node when size tree is greater than 1*/
    else if(node == this->root && this->size > 1) {
        nd* node_ptr = Tree::successor(node);
        if(node_ptr != NULL) {
            update_linkage(node_ptr);
        }
        else {
            node_ptr = Tree::predecessor(node);
            update_linkage(node_ptr);
        };
        node_ptr->parent = NULL;
        update_children(node_ptr, node);
        nullify_node(node);
        this->root = node_ptr;
        delete node;
        this->size--;
    }
    /*Case: Node has no children*/
    else if(node->left_child == NULL && node->right_child == NULL &&
            node != this->root) {
        if(node->key < node->parent->key)
            node->parent->left_child = NULL;
        else
            node->parent->right_child = NULL;
        nullify_node(node);
        delete node;
        this->size--;
    }
    /*Case: Node has right child*/
    else if(node->left_child == NULL && node->right_child != NULL &&
            node != this->root) {
        if(node->key < node->parent->key) {
            node->parent->left_child = node->right_child;
            node->right_child->parent = node->parent;
        }
        else {
            node->parent->right_child = node->right_child;
            node->right_child->parent = node->parent;
        }
        nullify_node(node);
        delete node;
        this->size--;
    }
    /*Case: Node has left child*/
    else if(node->left_child != NULL && node->right_child == NULL &&
            node != this->root) {
        if(node->key < node->parent->key) {
            node->parent->left_child = node->left_child;
            node->left_child->parent = node->parent;
        }
        else {
            node->parent->right_child = node->left_child;
            node->left_child->parent = node->parent;
        }
        nullify_node(node);
        delete node;
        this->size--;
    }
    /*Case: Node has left and right child*/
    else if(node->left_child != NULL && node->right_child != NULL &&
            node != this->root) {
        if(node->key < node->parent->key) {
            nd* node_ptr = Tree::successor(node);
            update_linkage(node_ptr);
            node->parent->left_child = node_ptr;
            node_ptr->parent = node->parent;
            update_children(node_ptr, node);
        }
        else {
            nd* node_ptr = Tree::successor(node);
            update_linkage(node_ptr);
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

void Tree::delete_node_wrapper(int key) {
    try {
        nd* node_ptr = Tree::search_node(key);
        Tree::delete_node(node_ptr);
    }
    catch (const char * s) {
        std::cout << "unable to delete node: "
                  << s << std::endl;
    }
}

nd* Tree::search_node(int key) {
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
            throw "invalid key";
    }
    if(key_found == false)
        throw "node not found";

    return node_x;
}

nd* Tree::subtree_minimum(nd* node) {
    if(node != NULL) {
        while(node->left_child != NULL) {
            node = node->left_child;
        }
    }

    return node;
}

nd* Tree::subtree_maximum(nd* node) {
    if(node != NULL) {
        while(node->right_child != NULL) {
            node = node->right_child;
        }
    }

    return node;
}

nd* Tree::tree_minimum() {
    nd* node_x = this->root;
    if(node_x != NULL) {
        while(node_x->left_child != NULL) {
            node_x = node_x->left_child;
        }
    }

    return node_x;
}

nd* Tree::tree_maximum() {
    nd* node_x = this->root;
    if(node_x != NULL) {
        while(node_x->right_child != NULL) {
            node_x = node_x->right_child;
        }
    }

    return node_x;
}

nd* Tree::successor(nd* node) {
    if(node->right_child != NULL) {
        return Tree::subtree_minimum(node->right_child);
    }
    nd* node_y = node->parent;
    while(node_y != NULL && node == node_y->right_child) {
        node = node_y;
        node_y = node_y->parent;
    }

    return node_y;
}

nd* Tree::predecessor(nd* node) {
    if(node->left_child != NULL) {
        return Tree::subtree_maximum(node->left_child);
    }
    nd* node_y = node->parent;
    while(node_y != NULL && node == node_y->left_child) {
        node = node_y;
        node_y = node_y->parent;
    }

    return node_y;
}

void Tree::print_tree() {
    nd* node_x = Tree::tree_minimum();
    while(node_x != NULL) {
        std::cout << "key " << node_x->key <<
                ",data " << node_x->data;
        if(node_x->left_child != NULL)
            std::cout << ", left_key " << node_x->left_child->key;
        if(node_x->right_child != NULL)
            std::cout << ", right_key " << node_x->right_child->key;
        if(node_x->parent != NULL)
            std::cout << ", parent_key " << node_x->parent->key;
        node_x = Tree::successor(node_x);
        if(node_x != NULL)
            std::cout << ", successor " << node_x->key;
        std::cout << std::endl;
    }

    std::cout << "size tree " << this->size << std::endl;
}

void Tree::print_tree_reverse() {
    nd* node_x = Tree::tree_maximum();
    while(node_x != NULL) {
        std::cout << "key " << node_x->key <<
                ",data " << node_x->data << std::endl;
        node_x = Tree::predecessor(node_x);
    }
}

bool Tree::verify_bst_invariant() {
    bool is_bst = true;
    nd* node_x = Tree::tree_minimum();
    while(node_x != NULL) {
        if(node_x->left_child != NULL &&
                node_x->left_child->key > node_x->key) {
            is_bst = false;
        }
        if(node_x->right_child != NULL &&
                node_x->right_child->key < node_x->key) {
            is_bst = false;
        }
        node_x = Tree::successor(node_x);
    }

    return is_bst;
}
