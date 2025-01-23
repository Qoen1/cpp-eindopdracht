

#include "QuitInputHandler.hpp"

namespace frontend {
    QuitInputHandler::QuitInputHandler(const std::string& inputCommand, const std::function<void(bool)>& callback):
    BaseInputHandler(inputCommand), callback_(callback) {
    }

    void QuitInputHandler::Handle(const std::vector<std::string>& arguments) const {
        callback_(false);
    }
} // frontend