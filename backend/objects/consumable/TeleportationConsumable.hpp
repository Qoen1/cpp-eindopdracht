//
// Created by koenv on 26/01/2025.
//

#ifndef TELEPORTATIONCONSUMABLE_HPP
#define TELEPORTATIONCONSUMABLE_HPP
#include "Consumable.hpp"

namespace backend {

class TeleportationConsumable: public Consumable {
public:
    TeleportationConsumable(const helpers::TypoTrap &name, const helpers::TypoTrap &description, int teleport_distance);

    void Consume(frontend::Player &player) override;

private:
    int teleport_distance_;

};

} // backend

#endif //TELEPORTATIONCONSUMABLE_HPP
