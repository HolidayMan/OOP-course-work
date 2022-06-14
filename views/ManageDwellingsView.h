#pragma once
#include "../views/View.h"

class ManageDwellingsView : public View {
public:
    explicit ManageDwellingsView(string _header) : View(std::move(_header)) {}
    string getScreenData() override;
};