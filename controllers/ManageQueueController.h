#pragma once
#include "Controller.h"

class ManageQueueController : public Controller {
public:
    explicit ManageQueueController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
};