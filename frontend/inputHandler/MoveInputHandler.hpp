//
// Created by koenv on 01/11/2024.
//

#ifndef MOVEINPUTHANDLER_HPP
#define MOVEINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"
#include "../player/Player.hpp"

namespace frontend {
    class ICommand;

    class MoveInputHandler : public BaseInputHandler {
public:
    MoveInputHandler(const std::string& command, Player& player, std::shared_ptr<frontend::ICommand> move_enemies_command);
protected:
    void Handle(const std::vector<std::string> &arguments) const override;
private:
    Player& player_;
    std::shared_ptr<frontend::ICommand> move_enemies_command_;
};

} // frontend

#endif //MOVEINPUTHANDLER_HPP
