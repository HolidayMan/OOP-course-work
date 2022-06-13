#pragma once
#include "View.h"
#include "../models/Model.h"


class MainView: public View {
public:
    explicit MainView(string _header) : View(std::move(_header)) {}
    string getScreenData() override;
};

