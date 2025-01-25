//
// Created by koenv on 05/10/2024.
//

#include "./Weapon.hpp"

namespace backend {
    Weapon::Weapon(const helpers::TypoTrap &name, const helpers::TypoTrap &description, int damage) :Item(name, description), damage_(damage) {
    }

    int Weapon::GetAttackDamage() const {
        return damage_;
    }
} // backend