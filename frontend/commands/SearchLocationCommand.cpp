//
// Created by koenv on 31/10/2024.
//

#include "SearchLocationCommand.hpp"

#include <iostream>

namespace frontend {
    SearchLocationCommand::SearchLocationCommand(backend::Location &location, std::ostream& output) : location_(location), output_(output) {
    }

    void SearchLocationCommand::Execute() {
        auto discovered_items = location_.MakeAllItemsVisible();

        output_ << "Je vindt:" << std::endl;
        for (auto i = 0; i < discovered_items.size(); ++i) {
            output_ << discovered_items[i]->GetName() << std::endl;
        }

    }
}
