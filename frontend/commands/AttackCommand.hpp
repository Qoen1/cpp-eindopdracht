//
// Created by koenv on 25/01/2025.
//

#ifndef ATTACKCOMMAND_HPP
#define ATTACKCOMMAND_HPP
#include "ICommand.hpp"

namespace backend {
    class Enemy;
}

namespace frontend {
class Player;

class AttackCommand: ICommand {

public:
    AttackCommand(Player& actor, backend::Enemy& victim);

    void Execute() override;

private:
    Player& player_;
    backend::Enemy& enemy_;
};

} // frontend

#endif //ATTACKCOMMAND_HPP
