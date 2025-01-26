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
        const helpers::DynamicDoodad<backend::Item*> items = location.GetVisibleItems();
        auto enemies = location.GetEnemies();
        auto directions = location.GetDirections();

        cout << "Je staat bij de locatie " << location.getName() << std::endl << location.getDescription() << std::endl;

        cout << "zichtbare objecten: ";
        if (items.size() == 0) cout << "Geen";
        else {
            for (int i = 0; i < items.size(); i++) {
                cout << items.get(i)->GetName();
                if (i != items.size() - 1) cout << ", ";
            }
        }
        cout << endl;

        if (enemies.size() == 0) cout << "Er zijn geen vijanden in deze kamer." << endl;
        else {
            cout << "Vijanden: ";
            for (int i = 0; i < enemies.size(); i++) {
                cout << enemies.get(i)->GetName();
                if (enemies.get(i)->GetHealth() <= 0) cout << " (dood)";
                if (i != enemies.size() - 1) cout << ", ";
            }
            cout << endl;
        }

        if (directions.size() == 0) cout << "Er zijn geen uitgangen in deze kamer." << endl;
        else {
            cout << "Uitgangen: ";
            for (int i = 0; i < directions.size(); i++) {
                cout << GetStringFromDirection(directions.get(i));
                if (i != directions.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
} // frontend