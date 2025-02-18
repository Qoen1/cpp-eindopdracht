//
// Created by koenv on 05/10/2024.
//

#include "ItemFactory.hpp"

#include <memory>
#include <random>
#include "Armor.hpp"
#include "consumable/Consumable.hpp"
#include "Gold.hpp"
#include "Weapon.hpp"
#include "consumable/ExperienceBoostConsumable.hpp"
#include "consumable/HealthBoostConsumable.hpp"
#include "consumable/TeleportationConsumable.hpp"

namespace backend {
    helpers::BigBrainPointer<Item> ItemFactory::Create(const helpers::TypoTrap& type, const helpers::TypoTrap& name,
        const helpers::TypoTrap& description, int value) {
        if (strcmp(type.cstring(), "teleportatiedrank") == 0) return {new TeleportationConsumable(name, description, value)};
        if (strcmp(type.cstring(), "ervaringsdrank") == 0)    return {new ExperienceBoostConsumable(name, description, value)};
        if (strcmp(type.cstring(), "levenselixer") == 0)      return {new HealthBoostConsumable(name, description, value)};
        if (strcmp(type.cstring(), "wapenrusting") == 0)      return {new Armor(name, description, value)};
        if (strcmp(type.cstring(), "wapen") == 0)             return {new Weapon(name, description, value)};
        if (strcmp(type.cstring(), "goudstukken") == 0)       return {new Gold(name, description, value)};
        throw std::runtime_error("invalid item type");
    }

    helpers::BigBrainPointer<Item> ItemFactory::Create(const ItemTypeDTO& dto) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> value_distribution(dto.minimum_value, dto.maximum_value);

        auto value = value_distribution(gen);

        if (strcmp(dto.type.c_str(), "teleportatiedrank") == 0) return {new TeleportationConsumable(helpers::TypoTrap(dto.name.c_str()), helpers::TypoTrap(dto.description.c_str()), value)};
        if (strcmp(dto.type.c_str(), "ervaringsdrank") == 0)    return {new ExperienceBoostConsumable(helpers::TypoTrap(dto.name.c_str()), helpers::TypoTrap(dto.description.c_str()), value)};
        if (strcmp(dto.type.c_str(), "levenselixer") == 0)      return {new HealthBoostConsumable(helpers::TypoTrap(dto.name.c_str()), helpers::TypoTrap(dto.description.c_str()), value)};
        if (strcmp(dto.type.c_str(), "wapenrusting") == 0)      return {new Armor(helpers::TypoTrap(dto.name.c_str()), helpers::TypoTrap(dto.description.c_str()), dto.protection)};
        if (strcmp(dto.type.c_str(), "wapen") == 0)             return {new Weapon(helpers::TypoTrap(dto.name.c_str()), helpers::TypoTrap(dto.description.c_str()), value)};
        if (strcmp(dto.type.c_str(), "goudstukken") == 0)       return {new Gold(helpers::TypoTrap(dto.name.c_str()), helpers::TypoTrap(dto.description.c_str()), value)};
        throw std::runtime_error("invalid item type");
    }
} // backend