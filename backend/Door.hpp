//
// Created by koenv on 01/11/2024.
//

#ifndef DOOR_HPP
#define DOOR_HPP
#include "Direction.hpp"


namespace backend {
    class Location;

    class Door {
public:
    Door(Location& location, Direction direction);
    Location& location_;
    Direction direction_;


};

} // backend

#endif //DOOR_HPP
