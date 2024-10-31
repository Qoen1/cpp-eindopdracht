//
// Created by koenv on 05/10/2024.
//

#include "Armor.hpp"

namespace backend {
    Armor::Armor(helpers::TypoTrap &name, helpers::TypoTrap &description) : name_(&name), description_(&description) {
    }

    const helpers::TypoTrap & Armor::GetName() const {
        return *name_;
    }

    const helpers::TypoTrap & Armor::GetDescription() const {
        return *description_;
    }
} // backend