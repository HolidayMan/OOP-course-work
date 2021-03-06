#pragma once
#include "Controller.h"

class ManageDwellingsController : public Controller {
public:
    explicit ManageDwellingsController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
};