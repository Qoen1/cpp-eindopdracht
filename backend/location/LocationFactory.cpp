//
// Created by koenv on 05/10/2024.
//

#include "LocationFactory.hpp"

namespace backend {
    Location* LocationFactory::Create(helpers::TypoTrap* name, helpers::TypoTrap* description) {
        return new Location(name, description);
    }
} // backend