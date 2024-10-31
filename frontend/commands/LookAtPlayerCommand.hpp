//
// Created by koenv on 31/10/2024.
//

#ifndef LOOKATPLAYERCOMMAND_HPP
#define LOOKATPLAYERCOMMAND_HPP
#include "ICommand.hpp"
#include "../player/Player.hpp"

namespace frontend {

class LookAtPlayerCommand : public ICommand {
public:
    LookAtPlayerCommand(Player &player);
    void Execute() override;
private:
    Player &player_;
};

} // frontend

#endif //LOOKATPLAYERCOMMAND_HPP
