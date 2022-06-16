#pragma once
#include "View.h"

#include <utility>

class PromptView : public View {
public:
    explicit PromptView(string header) : View(std::move(header)) {}
    string getScreenData() override;
};