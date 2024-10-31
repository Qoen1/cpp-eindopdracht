//
// Created by koenv on 05/10/2024.
//

#include "./Weapon.hpp"

namespace backend {
    Weapon::Weapon(helpers::TypoTrap &name, helpers::TypoTrap &description) : name_(&name), description_(&description) {
    }

    const helpers::TypoTrap & Weapon::GetName() const {
        return *name_;
    }

    const helpers::TypoTrap & Weapon::GetDescription() const {
        return *description_;
    }
} // backend