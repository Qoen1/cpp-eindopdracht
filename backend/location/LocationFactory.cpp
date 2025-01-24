//
// Created by koenv on 05/10/2024.
//

#include "LocationFactory.hpp"

namespace backend {
    Location* LocationFactory::Create(const helpers::TypoTrap& name, const helpers::TypoTrap& description) {
        return new Location(name, description);
    }
} // backend