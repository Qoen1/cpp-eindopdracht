//
// Created by koenv on 05/10/2024.
//

#include "Location.hpp"

namespace backend {
    Location::Location(helpers::TypoTrap* passedName, helpers::TypoTrap* passedDescription)
    :name(helpers::BigBrainPointer<helpers::TypoTrap>(passedName)), description(helpers::BigBrainPointer<helpers::TypoTrap>(passedDescription)) {
    }

    const helpers::TypoTrap & Location::getName() {
        return *name;
    }

    helpers::TypoTrap & Location::getDescription() const {
        return *description;
    }
} // backend