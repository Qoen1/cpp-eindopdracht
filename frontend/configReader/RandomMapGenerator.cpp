//
// Created by fikkie on 28/10/24.
//

#include "RandomMapGenerator.hpp"

#include <random>

#include "../../backend/enemy/EnemyFactory.hpp"
#include "../../backend/location/LocationFactory.hpp"
#include "../../backend/objects/ItemFactory.hpp"


RandomMapGenerator::RandomMapGenerator(std::shared_ptr<frontend::Database> database): database_(database) {
}

std::vector<std::unique_ptr<backend::Location>> RandomMapGenerator::Generate() {
    auto all_locations = database_->GetLocations();
    auto selected_locations = std::vector<std::unique_ptr<backend::Location>>{};
    auto item_options = database_->GetItems();
    auto enemy_options = database_->GetEnemies();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> room_distribution(1, all_locations.size() - 1);

    auto location_amt = room_distribution(gen);

    for (auto i = 0; i < location_amt; ++i) {
        std::uniform_int_distribution<> location_distribution(0, all_locations.size() - 1);
        auto location_index = location_distribution(gen);
        selected_locations.push_back(std::move(all_locations[location_index]));
        all_locations.erase(all_locations.begin() + location_index);
    }

    GenerateConnections(selected_locations);

    std::uniform_int_distribution<> visible_item_amount_distribution(0, 2);
    std::uniform_int_distribution<> hidden_item_amount_distribution(0, 3);
    std::uniform_int_distribution<> item_index_distribution(0, item_options.size() - 1);
    std::uniform_int_distribution<> enemy_amount_distribution(0, 2);
    std::uniform_int_distribution<> enemy_index_distribution(0, enemy_options.size() - 1);
    for (auto it = selected_locations.begin(); it != selected_locations.end(); ++it) {
        auto visible_item_amount = visible_item_amount_distribution(gen);
        auto hidden_item_amount = hidden_item_amount_distribution(gen);
        auto enemy_amount = enemy_amount_distribution(gen);
        for (auto i = 0; i < visible_item_amount; ++i) {
            auto item_index = item_index_distribution(gen);
            (*it)->AddVisibleItem(GenerateItem(item_options[item_index]));
        }
        for (auto i = 0; i < hidden_item_amount; ++i) {
            auto item_index = item_index_distribution(gen);
            (*it)->AddHiddenItem(GenerateItem(item_options[item_index]));
        }
        for (auto i = 0; i < enemy_amount; ++i) {
            auto enemy_index = enemy_index_distribution(gen);
            (*it)->AddEnemy(GenerateEnemy(enemy_options[enemy_index], item_options));
        }
    }

    return selected_locations;
}

void RandomMapGenerator::GenerateConnections(std::vector<std::unique_ptr<backend::Location>>& locations) {
    auto& start = *locations[0];
    start.AddNeighbor(SOUTH, *locations[1]);
    start.AddNeighbor(WEST, *locations[2]);
    start.AddNeighbor(NORTH, *locations[3]);
    start.AddNeighbor(EAST, *locations[4]);

    locations[1]->AddNeighbor(NORTH, *locations[0]);
    locations[2]->AddNeighbor(EAST, *locations[0]);
    locations[3]->AddNeighbor(SOUTH, *locations[0]);
    locations[4]->AddNeighbor(WEST, *locations[0]);
}

helpers::BigBrainPointer<backend::Item> RandomMapGenerator::GenerateItem(backend::ItemTypeDTO dto) {
    backend::ItemFactory factory;
    name_occurences[dto.name]++;
    dto.name += std::to_string(name_occurences[dto.name]);
    return factory.Create(dto);
}

helpers::BigBrainPointer<backend::Enemy> RandomMapGenerator::GenerateEnemy(backend::EnemyTypeDTO dto, std::vector<backend::ItemTypeDTO> item_options) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> damage_distribution(dto.min_damage, dto.max_damage);
    std::uniform_int_distribution<> object_distribution(dto.min_objects, dto.max_objects);
    std::uniform_int_distribution<> random_item_distribution(0, static_cast<int>(item_options.size()) - 1);

    auto amount_of_items = object_distribution(gen);
    auto damage = damage_distribution(gen);

    helpers::OwningDynamicDoodad<backend::Item> items;

    for (auto i = 0; i < amount_of_items; ++i) {
        items.push_back(GenerateItem(item_options[random_item_distribution(gen)]));
    }

    name_occurences[dto.name]++;
    dto.name += std::to_string(name_occurences[dto.name]);
    return backend::EnemyFactory().Create({dto.name.c_str()},
        helpers::TypoTrap{dto.description.c_str()}, dto.health,
        damage, dto.attack_chance, std::move(items));
}

