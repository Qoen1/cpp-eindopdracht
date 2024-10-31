//
// Created by koenv on 05/10/2024.
//

#ifndef SPELER_HPP
#define SPELER_HPP
#include <memory>

#include "../../backend/location/Location.hpp"
#include "../../backend/objects/Armor.hpp"
#include "../../backend/objects/Weapon.hpp"

namespace frontend {

class Player {
private:
    int hitpoints_;
    std::vector<backend::Item*> inventory_;
    std::unique_ptr<backend::Weapon> weapon_;
    std::unique_ptr<backend::Armor> armor_;
    int coinCount_;
public:
    Player(backend::Location* currentLocation);
    backend::Location* currentLocation;

    backend::Item* GetItemByName(const std::string &passedName) const;
    int GetHitpoints() const;
    void UseWeaponFromInventory(const std::string &weaponName);
    void UseArmorFromInventory(const std::string &armorName);
    backend::Weapon& GetWeapon() const;
    backend::Armor* GetArmor() const;
    const std::vector<backend::Item*>& GetInventory() const;
    void AddItemToInventory(backend::Item* item);
    int GetCoinCount();

};

} // frontend

#endif //SPELER_HPP
