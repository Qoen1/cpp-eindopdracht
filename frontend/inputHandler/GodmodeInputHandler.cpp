//
// Created by koenv on 26/01/2025.
//

#include "GodmodeInputHandler.hpp"

#include <iostream>
#include "../player/Player.hpp"
#include "../player/GodState.hpp"
#include "../player/RegularState.hpp"

namespace frontend {
    GodmodeInputHandler::GodmodeInputHandler(const std::string &inputCommand, Player &player, std::ostream &output)
            : BaseInputHandler(inputCommand),
              player_(player), output(output) {
    }

    void GodmodeInputHandler::Handle(const std::vector<std::string> &arguments) const {
        if (arguments.size() < 1) {
            output << "Invalid number of arguments" << std::endl;
            return;
        }

        if (arguments[0] == "on") {
            player_.SetState(std::make_unique<GodState>(player_));
            output << "Godmode enabled" << std::endl;
        } else if (arguments[0] == "off") {
            player_.SetState(std::make_unique<RegularState>(player_));
            output << "Godmode disabled" << std::endl;
        } else {
            output << "Invalid argument" << std::endl;
        }
    }
} // frontend