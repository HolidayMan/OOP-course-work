#include "MainScreenController.h"
#include "../views/MainView.h"

MainView *MainScreenController::getView() {
    return new MainView("Main screen");
}

Controller *MainScreenController::getNextController(string input) {
    return this;
}
