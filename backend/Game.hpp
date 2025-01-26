//
// Created by koenv on 26/01/2025.
//

#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>

#include "../helpers/OwningDynamicDoodad.hpp"
#include "location/Location.hpp"

namespace backend {

class Game {
public:
    Game(helpers::OwningDynamicDoodad<Location>&& locations);
    Location* GetLocation(size_t index);
    void MoveEnemies();
private:
    helpers::OwningDynamicDoodad<Location> locations;
};

} // backend

#endif //GAME_HPP
