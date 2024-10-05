//
// Created by koenv on 05/10/2024.
//

#include "Location.hpp"

namespace backend {
    Location::Location(std::string* passedName, std::string* passedDescription)
    :name(helpers::BigBrainPointer<std::string>(passedName)), description(helpers::BigBrainPointer<std::string>(passedDescription)) {
    }

    const std::string & Location::getName() {
        return *name;
    }

    std::string & Location::getDescription() const {
        return *description;
    }
} // backend