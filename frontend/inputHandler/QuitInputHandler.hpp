

#ifndef QUITINPUTHANDLER_HPP
#define QUITINPUTHANDLER_HPP

#include <functional>
#include "BaseInputHandler.hpp"

namespace frontend {

class QuitInputHandler: public BaseInputHandler {
public:
    explicit QuitInputHandler(const std::string& inputCommand, bool& playing, std::ostream& output);

protected:
    void Handle(const std::vector<std::string>& arguments) const override;

private:
    bool& playing_;
    std::ostream& output_;
};

} // frontend

#endif //QUITINPUTHANDLER_HPP
