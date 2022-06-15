#include "DisplayDwellingsController.h"
#include "../models/DwellingManager.h"
#include "../models/Dwelling.h"
#include "../views/DisplayDwellingsView.h"
#include <vector>

View *DisplayDwellingsController::getView() {
    if (dwellings.empty()) {
        return new DisplayDwellingsView(vector<Dwelling*>(), vector<int>(), "Dwellings list: No dwellings");
    }

    if (page_size > dwellings.size()) {
        page_size = (int)dwellings.size();
        buildRange(1, page_size);
    }

    vector<Dwelling*> dwellingsSlice;
    for (int i = range[0] - 1; i < range[range.size() - 1]; i++) {
        dwellingsSlice.push_back(dwellings[i]);
    }
    return new DisplayDwellingsView(std::move(dwellingsSlice),
                                    range,
                                    "Dwellings list (" + std::to_string(range[0]) + "-" +
                                    std::to_string(range[range.size() - 1]) + " of " + std::to_string(dwellings.size()) + ")");
}

Controller *DisplayDwellingsController::getNextController(string input) {
    if (strcmp(input.c_str(), "p") == 0) { // previous page
        if (dwellings.size() == page_size) { // if there is only one page
            return this;
        }
        if (range[0] != 1) { // if we are not on the first page
            buildRange(range[0] - page_size, range[0] - 1);
        }
        return this;
    }

    if (strcmp(input.c_str(), "n") == 0) { // next page
        if (dwellings.size() == page_size) { // if there is only one page
            return this;
        }
        if (range[range.size() - 1] + page_size > dwellings.size() && range[range.size() - 1] != dwellings.size()) { // if last page's length is less than page_size
            buildRange(range[range.size() - 1] + 1, (int)dwellings.size());
            return this;
        }
        if (range[range.size() - 1] != dwellings.size()) { // if we are not on the last page
            buildRange(range[range.size() - 1] + 1, range[range.size() - 1] + page_size);
        }
        return this;
    }

    if (!isdigit(input[0]) || input.size() != 1) {
        return this;
    }
    switch (std::stoi(input)) {
        case 0:
            return getPrevController();
        default:
            return this;
    }
}

DisplayDwellingsController::DisplayDwellingsController(Controller *_prevController) : Controller(_prevController) {
    dwellings = DwellingManager().getList();
    buildRange(1, page_size);
}

void DisplayDwellingsController::buildRange(int start, int end) {
    range.clear();
    for (int i = start; i <= end; i++) {
        range.push_back(i);
    }

}
