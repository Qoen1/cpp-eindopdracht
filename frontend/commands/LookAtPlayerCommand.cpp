//
// Created by koenv on 31/10/2024.
//

#include "LookAtPlayerCommand.hpp"

#include <iostream>

namespace frontend {
    LookAtPlayerCommand::LookAtPlayerCommand(Player &player, std::ostream& output) : player_(player), output_(output) {
    }

    void LookAtPlayerCommand::Execute() {
        const backend::Armor* armor = player_.GetArmor();
        const backend::Weapon* weapon = player_.GetWeapon();

        output_
        << "Je hebt " << player_.GetHitpoints() << " levenspunten" << std::endl
        << "Je hebt het volgende wapen vast: " << (weapon != nullptr ? weapon->GetName().cstring() : "Geen") << std::endl
        << "Je draagt de volgende bepansering: " << (armor != nullptr ? armor->GetName().cstring() : "Geen") << std::endl
        << "Je hebt " << player_.GetCoinCount() << " munten" << std::endl
        << "Je hebt de volgende items in je inventaris: ";
        if (player_.GetInventory().empty()) {
            output_ << "Geen";
        }else {
            auto inventory = player_.GetInventory();
            for(int i = 0; i <inventory.size(); ++i) {
                output_ << inventory[i]->GetName().cstring() << ", ";
            }
        }

        output_ << std::endl;
    }
} // frontend