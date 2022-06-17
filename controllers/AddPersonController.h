#pragma once
#include "Controller.h"
#include "../models/fields/Date.h"

enum Steps {enterName, enterYear, enterMonth, enterDay, enterSex, enterFamily};

struct DateInfo {
    int day;
    int month;
    int year;
};

class AddPersonController: public Controller {
public:
    explicit AddPersonController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
private:
    void save();
    Steps step = enterName;
    string name;
    shared_ptr<Date> birthDate;
    string sex;
    string family;
    DateInfo dateInfo;
};
