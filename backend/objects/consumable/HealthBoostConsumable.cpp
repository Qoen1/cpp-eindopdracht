//
// Created by koenv on 26/01/2025.
//

#include "HealthBoostConsumable.hpp"
#include "../../../frontend/player/Player.hpp"

namespace backend {
    HealthBoostConsumable::HealthBoostConsumable(const helpers::TypoTrap &name,const helpers::TypoTrap &description, int heal_amount)
    : Consumable(name, description), heal_amount_(heal_amount) {
    }

    void HealthBoostConsumable::Consume(frontend::Player &player) {
        player.Heal(heal_amount_);
    }
} // backend
