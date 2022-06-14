#include "MainScreenController.h"
#include "../views/MainView.h"
#include "ManagePeopleController.h"
#include "ManageDwellingsController.h"
#include "ManageQueueController.h"

MainView *MainScreenController::getView() {
    return new MainView("Main screen");
}

Controller *MainScreenController::getNextController(string input) {
    if (!isdigit(input[0]) || input.size() != 1) {
        return this;
    }
    switch (std::stoi(input)) {
        case 1:
            return new ManagePeopleController(this);
        case 2:
            return new ManageDwellingsController(this);
        case 3:
            return new ManageQueueController(this);
        default:
            return this;
    }
}
