//
// Created by koenv on 25/01/2025.
//

#ifndef ATTACKINPUTHANDLER_HPP
#define ATTACKINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class ICommand;
    class Player;

    class AttackInputHandler: public BaseInputHandler {
    public:
        AttackInputHandler(const std::string &inputCommand, Player &player, ICommand &move_enemies_command, std::ostream &output);

    protected:
        void Handle(const std::vector<std::string> &arguments) const override;

    private:
    Player& player_;
    ICommand& move_enemies_command;
    std::ostream &output;
};

} // frontend

#endif //ATTACKINPUTHANDLER_HPP
