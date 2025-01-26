//
// Created by koenv on 26/01/2025.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "../helpers/OwningDynamicDoodad.hpp"
#include "location/Location.hpp"

namespace backend {

class Game {
public:
    Game(helpers::OwningDynamicDoodad<Location>&& locations);
    void MoveEnemies();
    helpers::OwningDynamicDoodad<Location> locations;
};

} // backend

#endif //GAME_HPP
