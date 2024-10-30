//
// Created by koenv on 05/10/2024.
//

#ifndef SPELER_HPP
#define SPELER_HPP
#include "../../backend/location/Location.hpp"

namespace frontend {

class Player {
public:
    backend::Location& currentLocation;

    backend::Item* GetItemByName(const std::string &passedName) const;

};

} // frontend

#endif //SPELER_HPP
