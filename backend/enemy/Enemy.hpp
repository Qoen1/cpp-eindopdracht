//
// Created by koenv on 05/10/2024.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>
#include <vector>

#include "../objects/Item.hpp"

namespace backend {

class Enemy {
private:
    std::vector<Item*> items;
public:
    std::string name;
    std::string description;

    std::vector<Item*> &GetItems();
    int GetHealth() const;
};

} // backend

#endif //ENEMY_HPP
