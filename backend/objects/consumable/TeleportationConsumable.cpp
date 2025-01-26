//
// Created by koenv on 26/01/2025.
//

#include "TeleportationConsumable.hpp"
#include <random>
#include "../../../frontend/player/Player.hpp"

namespace backend {
    TeleportationConsumable::TeleportationConsumable(const helpers::TypoTrap &name,
                                                     const helpers::TypoTrap &description,
                                                     int teleport_distance): Consumable(name, description),
                                                                             teleport_distance_(teleport_distance) {
    }

    void TeleportationConsumable::Consume(frontend::Player &player) {
        std::random_device rd;
        std::mt19937 gen(rd());

        auto* location = player.currentLocation;

        for (auto i = 0; i < teleport_distance_; ++i) {
            auto possible_directions = location->GetDirections();
            if (possible_directions.size() == 0) {
                break;
            }

            std::uniform_int_distribution dis(0, static_cast<int>(possible_directions.size()) - 1);
            auto chosen_direction = possible_directions.get(dis(gen));

            location = location->GetNeighbor(chosen_direction);
        }

        player.currentLocation = location;
    }
} // backend
