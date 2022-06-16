#pragma once
#include "View.h"
#include <vector>

#include <utility>

class MenuListView : public View {
public:
    MenuListView(string header, vector<string> list) : list(std::move(list)), View(std::move(header)) {}
    string getScreenData() override;
private:
    vector<string> list;
};