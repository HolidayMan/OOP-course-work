#pragma once
#include "View.h"

#include <utility>
#include "../models/Dwelling.h"


class ChooseDwellingView : public View {
public:
    explicit ChooseDwellingView(string _header, vector<Dwelling*> dwellings, vector<int> range)
            : dwellings(std::move(dwellings)), range(std::move(range)), View(std::move(_header)) {}
    string getScreenData() override;
private:
    vector<Dwelling*> dwellings;
    vector<int> range;
};
