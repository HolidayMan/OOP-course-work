#pragma once
#include "View.h"

#include <utility>
#include "../models/Person.h"

class DisplayPeopleView : public View {
public:
    explicit DisplayPeopleView(string header, vector<Person*> people, vector<int> range)
    : View(std::move(header)), people(std::move(people)), range(std::move(range)) {}
    string getScreenData() override;
    ~DisplayPeopleView();
private:
    vector<Person*> people;
    vector<int> range;
};