/*
 * BST_support.hpp
 *
 *  Created on: Apr 18, 2019
 *      Author: d-w-h
 */

#ifndef BST_SUPPORT_HPP_
#define BST_SUPPORT_HPP_

#include "../inc/BST.hpp"

void update_links_successor(nd* node_ptr);
void update_links_predecessor(nd* node_ptr);
void update_children(nd* node_ptr, nd* node);
void nullify_node (nd* node);

#endif /* BST_SUPPORT_HPP_ */
