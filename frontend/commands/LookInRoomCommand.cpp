//
// Created by fikkie on 28/10/24.
//

#include "LookInRoomCommand.hpp"

#include <iostream>
#include <ostream>


namespace frontend {
    LookInRoomCommand::LookInRoomCommand(backend::Location &passedLocation, std::ostream& output) :location(passedLocation), output_(output) {
    }

    void LookInRoomCommand::Execute() {
        const helpers::DynamicDoodad<backend::Item*> items = location.GetVisibleItems();
        auto enemies = location.GetEnemies();
        auto directions = location.GetDirections();

        output_ << "Je staat bij de locatie " << location.getName() << std::endl << location.getDescription() << std::endl;

        output_ << "zichtbare objecten: ";
        if (items.size() == 0) output_ << "Geen";
        else {
            for (int i = 0; i < items.size(); i++) {
                output_ << items.get(i)->GetName();
                if (i != items.size() - 1) output_ << ", ";
            }
        }
        output_ << std::endl;

        if (enemies.size() == 0) output_ << "Er zijn geen vijanden in deze kamer." << std::endl;
        else {
            output_ << "Vijanden: ";
            for (int i = 0; i < enemies.size(); i++) {
                output_ << enemies.get(i)->GetName();
                if (enemies.get(i)->GetHealth() <= 0) output_ << " (dood)";
                if (i != enemies.size() - 1) output_ << ", ";
            }
            output_ << std::endl;
        }

        if (directions.size() == 0) output_ << "Er zijn geen uitgangen in deze kamer." << std::endl;
        else {
            output_ << "Uitgangen: ";
            for (int i = 0; i < directions.size(); i++) {
                output_ << GetStringFromDirection(directions.get(i));
                if (i != directions.size() - 1) output_ << ", ";
            }
            output_ << std::endl;
        }
    }
} // frontend