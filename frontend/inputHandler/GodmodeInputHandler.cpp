//
// Created by koenv on 26/01/2025.
//

#include "GodmodeInputHandler.hpp"

#include <iostream>
#include "../player/Player.hpp"
#include "../player/GodState.hpp"
#include "../player/RegularState.hpp"

namespace frontend {
    GodmodeInputHandler::GodmodeInputHandler(const std::string &inputCommand, Player &player)
            : BaseInputHandler(inputCommand),
              player_(player) {
    }

    void GodmodeInputHandler::Handle(const std::vector<std::string> &arguments) const {
        if (arguments.size() < 1) {
            std::cout << "Invalid number of arguments" << std::endl;
            return;
        }

        if (arguments[0] == "on") {
            player_.SetState(std::make_unique<GodState>(player_));
            std::cout << "Godmode enabled" << std::endl;
        } else if (arguments[0] == "off") {
            player_.SetState(std::make_unique<RegularState>(player_));
            std::cout << "Godmode disabled" << std::endl;
        } else {
            std::cout << "Invalid argument" << std::endl;
        }
    }
} // frontend