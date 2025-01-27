//
// Created by koenv on 24/01/2025.
//

#ifndef TAKEINPUTHANDLER_HPP
#define TAKEINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class Player;

    class TakeInputHandler: public BaseInputHandler {
public:
    explicit TakeInputHandler(const std::string &inputCommand, Player &player, std::ostream &output)
        : BaseInputHandler(inputCommand), player_(player), output_(output) {
    }

protected:
    void Handle(const std::vector<std::string> &arguments) const override;

private:
    Player &player_;
    std::ostream& output_;
};

} // frontend

#endif //TAKEINPUTHANDLER_HPP
