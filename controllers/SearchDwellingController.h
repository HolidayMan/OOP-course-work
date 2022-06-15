#pragma once
#include "Controller.h"

class SearchDwellingController : public Controller {
public:
    explicit SearchDwellingController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
};