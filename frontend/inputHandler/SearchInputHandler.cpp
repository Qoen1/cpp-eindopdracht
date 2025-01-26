//
// Created by koenv on 31/10/2024.
//

#include "SearchInputHandler.hpp"

#include "../commands/SearchLocationCommand.hpp"

namespace frontend {
    SearchInputHandler::SearchInputHandler(const std::string& inputCommand, Player &player, std::shared_ptr<ICommand> command) : BaseInputHandler(inputCommand), player_(player), moveEnemiesCommand_(command) {
    }

    void SearchInputHandler::Handle(const std::vector<std::string> &arguments) const {
        SearchLocationCommand(*player_.currentLocation).Execute();
        moveEnemiesCommand_->Execute();
    }
} // frontend