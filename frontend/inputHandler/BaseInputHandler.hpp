//
// Created by koenv on 30/10/2024.
//

#ifndef BASEINPUTHANDLER_HPP
#define BASEINPUTHANDLER_HPP
#include <memory>
#include <string>
#include <vector>

namespace frontend {

class BaseInputHandler {
protected:
    std::unique_ptr<const std::string> inputCommand;
    virtual void Handle(const std::vector<std::string> &arguments) const = 0;
public:
    std::unique_ptr<const BaseInputHandler> nextHandler;

    BaseInputHandler(const std::string &inputCommand);
    void SetNextHandler(const BaseInputHandler& nextHandler);
    void Handle(const std::string& inputCommand, const std::vector< std::string>& arguments) const;


    BaseInputHandler(BaseInputHandler &&other) noexcept
        : inputCommand(std::move(other.inputCommand)),
          nextHandler(std::move(other.nextHandler)) {
    }

    BaseInputHandler & operator=(BaseInputHandler &&other) noexcept {
        if (this == &other)
            return *this;
        inputCommand = std::move(other.inputCommand);
        nextHandler = std::move(other.nextHandler);
        return *this;
    }
};

} // frontend

#endif //BASEINPUTHANDLER_HPP
