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
	nd node_1 = {33, 3.14, };
	nd node_2 = {40, 2.14, };
	nd node_3 = {23, 1.14, };
	nd node_4 = {58, 4.14, };
	nd node_5 = {48, 5.14, };
	nd node_6 = {28, 6.14, };
	nd node_7 = {11, 7.14, };
	nd node_8 = {13, 8.14, };
	nd node_9 = {22, 80.14, };
	nd node_10 = {39, 2.72, };
	nd node_11 = {25, 1.72, };
	nd node_12 = {29, 3.72, };
	nd node_13 = {70, 4.72, };
	nd node_14 = {47, 4.72, };
	nd node_15 = {64, 4.72, };
	nd node_16 = {26, 4.72, };
	nd node_17 = {65, 4.72, };
	nd node_18 = {30, 4.72, };
	nd node_19 = {49, 4.72, };
	nd node_20 = {50, 4.72, };
	nd node_21 = {10, 4.72, };
	nd node_22 = {6, 4.72, };
	nd node_23 = {8, 4.72, };
	nd node_24 = {9, 4.72, };
	nd node_25 = {-1, 4.72, };

	try {
		bst.insert_node(node_1);
		bst.insert_node(node_2);
		bst.insert_node(node_3);
		bst.insert_node(node_4);
		bst.insert_node(node_5);
		bst.insert_node(node_6);
		bst.insert_node(node_7);
		bst.insert_node(node_8);
		bst.insert_node(node_9);
		bst.insert_node(node_10);
		bst.insert_node(node_11);
		bst.insert_node(node_12);
		bst.insert_node(node_13);
		bst.insert_node(node_14);
		bst.insert_node(node_15);
		bst.insert_node(node_16);
		bst.insert_node(node_17);
		bst.insert_node(node_18);
		bst.insert_node(node_19);
		bst.insert_node(node_20);
		bst.insert_node(node_21);
		bst.insert_node(node_22);
		bst.insert_node(node_23);
		bst.insert_node(node_24);
		bst.insert_node(node_25);
		bst.print_tree();
	}
	catch(const char* s) {
		std::cout << s << std::endl;
	}

	try	{
		is_bst = bst.verify_bst_invariant();
		std::cout << "is_bst " << is_bst << std::endl;

		std::cout << "deleting node(s)" << std::endl;
		bst.delete_node_wrapper(-1);
		bst.delete_node_wrapper(48);
		bst.print_tree();

		std::cout << "print reverse" << std::endl;
		bst.print_tree_reverse();
	}
	catch(const char* s) {
		std::cout << s << std::endl;
	}

	return 0;
}
