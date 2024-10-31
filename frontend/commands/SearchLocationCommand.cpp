//
// Created by koenv on 31/10/2024.
//

#include "SearchLocationCommand.hpp"

namespace frontend {
    SearchLocationCommand::SearchLocationCommand(backend::Location &location) : location_(location) {
    }

    void SearchLocationCommand::Execute() {
        location_.MakeAllItemsVisible();
    }
}
