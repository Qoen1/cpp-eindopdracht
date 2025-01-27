//
// Created by koenv on 05/10/2024.
//

#include "Player.hpp"
#include <memory>
#include <vector>
#include <sys/stat.h>

#include "RegularState.hpp"
#include "../../backend/objects/Gold.hpp"

namespace frontend {
    Player::Player(backend::Location* currentLocation) : currentLocation(currentLocation), inventory_(0), state_(std::make_unique<RegularState>(*this)) {
        hitpoints_ = 100;
        coinCount_ = 0;
        attack_chance_ = 50;
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
                    std::unique_ptr<backend::Weapon> wpn = nullptr;
                    if (weapon_ != nullptr) {
                        wpn = std::move(weapon_);
                    }
                    weapon_ = std::unique_ptr<backend::Weapon>(dynamic_cast<backend::Weapon*>(i->release()));
                    inventory_.erase(i);
                    if (wpn) {
                        inventory_.push_back(std::move(wpn));
                    }
                    return true;
                }
                if (dynamic_cast<backend::Armor*>(i->get())) {
                    std::unique_ptr<backend::Armor> armor = nullptr;
                    if (armor_ != nullptr) {
                        armor = std::move(armor_);
                    }
                    armor_ = std::unique_ptr<backend::Armor>(dynamic_cast<backend::Armor*>(i->release()));
                    inventory_.erase(i);
                    if (armor) {
                        inventory_.push_back(std::move(armor));
                    }
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    void Player::AddItemToInventory(std::unique_ptr<backend::Item>&& item) {
        if (auto gold = dynamic_cast<backend::Gold*>(item.get())) {
            coinCount_ += gold->GetValue();
            return;
        }
        inventory_.push_back(std::move(item));
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

    int Player::Attack() {
        return state_->Attack();
    }

    int Player::GetAttackDamage() {
        if(weapon_ == nullptr) {
            return 0;
        }
        return weapon_->GetAttackDamage();
    }

    void Player::UpdateAttackProbability(int by) {
        attack_chance_ += by;
        if (attack_chance_ > 90) {
            attack_chance_ = 90;
        }
    }

    void Player::Heal(int by) {
        hitpoints_ += by;
        if (hitpoints_ > 100) {
            hitpoints_ = 100;
        }
    }

    void Player::TakeDamage(int by) {
        state_->TakeDamage(by);
    }

    void Player::SetHitpoints(int hitpoints) {
        if (hitpoints > 100 || hitpoints < 0) {
            throw std::invalid_argument("Hitpoints must be between 0 and 100");
        }
        hitpoints_ = hitpoints;
    }

    int Player::GetAttackChance() const {
        return attack_chance_;
    }

    void Player::SetState(std::unique_ptr<IPlayerState> state) {
        state_ = std::move(state);
    }
} // frontend