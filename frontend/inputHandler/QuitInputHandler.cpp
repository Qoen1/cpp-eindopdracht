

#include "QuitInputHandler.hpp"

namespace frontend {
    QuitInputHandler::QuitInputHandler(const std::string& inputCommand, bool& playing, std::ostream& output):
    BaseInputHandler(inputCommand), playing_(playing), output_(output) {
    }

    void QuitInputHandler::Handle(const std::vector<std::string>& arguments) const {
        playing_ = false;
    }
} // frontend