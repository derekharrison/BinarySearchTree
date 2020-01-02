/*
 * main.cpp
 *
 *  Created on: Apr 15, 2019
 *      Author: d-w-h
 *
 *      Implementation of binary search tree with unique keys
 */

#include <iostream>
#include <cstdlib>
#include "../inc/BST.hpp"

int main(int argc, char* argv[]) {
    BST bst;
    Data data;
    Data data_2;
    bool is_bst = false;

    bst.insert_node(33);
    bst.insert_node(40);
    bst.insert_node(23);
    bst.insert_node(58);
    bst.insert_node(48);
    bst.insert_node(28);
    bst.insert_node(11);
    bst.insert_node(13);
    bst.insert_node(22);
    bst.insert_node(39);
    bst.insert_node(25);
    bst.insert_node(30);
    bst.insert_node(29);
    bst.insert_node(70);
    bst.insert_node(47);
    bst.insert_node(64);
    bst.insert_node(26);
    bst.insert_node(65);
    bst.insert_node(31);
    bst.insert_node(49);
    bst.insert_node(50);
    bst.insert_node(10);
    bst.insert_node(6);
    bst.insert_node(8);
    bst.insert_node(9);
    bst.insert_node(-1);
    bst.print_tree();

    std::cout << "verifying bst invariant" << std::endl;
    is_bst = bst.verify_bst_invariant();
    std::cout << "is_bst " << is_bst << std::endl;

    std::cout << "setting and printing data" << std::endl;
    data.set_data(1.78, "George");
    bst.set_data_node(10, data);
    bst.print_data_node(10);

    std::cout << "deleting node(s)" << std::endl;
    bst.delete_node(33);
    bst.delete_node(39);
    bst.delete_node(40);
    bst.delete_node(47);
    bst.delete_node(-1);
    bst.delete_node(49);
    bst.delete_node(50);
    bst.delete_node(58);
    bst.delete_node(64);
    bst.delete_node(65);
    bst.delete_node(70);
    bst.delete_node(48);
    bst.delete_node(31);
    bst.delete_node(28);
    bst.print_tree();

    data_2.set_data(1.79, "Derek");
    bst.set_data_node(23, data_2);
    bst.print_data_node(23);

    std::cout << "verifying bst invariant" << std::endl;
    is_bst = bst.verify_bst_invariant();
    std::cout << "is_bst " << is_bst << std::endl;

    std::cout << "make empty" << std::endl;
    bst.make_empty();
    bst.print_tree();

    return 0;
}
