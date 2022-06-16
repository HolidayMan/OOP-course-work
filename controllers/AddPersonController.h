#pragma once
#include "Controller.h"

class AddPersonController: public Controller {
public:
    explicit AddPersonController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
};
