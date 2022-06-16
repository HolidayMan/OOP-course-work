#include "AddDwellingController.h"
#include "../views/PromptView.h"
#include "../models/Dwelling.h"


View *AddDwellingController::getView() {
    switch (step) {
        case enterAddress:
            return new PromptView("Enter address:");
        case enterRooms:
            return new PromptView("Enter number of rooms:");
        default:
            return new PromptView("Error");
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
