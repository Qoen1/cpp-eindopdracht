

#ifndef QUITINPUTHANDLER_HPP
#define QUITINPUTHANDLER_HPP

#include <functional>
#include "BaseInputHandler.hpp"

namespace frontend {

class QuitInputHandler: public BaseInputHandler {
public:
    explicit QuitInputHandler(const std::string& inputCommand, const std::function<void(bool)>& callback);

protected:
    void Handle(const std::vector<std::string>& arguments) const override;

private:
    const std::function<void(bool)>& callback_;
};

} // frontend

#endif //QUITINPUTHANDLER_HPP
