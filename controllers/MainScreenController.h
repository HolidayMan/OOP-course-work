#pragma once
#include "Controller.h"
#include "../views/MainView.h"

class MainScreenController : public Controller {
public:
    explicit MainScreenController(Controller *_prevController = nullptr) : Controller(_prevController) {}
    MainView* getView() override;
    Controller* getNextController(string input) override;
};


