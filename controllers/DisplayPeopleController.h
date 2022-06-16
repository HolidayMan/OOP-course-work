#pragma once
#include "Controller.h"
#include "../models/Person.h"


class DisplayPeopleController: public Controller {
public:
    explicit DisplayPeopleController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
};