//
// Created by fikkie on 28/10/24.
//

#include "RandomMapGenerator.hpp"

#include "../../backend/location/LocationFactory.hpp"


std::vector<std::unique_ptr<backend::Location>> RandomMapGenerator::Generate() {

    auto locations = std::vector<std::unique_ptr<backend::Location>>();
    locations.push_back(std::unique_ptr<backend::Location>(backend::LocationFactory::Create(new helpers::TypoTrap("'sex dungeon'"), new helpers::TypoTrap("'a red room with a swing in the corner.'"))));
    locations.push_back(std::unique_ptr<backend::Location>(backend::LocationFactory::Create(new helpers::TypoTrap("home office"), new helpers::TypoTrap("'a square room with a desk in the middle which holds a shrine to the machine gods.'"))));
    return locations;
}

