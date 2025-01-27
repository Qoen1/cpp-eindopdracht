//
// Created by koenv on 26/01/2025.
//

#ifndef HELPINPUTMANAGER_HPP
#define HELPINPUTMANAGER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {

class HelpInputManager: public BaseInputHandler {
public:
    explicit HelpInputManager(const std::string &inputCommand, std::ostream& output);

protected:
    void Handle(const std::vector<std::string> &arguments) const override;
private:
    std::ostream& output_;
};

} // frontend

#endif //HELPINPUTMANAGER_HPP
