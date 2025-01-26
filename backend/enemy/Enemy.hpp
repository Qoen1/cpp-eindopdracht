//
// Created by koenv on 05/10/2024.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>
#include <vector>

#include "../../helpers/BigBrainPointer.hpp"
#include "../../helpers/DynamicDoodad.hpp"
#include "../../helpers/OwningDynamicDoodad.hpp"
#include "../objects/Item.hpp"

namespace backend {

struct EnemyTypeDTO {
    std::string name;
    std::string description;
    int min_objects;
    int max_objects;
    int health;
    int attack_chance;
    int min_damage;
    int max_damage;
};

class Enemy {
private:
    helpers::OwningDynamicDoodad<Item> items;
    helpers::TypoTrap name;
    helpers::TypoTrap description;
    int health;
    int damage;
    int attack_chance;
public:
    Enemy();
    Enemy(const helpers::TypoTrap& name, const helpers::TypoTrap& description, int health, int damage, int attack_chance);
    void AddItem(helpers::BigBrainPointer<Item>&& item);
    helpers::OwningDynamicDoodad<Item> TransferItems();
    int GetHealth() const;
    const helpers::TypoTrap &GetName() const;
    const helpers::TypoTrap &GetDescription() const;
    void TakeDamage(int amount);
    int Attack();
};

} // backend

#endif //ENEMY_HPP
