//
// Created by koenv on 05/10/2024.
//

#include "Gold.hpp"

namespace backend {
    Gold::Gold(const helpers::TypoTrap& name, const helpers::TypoTrap& description, int amount)
        : Item(name, description), amount_(amount) {
    }
} // backend