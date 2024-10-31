//
// Created by koenv on 30/10/2024.
//

#ifndef BASEINPUTHANDLERBUILDER_HPP
#define BASEINPUTHANDLERBUILDER_HPP
#include <vector>

#include "BaseInputHandler.hpp"
#include "LookInputHandler.hpp"

namespace frontend {

class BaseInputHandlerBuilder {
private:
    std::vector<BaseInputHandler*> handlers;
    Player &player_;
public:
    BaseInputHandlerBuilder &AddLookInputHandler(const std::string &trigger) {
        handlers.push_back(new LookInputHandler(trigger, player_));
        return *this;
    }
};

} // frontend

#endif //BASEINPUTHANDLERBUILDER_HPP
