//
// Created by koenv on 26/01/2025.
//

#ifndef WAITINPUTHANDLER_HPP
#define WAITINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class ICommand;

    class WaitInputHandler: public BaseInputHandler {
public:
    WaitInputHandler(const std::string &inputCommand, ICommand &move_enemies_command);

protected:
    void Handle(const std::vector<std::string> &arguments) const override;

private:
    ICommand& move_enemies_command;
};

} // frontend

#endif //WAITINPUTHANDLER_HPP
