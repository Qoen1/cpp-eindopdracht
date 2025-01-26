//
// Created by koenv on 26/01/2025.
//

#include "ExperienceBoostConsumable.hpp"

#include "../../../frontend/player/Player.hpp"

namespace backend {
    ExperienceBoostConsumable::ExperienceBoostConsumable(const helpers::TypoTrap &name,
        const helpers::TypoTrap &description, int boost_amount): Consumable(name, description), experienceBoost(boost_amount) {
    }

    void ExperienceBoostConsumable::Consume(frontend::Player &player) {
        player.UpdateAttackProbability(experienceBoost);
    }
} // backend