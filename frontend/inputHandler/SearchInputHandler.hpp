//
// Created by koenv on 31/10/2024.
//

#ifndef SEARCHINPUTHANDLER_HPP
#define SEARCHINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"
#include "../player/Player.hpp"

namespace frontend {
    class ICommand;

    class SearchInputHandler : public BaseInputHandler {
public:
    SearchInputHandler(const std::string &inputCommand, Player& player, ICommand &moveEnemiesCommand, std::ostream& output);
protected:
    void Handle(const std::vector<std::string> &arguments) const override;
private:
    Player& player_;
    ICommand& moveEnemiesCommand_;
    std::ostream& output_;
};

} // frontend

#endif //SEARCHINPUTHANDLER_HPP
