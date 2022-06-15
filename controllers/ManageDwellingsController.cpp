#include "ManageDwellingsController.h"
#include "../views/ManageDwellingsView.h"
#include "DisplayDwellingsController.h"
#include "SearchDwellingController.h"
#include "AddDwellingController.h"

View *ManageDwellingsController::getView() {
    return new ManageDwellingsView("Manage Dwellings");
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
        case 0:
            return getPrevController();
        default:
            return this;
    }
}
