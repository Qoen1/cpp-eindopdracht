//
// Created by koenv on 30/10/2024.
//

#ifndef LOOKINPUTHANDLER_HPP
#define LOOKINPUTHANDLER_HPP
#include <algorithm>

#include "BaseInputHandler.hpp"
#include "../player/Player.hpp"

namespace frontend {

class LookInputHandler : public BaseInputHandler {
public:
    explicit LookInputHandler(const std::string& inputCommand, Player &player)
        : BaseInputHandler(inputCommand), player_(player) {
    }

protected:
    void Handle(const std::vector<std::string> &arguments) const override;

private:
    Player &player_;
};

} // frontend

#endif //LOOKINPUTHANDLER_HPP
