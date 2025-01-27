//
// Created by koenv on 26/01/2025.
//

#ifndef MOVEENEMIESCOMMAND_HPP
#define MOVEENEMIESCOMMAND_HPP
#include <ostream>

#include "ICommand.hpp"

namespace backend {
    class Game;
}

namespace frontend {
    class Player;

    class EnemyTurnCommand: public ICommand {
public:
    explicit EnemyTurnCommand(backend::Game &game, Player& player, std::ostream& output);

    ~EnemyTurnCommand() override {
        auto i = 0;
    };

    void Execute() override;
private:
    backend::Game& game_;
    Player& player_;
    std::ostream& output_;
};

} // frontend

#endif //MOVEENEMIESCOMMAND_HPP
