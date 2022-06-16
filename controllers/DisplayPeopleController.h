#pragma once
#include "Controller.h"
#include "../models/Person.h"


class DisplayPeopleController: public Controller {
public:
    explicit DisplayPeopleController(Controller *_prevController);
    View* getView() override;
    Controller* getNextController(string input) override;
private:
    vector<Person*> people;
    vector<int> range;
    int page_size = 7;
    void buildRange(int start, int end);
    void search(const string& query);
};