//
// Created by koenv on 05/10/2024.
//

#include "Player.hpp"
#include <memory>
#include <vector>

namespace frontend {
    Player::Player(backend::Location* currentLocation) : currentLocation(currentLocation), inventory_(0){
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

    std::unique_ptr<backend::Item> Player::PopItemByName(const std::string &passedName) {
        auto it = std::find_if(inventory_.begin(), inventory_.end(), [&](const std::unique_ptr<backend::Item>& item) {
            return item->GetName().cstring() == passedName;
        });
        std::unique_ptr<backend::Item> item = std::move(*it);
        inventory_.erase(it);
        return item;
    }

    int Player::GetHitpoints() const {
        return hitpoints_;
    }

    bool Player::UseItemFromInventory(const std::string &weaponName) {
        for (auto i = inventory_.begin(); i != inventory_.end(); ++i) {
            if ((*i)->GetName().cstring() == weaponName) {
                if (dynamic_cast<backend::Weapon*>(i->get())) {
                    if (weapon_ != nullptr) {
                        inventory_.emplace_back(std::move(weapon_));
                    }
                    weapon_ = std::unique_ptr<backend::Weapon>(static_cast<backend::Weapon*>(i->release()));
                    inventory_.erase(i);
                    return true;
                }
                if (dynamic_cast<backend::Armor*>(i->get())) {
                    if (armor_ != nullptr) {
                        inventory_.emplace_back(std::move(armor_));
                    }
                    armor_ = std::unique_ptr<backend::Armor>(static_cast<backend::Armor*>(i->release()));
                    inventory_.erase(i);
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    void Player::AddItemToInventory(std::unique_ptr<backend::Item>&& item) {
        inventory_.emplace_back(std::move(item));
    }

    backend::Weapon * Player::GetWeapon() const {
        return weapon_.get();
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