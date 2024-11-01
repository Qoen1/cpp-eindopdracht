//
// Created by koenv on 01/11/2024.
//

#include "MoveCommand.hpp"

#include "../player/Player.hpp"

namespace frontend {
    MoveCommand::MoveCommand(Direction direction, Player& player) : direction_(direction), player_(player) {
    }

    void MoveCommand::Execute() {
        player_.currentLocation = player_.currentLocation->GetNeighbor(direction_);
    }
} // frontend