#pragma once
#include "Controller.h"

class AddDwellingController : public Controller {
public:
    explicit AddDwellingController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
};