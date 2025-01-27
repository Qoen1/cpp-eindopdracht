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
    explicit LookInputHandler(const std::string& inputCommand, Player &player, std::ostream& output)
        : BaseInputHandler(inputCommand), player_(player), output_(output) {
    }

protected:
    void Handle(const std::vector<std::string> &arguments) const override;

private:
    Player &player_;
    std::ostream& output_;
};

} // frontend

#endif //LOOKINPUTHANDLER_HPP
