//
// Created by koenv on 31/10/2024.
//

#ifndef LOOKATENEMYCOMMAND_HPP
#define LOOKATENEMYCOMMAND_HPP
#include "ICommand.hpp"
#include "../../backend/enemy/Enemy.hpp"
#include "../player/Player.hpp"

namespace frontend {

class LookAtEnemyCommand : public ICommand {
public:
    LookAtEnemyCommand(backend::Enemy& enemy, Player& player, std::ostream& output);
    void Execute() override;
private:
    backend::Enemy& enemy_;
    Player& player_;
    std::ostream& output_;
};

} // frontend

#endif //LOOKATENEMYCOMMAND_HPP
