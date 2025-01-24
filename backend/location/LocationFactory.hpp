//
// Created by koenv on 05/10/2024.
//

#ifndef LOCATIONFACTORY_HPP
#define LOCATIONFACTORY_HPP
#include <memory>

#include "Location.hpp"

namespace backend {

class LocationFactory {
public:
    Location* Create(const helpers::TypoTrap& name, const helpers::TypoTrap& description);
};

} // backend

#endif //LOCATIONFACTORY_HPP
