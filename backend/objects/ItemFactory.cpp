//
// Created by koenv on 05/10/2024.
//

#include "ItemFactory.hpp"

#include <memory>

#include "Armor.hpp"
#include "Consumable.hpp"
#include "Gold.hpp"
#include "Weapon.hpp"

namespace backend {
    helpers::BigBrainPointer<Item> ItemFactory::Create(const helpers::TypoTrap& type, const helpers::TypoTrap& name,
        const helpers::TypoTrap& description, int value) {
        if (strcmp(type.cstring(), "teleportatiedrank") == 0) return {new Consumable(name, description)};
        if (strcmp(type.cstring(), "ervaringsdrank") == 0)    return {new Consumable(name, description)};
        if (strcmp(type.cstring(), "levenselixer") == 0)      return {new Consumable(name, description)};
        if (strcmp(type.cstring(), "wapenrusting") == 0)      return {new Armor(name, description)};
        if (strcmp(type.cstring(), "wapen") == 0)             return {new Weapon(name, description)};
        if (strcmp(type.cstring(), "gold") == 0)              return {new Gold(name, description, value)};

    }
} // backend