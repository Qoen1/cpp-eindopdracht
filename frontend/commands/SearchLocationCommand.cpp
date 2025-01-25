//
// Created by koenv on 31/10/2024.
//

#include "SearchLocationCommand.hpp"

#include <iostream>

namespace frontend {
    SearchLocationCommand::SearchLocationCommand(backend::Location &location) : location_(location) {
    }

    void SearchLocationCommand::Execute() {
        auto discovered_items = location_.GetHiddenItems();
        location_.MakeAllItemsVisible();

        std::cout << "Je vindt:" << std::endl;
        for (auto i = 0; i < discovered_items.size(); ++i) {
            std::cout << discovered_items.get(i)->GetName() << std::endl;
        }

    }
}
