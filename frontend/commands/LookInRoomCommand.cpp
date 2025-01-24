//
// Created by fikkie on 28/10/24.
//

#include "LookInRoomCommand.hpp"

#include <iostream>
#include <ostream>

namespace frontend {
    LookInRoomCommand::LookInRoomCommand(backend::Location &passedLocation) :location(passedLocation){
    }

    void LookInRoomCommand::Execute() {
        const helpers::DynamicDoodad<backend::Item> items = location.GetVisibleItems();
        std::cout << "Je staat bij de locatie " << location.getName().cstring() << std::endl << location.getDescription().cstring() << std::endl;

        std::cout << "zichtbare objecten: ";
        for(int i = 0; i < items.size(); i++) {
            std::cout << items.get(i).GetName().cstring() << ", ";
        }
        std::cout << std::endl;
    }
} // frontend