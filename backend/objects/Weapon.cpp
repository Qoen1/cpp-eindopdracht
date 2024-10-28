//
// Created by koenv on 05/10/2024.
//

#include "./Weapon.hpp"

namespace backend {
    helpers::TypoTrap* Weapon::ToString() {
        return new helpers::TypoTrap("super gevaarlijk");
    }
} // backend