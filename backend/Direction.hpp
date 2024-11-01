//
// Created by koenv on 01/11/2024.
//

#ifndef DIRECTION_HPP
#define DIRECTION_HPP
#include <stdexcept>

enum Direction : unsigned int {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

static Direction GetDirectionFromString(const std::string& direction) {
    if (direction == "north") return NORTH;
    if (direction == "east") return EAST;
    if (direction == "south") return SOUTH;
    if (direction == "west") return WEST;

    throw std::invalid_argument("Invalid direction");
}

#endif //DIRECTION_HPP