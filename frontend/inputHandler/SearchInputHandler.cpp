//
// Created by koenv on 31/10/2024.
//

#include "SearchInputHandler.hpp"

#include "../commands/SearchLocationCommand.hpp"

namespace frontend {
    SearchInputHandler::SearchInputHandler(const std::string& inputCommand, Player &player) : BaseInputHandler(inputCommand), player_(player) {
    }

    void SearchInputHandler::Handle(const std::vector<std::string> &arguments) const {
        SearchLocationCommand(*player_.currentLocation).Execute();
        //TODO: after searching the enemies take a turn.
    }
} // frontend