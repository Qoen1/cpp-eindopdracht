//
// Created by koenv on 31/10/2024.
//

#include "SearchInputHandler.hpp"

#include "../commands/SearchLocationCommand.hpp"

namespace frontend {
    SearchInputHandler::SearchInputHandler(const std::string &inputCommand, Player &player,
                                           ICommand &command, std::ostream& output) : BaseInputHandler(inputCommand),
        player_(player), moveEnemiesCommand_(command), output_(output) {
    }

    void SearchInputHandler::Handle(const std::vector<std::string> &arguments) const {
        SearchLocationCommand(*player_.currentLocation, output_).Execute();
        moveEnemiesCommand_.Execute();
    }
} // frontend