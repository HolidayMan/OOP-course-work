#pragma once
#include "Controller.h"

enum Steps {enterAddress, enterRooms};

class AddDwellingController : public Controller {
public:
    explicit AddDwellingController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;
private:
    void save();
    Steps step = enterAddress;
    string address;
    int rooms;
};