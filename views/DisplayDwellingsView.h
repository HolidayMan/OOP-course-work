#pragma once
#include "View.h"

#include <utility>
#include "../models/Dwelling.h"


class DisplayDwellingsView : public View {
public:
    explicit DisplayDwellingsView(vector<Dwelling*> dwellings, vector<int> range, string _header)
    : dwellings(std::move(dwellings)), range(std::move(range)), View(std::move(_header)) {}
    string getScreenData() override;

private:
    vector<Dwelling*> dwellings;
    vector<int> range;
};
