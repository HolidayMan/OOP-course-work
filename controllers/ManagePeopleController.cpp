#include "ManagePeopleController.h"
#include "DisplayPeopleController.h"
#include "AddPersonController.h"
#include "../views/MenuListView.h"


View *ManagePeopleController::getView() {
    return new MenuListView("Manage people", {
        "1. Show and search through all people",
        "2. Add new dwelling",
    });
}

Controller *ManagePeopleController::getNextController(string input) {
    if (!isdigit(input[0]) || input.size() != 1) {
        return this;
    }
    switch (std::stoi(input)) {
        case 1:
            return new DisplayPeopleController(this);
        case 2:
            return new AddPersonController(this);
        default:
            return this;
    }
}
