

#include "QuitInputHandler.hpp"

namespace frontend {
    QuitInputHandler::QuitInputHandler(const std::string& inputCommand, bool& playing):
    BaseInputHandler(inputCommand), playing_(playing) {
    }

    void QuitInputHandler::Handle(const std::vector<std::string>& arguments) const {
        playing_ = false;
    }
} // frontend