#pragma once
#include "View.h"
#include "../models/Dwelling.h"
#include <vector>

#include <utility>

class SearchDwellingsView : public View {
public:
    SearchDwellingsView(string header, vector<Dwelling*> dwellings, vector<int> range)
    : View(std::move(header)), dwellings(dwellings), range(range) {}
    string getScreenData() override;
    ~SearchDwellingsView();
private:
    vector<Dwelling*> dwellings;
    vector<int> range;
};