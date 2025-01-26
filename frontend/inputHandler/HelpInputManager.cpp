//
// Created by koenv on 26/01/2025.
//

#include "HelpInputManager.hpp"

#include <iostream>

namespace frontend {
    HelpInputManager::HelpInputManager(const std::string &inputCommand)
        : BaseInputHandler(inputCommand) {
    }

    void HelpInputManager::Handle(const std::vector<std::string> &arguments) const {
        std::cout
        << "=====================================================================" << std::endl
        << "AVAILABLE ACTIONS:" << std::endl
        << "---------------------------------------------------------------------" << std::endl
        << "move <direction>: walk to the connected room in the given direction" << std::endl
        << "look self: look at yourself" << std::endl
        << "look: look at the room you are in" << std::endl
        << "look <item>: look at the given item" << std::endl
        << "take <item>: take the given item" << std::endl
        << "place <item>: drop the given item" << std::endl
        << "look <enemy>: look at the given enemy" << std::endl
        << "attack <enemy>: attack the given enemy" << std::endl
        << "consume <item>: consume a consumable item" << std::endl
        << "wear <item>: equip a weapon or piece of armor" << std::endl
        << "wait: skip a turn" << std::endl
        << "godmode <on|off>: enter god mode" << std::endl
        << "quit: quit the game" << std::endl
        << "help: show this help message" << std::endl
        << "=====================================================================" << std::endl;

    }
} // frontend