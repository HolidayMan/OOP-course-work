#pragma once
#include "Controller.h"


class ManagePeopleController: public Controller {
public:
    explicit ManagePeopleController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
};

