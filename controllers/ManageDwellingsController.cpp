#include "ManageDwellingsController.h"
#include "DisplayDwellingsController.h"
#include "SearchDwellingController.h"
#include "AddDwellingController.h"
#include "../views/MenuListView.h"

View *ManageDwellingsController::getView() {
    return new MenuListView("Manage dwellings", {
        "1. Show all dwellings",
        "2. Search dwellings",
        "3. Add new dwelling"
    });
}

Controller *ManageDwellingsController::getNextController(string input) {
    if (!isdigit(input[0]) || input.size() != 1) {
        return this;
    }
    switch (std::stoi(input)) {
        case 1:
            return new DisplayDwellingsController(this);
        case 2:
            return new SearchDwellingController(this);
        case 3:
            return new AddDwellingController(this);
        default:
            return this;
    }
}
