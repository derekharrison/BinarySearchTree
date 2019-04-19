/*
 * main.cpp
 *
 *  Created on: Apr 15, 2019
 *      Author: d-w-h
 *
 *      Implementation of binary search tree
 */

#include <iostream>
#include <cstdlib>
#include "../inc/BST.hpp"

int main(int argc, char* argv[]) {
    Tree bst;
    bool is_bst = false;

    bst.insert_node_wrapper(33);
    bst.insert_node_wrapper(40);
    bst.insert_node_wrapper(23);
    bst.insert_node_wrapper(58);
    bst.insert_node_wrapper(48);
    bst.insert_node_wrapper(28);
    bst.insert_node_wrapper(11);
    bst.insert_node_wrapper(13);
    bst.insert_node_wrapper(22);
    bst.insert_node_wrapper(39);
    bst.insert_node_wrapper(25);
    bst.insert_node_wrapper(29);
    bst.insert_node_wrapper(70);
    bst.insert_node_wrapper(47);
    bst.insert_node_wrapper(64);
    bst.insert_node_wrapper(26);
    bst.insert_node_wrapper(65);
    bst.insert_node_wrapper(31);
    bst.insert_node_wrapper(49);
    bst.insert_node_wrapper(50);
    bst.insert_node_wrapper(10);
    bst.insert_node_wrapper(6);
    bst.insert_node_wrapper(8);
    bst.insert_node_wrapper(9);
    bst.insert_node_wrapper(-1);
    bst.insert_node_wrapper(30);
    bst.print_tree();

    is_bst = bst.verify_bst_invariant();
    std::cout << "is_bst " << is_bst << std::endl;

    std::cout << "deleting node(s)" << std::endl;
    bst.delete_node_wrapper(33);
    bst.delete_node_wrapper(48);
    bst.delete_node_wrapper(23);
    bst.print_tree();

    std::cout << "print reverse" << std::endl;
    bst.print_tree_reverse();

    return 0;
}
