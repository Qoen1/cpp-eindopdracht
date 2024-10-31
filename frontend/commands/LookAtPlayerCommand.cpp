//
// Created by koenv on 31/10/2024.
//

#include "LookAtPlayerCommand.hpp"

#include <iostream>

namespace frontend {
    LookAtPlayerCommand::LookAtPlayerCommand(Player &player) : player_(player) {
    }

    void LookAtPlayerCommand::Execute() {
        const backend::Armor* armor = player_.GetArmor();

        std::cout
        << "Je hebt " << player_.GetHitpoints() << " levenspunten" << std::endl
        << "Je hebt het volgende wapen vast: " << player_.GetWeapon().GetName().cstring() << std::endl
        << "Je draagt de volgende bepansering: " << (armor != nullptr ? armor->GetName().cstring() : "") << std::endl
        << "Je hebt " << player_.GetCoinCount() << " munten" << std::endl
        << "Je hebt de volgende items in je inventaris: ";
        for(int i = 0; i < player_.GetInventory().size(); ++i) {
            std::cout << player_.GetInventory()[i]->GetName().cstring() << ", ";
        }
        std::cout << std::endl;
    }
} // frontend