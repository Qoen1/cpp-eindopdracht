//
// Created by koenv on 01/11/2024.
//

#ifndef MOVECOMMAND_HPP
#define MOVECOMMAND_HPP
#include "ICommand.hpp"
#include "../../backend/Direction.hpp"
#include "../player/Player.hpp"

namespace frontend {

class MoveCommand : public ICommand {
public:
    MoveCommand(Direction direction, Player& player);
    void Execute() override;
private:
    Direction direction_;
    Player& player_;
};

} // frontend

#endif //MOVECOMMAND_HPP
