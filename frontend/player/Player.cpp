//
// Created by koenv on 05/10/2024.
//

#include "Player.hpp"

namespace frontend {
    Player::Player(backend::Location* currentLocation) : currentLocation(currentLocation){
        hitpoints_ = 100;
        coinCount_ = 0;
    }

    backend::Item * Player::GetItemByName(const std::string &passedName) const {
        for (auto i = inventory_.begin(); i != inventory_.end(); ++i) {
            if((*i)->GetName().cstring() == passedName) {
                return i->get();
            }
        }
        return nullptr;
    }

    int Player::GetHitpoints() const {
        return hitpoints_;
    }

    void Player::UseWeaponFromInventory(const std::string &weaponName) {
        throw std::runtime_error("Not implemented");
        // for (auto i = inventory_.begin(); i != inventory_.end(); ++i) {
        //     if ((*i)->GetName().cstring() == weaponName) {
        //         weapon_ = std::unique_ptr<backend::Weapon>(dynamic_cast<backend::Weapon*>(*i));
        //         inventory_.erase(i);
        //         return;
        //     }
        // }
    }

    void Player::UseArmorFromInventory(const std::string &armorName) {
        throw std::runtime_error("Not implemented");
        // for (auto i = inventory_.begin(); i != inventory_.end(); ++i) {
        //     if ((*i)->GetName().cstring() == armorName) {
        //         armor_ = std::unique_ptr<backend::Armor>(dynamic_cast<backend::Armor*>(*i));
        //         inventory_.erase(i);
        //         return;
        //     }
        // }
    }

    void Player::AddItemToInventory(std::unique_ptr<backend::Item>&& item) {
        inventory_.emplace_back(std::move(item));
    }

    backend::Weapon & Player::GetWeapon() const {
        return *weapon_;
    }

    backend::Armor * Player::GetArmor() const {
        return armor_.get();
    }

    std::vector<backend::Item*> Player::GetInventory() {
        auto items = std::vector<backend::Item*>();
        for (auto i = inventory_.begin(); i != inventory_.end(); ++i) {
            items.push_back(i->get());
        }
        return items;
    }

    int Player::GetCoinCount() {
        return coinCount_;
    }
} // frontend