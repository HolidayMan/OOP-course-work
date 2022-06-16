#include "SearchDwellingController.h"
#include "../views/SearchDwellingsView.h"
#include "../models/Filter.h"


View *SearchDwellingController::getView() {
    if (dwellings.empty() || range.size() == 0) {
        return new SearchDwellingsView("Dwellings list: No dwellings", vector<Dwelling*>(), vector<int>());
    }

    if (page_size > dwellings.size()) {
        int _page_size = (int)dwellings.size();
        buildRange(1, _page_size);
    }

    vector<Dwelling*> dwellingsSlice;
    for (int i = range[0] - 1; i < range[range.size() - 1]; i++) {
        dwellingsSlice.push_back(dwellings[i]);
    }
    return new SearchDwellingsView("Search dwellings (" + std::to_string(range[0]) + "-" +
                                   std::to_string(range[range.size() - 1]) + " of " + std::to_string(dwellings.size()) + ")",
                                   dwellingsSlice,
                                   range);
}

Controller *SearchDwellingController::getNextController(string input) {
    if (input[0] == 's' && input[1] == ' ') { // search
        string query = "'%" + input.substr(2) + "%'";
        search(query);
        if (dwellings.size() > page_size) {
            buildRange(1, page_size);
        } else if (dwellings.size() > 0) {
            buildRange(1, (int)dwellings.size());
        }
        return this;
    }

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
    return this;
}

void SearchDwellingController::buildRange(int start, int end) {
    range.clear();
    for (int i = start; i <= end; i++) {
        range.push_back(i);
    }

}

void SearchDwellingController::search(const string& query) {
    dwellings = DwellingManager().filter(new ORFilter(vector<std::shared_ptr<Filter>>{
            std::make_shared<CompareFilter>("address", query, "LIKE"),
            std::make_shared<CompareFilter>("rooms", query, "LIKE"),
    }));
}
