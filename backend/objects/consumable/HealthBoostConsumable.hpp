//
// Created by koenv on 26/01/2025.
//

#ifndef HEALTHBOOSTCONSUMABLE_HPP
#define HEALTHBOOSTCONSUMABLE_HPP
#include "Consumable.hpp"

namespace backend {

class HealthBoostConsumable: public Consumable {
public:
    HealthBoostConsumable(const helpers::TypoTrap &name, const helpers::TypoTrap &description, int heal_amount);

    void Consume(frontend::Player &player) override;
private:
    int heal_amount_;
};

} // backend

#endif //HEALTHBOOSTCONSUMABLE_HPP
