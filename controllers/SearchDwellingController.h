#pragma once
#include "Controller.h"
#include "../models/Dwelling.h"

class SearchDwellingController : public Controller {
public:
    explicit SearchDwellingController(Controller *_prevController) : Controller(_prevController) {}
    View* getView() override;
    Controller* getNextController(string input) override;

private:
    vector<Dwelling*> dwellings;
    vector<int> range;
    int page_size = 7;
    void buildRange(int start, int end);
    void search(const string& input);
};