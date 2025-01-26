//
// Created by fikkie on 28/10/24.
//

#ifndef GODSTATE_HPP
#define GODSTATE_HPP
#include "IPlayerState.hpp"


namespace frontend {
    class Player;
}

class GodState: public IPlayerState {
public:
    explicit GodState(frontend::Player &player);

    void TakeDamage(int damage) override;

    int Attack() override;

private:
    frontend::Player& player_;
};



#endif //GODSTATE_HPP
