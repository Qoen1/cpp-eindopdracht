//
// Created by koenv on 05/10/2024.
//

#ifndef CONSUMABLE_HPP
#define CONSUMABLE_HPP
#include "../Item.hpp"

namespace frontend {
    class Player;
}

namespace backend {

class Consumable: public Item {
public:
    Consumable(const helpers::TypoTrap& name, const helpers::TypoTrap& description)
        : Item(name, description) {
    }

    virtual void Consume(frontend::Player& player) = 0;

    ~Consumable() override = default;
};

} // backend

#endif //CONSUMABLE_HPP
