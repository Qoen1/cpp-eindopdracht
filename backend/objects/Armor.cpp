//
// Created by koenv on 05/10/2024.
//

#include "Armor.hpp"

namespace backend {
    Armor::Armor(const helpers::TypoTrap &name, const helpers::TypoTrap &description, int defense)
    : Item(name, description), defense_(defense) {
    }

    int Armor::GetDefense() const {
        return defense_;
    }
} // backend