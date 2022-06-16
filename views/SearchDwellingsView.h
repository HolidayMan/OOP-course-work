#pragma once
#include "View.h"
#include "../models/Dwelling.h"
#include <utility>
#include <vector>

#include <utility>

class SearchDwellingsView : public View {
public:
    SearchDwellingsView(string header, vector<Dwelling*> dwellings, vector<int> range)
    : View(std::move(header)), dwellings(std::move(dwellings)), range(std::move(range)) {}
    string getScreenData() override;
    ~SearchDwellingsView();
private:
    vector<Dwelling*> dwellings;
    vector<int> range;
};