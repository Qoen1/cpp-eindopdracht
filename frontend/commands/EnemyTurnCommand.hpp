//
// Created by koenv on 26/01/2025.
//

#ifndef MOVEENEMIESCOMMAND_HPP
#define MOVEENEMIESCOMMAND_HPP
#include "ICommand.hpp"

namespace backend {
    class Game;
}

namespace frontend {
    class Player;

    class EnemyTurnCommand: public ICommand {
public:
    explicit EnemyTurnCommand(backend::Game &game, Player& player);

    void Execute() override;
private:
    backend::Game& game_;
    Player& player_;
};

} // frontend

#endif //MOVEENEMIESCOMMAND_HPP
