//
// Created by fikkie on 28/10/24.
//

#include "FileMapGenerator.hpp"

#include <iostream>
#include <map>
#include <random>
#include <sstream>

#include "../../backend/enemy/EnemyFactory.hpp"
#include "../../backend/location/LocationFactory.hpp"
#include "../../backend/objects/ItemFactory.hpp"
#include "../../external/pugixml.hpp"
#include "../database/Database.hpp"

FileMapGenerator::FileMapGenerator(const std::string& fileName, std::shared_ptr<frontend::Database> database): fileName(fileName), database(database) {}

std::vector<std::unique_ptr<backend::Location>> FileMapGenerator::Generate() {
    struct LocationDTO {
        std::string name;
        std::string description;
        int id;
        int north_id;
        int east_id;
        int south_id;
        int west_id;
        std::vector<backend::EnemyTypeDTO> enemies;
        std::vector<std::pair<backend::ItemTypeDTO, bool>> objects;
    };
    std::vector<LocationDTO> location_dtos;
    std::map<int, std::unique_ptr<backend::Location>> locations;

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("kasteelruine.xml");

    if (!result) throw std::runtime_error("Failed to load file");

    auto root = doc.child("locaties");
    auto location_nodes = root.children();
    for (auto location : location_nodes) {
        LocationDTO dto;

        dto.description = location.child("beschrijving").text().as_string();
        dto.name = location.text().as_string();

        dto.id = location.attribute("id").as_int();
        dto.north_id = location.attribute("noord").as_int();
        dto.east_id = location.attribute("oost").as_int();
        dto.south_id = location.attribute("zuid").as_int();
        dto.west_id = location.attribute("west").as_int();

        auto visible_objects_string = std::string(location.attribute("objectenzichtbaar").as_string());
        auto hidden_objects_string = std::string(location.attribute("objectenverborgen").as_string());
        auto enemies_string = std::string(location.attribute("vijand").as_string());

        auto visible_object_names = split(visible_objects_string, ';');
        auto hidden_object_names = split(hidden_objects_string, ';');
        auto enemy_names = split(enemies_string, ';');

        for (const auto& hidden_object_name: hidden_object_names) {
            dto.objects.push_back({database->GetItem(hidden_object_name), false});
        }
        for (const auto& visible_object_name: visible_object_names) {
            dto.objects.push_back({database->GetItem(visible_object_name), false});
        }
        for (const auto& enemy_name: enemy_names) {
            dto.enemies.push_back(database->GetEnemy(enemy_name));
        }
        location_dtos.push_back(dto);
    }

    backend::LocationFactory location_factory;

    auto possible_items_vector = database->GetItems();
    helpers::DynamicDoodad<backend::ItemTypeDTO> possible_items {};
    for (const auto& dto: possible_items_vector) {
        possible_items.push_back(dto);
    }

    for (const auto& dto: location_dtos) {
        auto location = std::unique_ptr<backend::Location>(location_factory.Create(helpers::TypoTrap{dto.name.c_str()}, helpers::TypoTrap{dto.description.c_str()}));

        for (auto& object: dto.objects) {
            auto item = create_item(object.first);
            if (object.second) {
                location->AddVisibleItem(std::move(item));
            } else {
                location->AddHiddenItem(std::move(item));
            }
        }

        for (auto& enemy: dto.enemies) {
            location->AddEnemy(create_enemy(enemy, possible_items));
        }

        locations[dto.id] = std::move(location);
    }

    for (auto dto: location_dtos) {
        if(dto.north_id != 0) locations[dto.id]->AddNeighbor(NORTH, *locations[dto.north_id]);
        if(dto.east_id != 0)  locations[dto.id]->AddNeighbor(EAST, *locations[dto.east_id]);
        if(dto.south_id != 0) locations[dto.id]->AddNeighbor(SOUTH, *locations[dto.south_id]);
        if(dto.west_id != 0)  locations[dto.id]->AddNeighbor(WEST, *locations[dto.west_id]);
    }

    std::vector<std::unique_ptr<backend::Location>> location_list;
    for (auto i = locations.begin(); i != locations.end(); ++i) {
        location_list.push_back(std::move(i->second));
    }
    return location_list;
}

std::vector<std::string> FileMapGenerator::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

helpers::BigBrainPointer<backend::Enemy> FileMapGenerator::create_enemy(backend::EnemyTypeDTO dto,
    helpers::DynamicDoodad<backend::ItemTypeDTO> &possible_items) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> damage_distribution(dto.min_damage, dto.max_damage);
    std::uniform_int_distribution<> object_distribution(dto.min_objects, dto.max_objects);
    std::uniform_int_distribution<> random_item_distribution(0, static_cast<int>(possible_items.size()) - 1);

    auto amount_of_items = object_distribution(gen);
    auto damage = damage_distribution(gen);

    helpers::OwningDynamicDoodad<backend::Item> items;

    for (auto i = 0; i < amount_of_items; ++i) {
        items.push_back(create_item(possible_items.get(random_item_distribution(gen))));
    }

    name_occurences[dto.name]++;
    dto.name += std::to_string(name_occurences[dto.name]);
    return backend::EnemyFactory().Create({dto.name.c_str()},
        helpers::TypoTrap{dto.description.c_str()}, dto.health,
        damage, dto.attack_chance, std::move(items));
}

helpers::BigBrainPointer<backend::Item> FileMapGenerator::create_item(backend::ItemTypeDTO dto) {
    backend::ItemFactory factory;
    name_occurences[dto.name]++;
    dto.name += std::to_string(name_occurences[dto.name]);
    return factory.Create(dto);
}
