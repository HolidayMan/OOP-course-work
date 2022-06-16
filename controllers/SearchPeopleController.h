#pragma once
#include "Controller.h"

class SearchPeopleController: public Controller {
public:
    explicit SearchPeopleController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
};