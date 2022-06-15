#pragma once
#include "Controller.h"
#include <vector>
#include "../models/Dwelling.h"

class DisplayDwellingsController : public Controller {
public:
    explicit DisplayDwellingsController(Controller *_prevController);
    View* getView() override;
    Controller* getNextController(string input) override;

private:
    vector<Dwelling*> dwellings;
    vector<int> range;
    int page_size = 7;
    void buildRange(int start, int end);
};
