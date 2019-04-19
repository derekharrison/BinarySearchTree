/*
 * Data.hpp
 *
 *  Created on: Apr 19, 2019
 *      Author: d-w-h
 */

#ifndef DATA_HPP_
#define DATA_HPP_

#include <string>

class Data {
public:
    double height;
    std::string name;

    Data();
    void set_data(double height, std::string name);
};

#endif /* DATA_HPP_ */
