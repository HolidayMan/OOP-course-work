#include "AddDwellingController.h"
#include "../views/AddDwellingView.h"
#include "../models/Dwelling.h"


View *AddDwellingController::getView() {
    switch (step) {
        case enterAddress:
            return new AddDwellingView("Enter address:");
        case enterRooms:
            return new AddDwellingView("Enter number of rooms:");
        default:
            return new AddDwellingView("Error");
    }
}

Controller *AddDwellingController::getNextController(string input) {
    if (strcmp(input.c_str(), "cancel") == 0) {
        return prevController;
    }
    if (step == Steps::enterAddress) {
        address = input;
        step = Steps::enterRooms;
        return this;
    } else if (step == Steps::enterRooms) {
        if (input.size() > 1) {
            return this;
        }
        if (!isdigit(input[0])) {
            return this;
        }
        rooms = std::stoi(input);
        save();
        return prevController;
    }
}

void AddDwellingController::save() {
    Dwelling dwelling(address, rooms);
    dwelling.save();
}
