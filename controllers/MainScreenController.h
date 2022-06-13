#pragma once
#include "Controller.h"
#include "../views/MainView.h"

class MainScreenController : public Controller {
public:
    MainView* getView() override;
    Controller* getNextController(string input) override;
};


