#include "ManageDwellingsController.h"
#include "../views/ManageDwellingsView.h"

View *ManageDwellingsController::getView() {
    return new ManageDwellingsView("Manage Dwellings");
}

Controller *ManageDwellingsController::getNextController(string input) {
    if (!isdigit(input[0]) || input.size() != 1) {
        return this;
    }
    switch (std::stoi(input)) {
        // TODO: implement all other cases
        case 0:
            return getPrevController();
        default:
            return this;
    }
}
