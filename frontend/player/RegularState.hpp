//
// Created by fikkie on 28/10/24.
//

#ifndef REGULARSTATE_HPP
#define REGULARSTATE_HPP
#include "IPlayerState.hpp"


namespace frontend {
    class Player;
}

class RegularState: public IPlayerState {
public:
    explicit RegularState(frontend::Player &player);

    void TakeDamage(int damage) override;

    int Attack() override;

private:
    frontend::Player& player_;
};



#endif //REGULARSTATE_HPP
