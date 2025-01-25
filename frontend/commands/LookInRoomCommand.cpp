//
// Created by fikkie on 28/10/24.
//

#include "LookInRoomCommand.hpp"

#include <iostream>
#include <ostream>

using namespace std;

namespace frontend {
    LookInRoomCommand::LookInRoomCommand(backend::Location &passedLocation) :location(passedLocation){
    }

    void LookInRoomCommand::Execute() {
        const helpers::DynamicDoodad<backend::Item> items = location.GetVisibleItems();
        auto enemies = location.GetEnemies();
        cout << "Je staat bij de locatie " << location.getName().cstring() << std::endl << location.getDescription().cstring() << std::endl;

        cout << "zichtbare objecten: ";
        if (items.size() == 0) cout << "Geen";
        else {
            for (int i = 0; i < items.size(); i++) {
                cout << items.get(i).GetName().cstring();
                if (i != items.size() - 1) cout << ", ";
            }
        }
        cout << endl;

        if (enemies.size() == 0) cout << "Er zijn geen vijanden in deze kamer." << endl;
        else {
            cout << "Vijanden: ";
            for (int i = 0; i < enemies.size(); i++) {
                auto name = enemies.get(i).GetName();
                cout << name;
                if (i != enemies.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
} // frontend