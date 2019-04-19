/*
 * Data.cpp
 *
 *  Created on: Apr 19, 2019
 *      Author: d-w-h
 */

#include "../inc/Data.hpp"

Data::Data() {
    this->height = 0;
    this->name = "";
}

void Data::set_data(double height, std::string name) {
    this->height = height;
    this->name = name;
}
