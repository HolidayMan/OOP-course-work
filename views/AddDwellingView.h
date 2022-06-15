#pragma once
#include "View.h"

#include <utility>

class AddDwellingView : public View {
public:
    explicit AddDwellingView(string header) : View(std::move(header)) {}
    string getScreenData() override;
};