//
// Created by koenv on 05/10/2024.
//

#ifndef SPELER_HPP
#define SPELER_HPP
#include <memory>

#include "IPlayerState.hpp"
#include "../../backend/location/Location.hpp"
#include "../../backend/objects/Armor.hpp"
#include "../../backend/objects/Weapon.hpp"

namespace frontend {

class Player {
public:
    Player(backend::Location* currentLocation);
    backend::Location* currentLocation;

    std::unique_ptr<backend::Item> PopItemByName(const std::string &passedName);
    [[nodiscard]] backend::Item* GetItemByName(const std::string &passedName) const;
    int GetHitpoints() const;
    bool UseItemFromInventory(const std::string &weaponName);
    [[nodiscard]] backend::Weapon* GetWeapon() const;
    [[nodiscard]] backend::Armor* GetArmor() const;
    [[nodiscard]] std::vector<backend::Item*> GetInventory();
    void AddItemToInventory(std::unique_ptr<backend::Item>&& item);
    int GetCoinCount();
    int Attack();
    int GetAttackDamage();
    void UpdateAttackProbability(int by);
    void Heal(int by);
    void TakeDamage(int by);
    void SetHitpoints(int hitpoints);
    void SetState(std::unique_ptr<IPlayerState> state);
    int GetAttackChance() const;

private:
    int hitpoints_;
    std::vector<std::unique_ptr<backend::Item>> inventory_;
    std::unique_ptr<backend::Weapon> weapon_;
    std::unique_ptr<backend::Armor> armor_;
    int coinCount_;
    int attack_chance_;
    std::unique_ptr<IPlayerState> state_;
};
} // frontend

#endif //SPELER_HPP
