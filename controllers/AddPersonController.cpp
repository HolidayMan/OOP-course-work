#include "AddPersonController.h"
#include "../models/fields/Date.h"
#include "../models/Person.h"
#include "../utils.h"
#include "../views/PromptView.h"


View *AddPersonController::getView() {
    switch (step) {
        case enterName:
            return new PromptView("Enter NAME of person:");
        case enterYear:
            return new PromptView("Enter YEAR of birth:");
        case enterMonth:
            return new PromptView("Enter MONTH of birth:");
        case enterDay:
            return new PromptView("Enter DAY of birth:");
        case enterSex:
            return new PromptView("Enter GENDER of person (m, f):");
        case enterFamily:
            return new PromptView("Enter person's family composition:");
    }
}

Controller *AddPersonController::getNextController(string input) {
    if (strcmp(input.c_str(), "cancel") == 0) {
        return prevController;
    }
    if (input.empty() && step != enterFamily) {
        return this;
    }
    switch (step) {
        case enterName:
            name = input;
            step = enterYear;
            return this;
        case enterYear:
            if (!isNumber(input) || std::stoi(input) < 1900) {
                return this;
            }
            dateInfo.year = std::stoi(input);
            step = enterMonth;
            return this;
        case enterMonth:
            if (!isNumber(input) || std::stoi(input) < 1 || std::stoi(input) > 12) {
                return this;
            }
            dateInfo.month = std::stoi(input);
            step = enterDay;
            return this;
        case enterDay:
            if (!isNumber(input) ||
            std::stoi(input) > Date::getDaysOfMonth(dateInfo.year, dateInfo.month) ||
            std::stoi(input) < 1) {
                return this;
            }
            dateInfo.day = std::stoi(input);
            birthDate = make_shared<Date>(dateInfo.year, dateInfo.month, dateInfo.day);
            step = enterSex;
            return this;
        case enterSex:
            if (input.size() != 1) {
                return this;
            }
            switch (input[0]) {
                case 'm':
                    sex = "Male";
                    break;
                case 'f':
                    sex = "Female";
                    break;
                default:
                    return this;
            }
            step = enterFamily;
            return this;
        case enterFamily:
            family = input;
            save();
            return prevController;
    }
}

void AddPersonController::save() {
    Person person(name, birthDate.get(), sex, family);
    person.save();
}
