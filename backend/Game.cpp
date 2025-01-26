//
// Created by koenv on 26/01/2025.
//

#include "Game.hpp"
#include <random>

namespace backend {
    Game::Game(helpers::OwningDynamicDoodad<Location> &&locations): locations(static_cast<helpers::OwningDynamicDoodad<Location>&&>(locations)) {
    }

    Location * Game::GetLocation(size_t index) {
        return &locations.get(index);
    }

    void Game::MoveEnemies() {
        struct EnemyByLocation {
            Enemy* enemy;
            Location* location;
        };
        helpers::DynamicDoodad<EnemyByLocation> moving_enemies_by_location;

        for (auto i = 0; i < locations.size(); ++i) {
            auto enemies = locations.get(i).GetEnemies();

            for (auto j = 0; j < enemies.size(); ++j) {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, 100);
                int result = dis(gen);
                if (result > 50 && enemies.get(j)->GetHealth() > 0) {
                    moving_enemies_by_location.push_back({enemies.get(j), &locations.get(i)});
                }
            }
        }

        for (auto i = 0; i < moving_enemies_by_location.size(); ++i) {
            auto location = moving_enemies_by_location.get(i).location;

            auto possible_directions = location->GetDirections();
            if (possible_directions.size() == 0) {
                continue;
            }
            auto enemy = moving_enemies_by_location.get(i).enemy;

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, static_cast<int>(possible_directions.size()) - 1);
            auto chosen_direction = possible_directions.get(dis(gen));

            location->GetNeighbor(chosen_direction)->AddEnemy(location->PopEnemyByName(enemy->GetName()));
        }
    }
} // backend