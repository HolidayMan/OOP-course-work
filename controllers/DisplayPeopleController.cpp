#include "DisplayPeopleController.h"
#include "../models/PersonManager.h"
#include "../models/Person.h"
#include "../views/DisplayPeopleView.h"
#include <boost/algorithm/string.hpp>


View *DisplayPeopleController::getView() {
    if (people.empty() || range.size() == 0) {
        return new DisplayPeopleView("People list: No pople", vector<Person*>(), vector<int>());
    }

    if (page_size > people.size()) {
        int _page_size = (int)people.size();
        buildRange(1, _page_size);
    }

    vector<Person*> dwellingsSlice;
    for (int i = range[0] - 1; i < range[range.size() - 1]; i++) {
        dwellingsSlice.push_back(people[i]);
    }
    return new DisplayPeopleView("People list (" + std::to_string(range[0]) + "-" +
                                   std::to_string(range[range.size() - 1]) + " of " + std::to_string(people.size()) + ")",
                                   dwellingsSlice,
                                   range);
}

Controller *DisplayPeopleController::getNextController(string input) {
    if (input.empty()) {
        people = PersonManager().getList();
        buildRange(1, page_size);
        return this;
    }
    if (input[0] == 's' && input[1] == ' ') { // search
        string query = input.substr(2);
        search(query);
        if (people.size() > page_size) {
            buildRange(1, page_size);
        } else if (people.size() > 0) {
            buildRange(1, (int)people.size());
        }
        return this;
    }

    if (strcmp(input.c_str(), "p") == 0) { // previous page
        if (people.size() == page_size) { // if there is only one page
            return this;
        }
        if (range[0] != 1) { // if we are not on the first page
            buildRange(range[0] - page_size, range[0] - 1);
        }
        return this;
    }

    if (strcmp(input.c_str(), "n") == 0) { // next page
        if (people.size() == page_size) { // if there is only one page
            return this;
        }
        if (range[range.size() - 1] + page_size > people.size() && range[range.size() - 1] != people.size()) { // if last page's length is less than page_size
            buildRange(range[range.size() - 1] + 1, (int)people.size());
            return this;
        }
        if (range[range.size() - 1] != people.size()) { // if we are not on the last page
            buildRange(range[range.size() - 1] + 1, range[range.size() - 1] + page_size);
        }
        return this;
    }

    if (!isdigit(input[0]) || input.size() != 1) {
        return this;
    }
    return this;

}

void DisplayPeopleController::buildRange(int start, int end) {
    range.clear();
    for (int i = start; i <= end; i++) {
        range.push_back(i);
    }
}

void DisplayPeopleController::search(const string& query) {
    string lowerQuery = boost::to_lower_copy(query);
    if (strcmp(lowerQuery.c_str(), "male") == 0 || strcmp(lowerQuery.c_str(), "female") == 0) {
        lowerQuery = "'" + lowerQuery + "'";
        people = PersonManager().filter(new CompareFilter("sex", lowerQuery, "LIKE"));
        return;
    }
    string _query = "'%" + query + "%'";

    people = PersonManager().filter(new ORFilter(vector<std::shared_ptr<Filter>>{
            std::make_shared<CompareFilter>("name", query, "LIKE"),
            std::make_shared<CompareFilter>("birth_date", query, "LIKE"),
            std::make_shared<CompareFilter>("sex", query, "LIKE"),
            std::make_shared<CompareFilter>("family", query, "LIKE"),
    }));
}

DisplayPeopleController::DisplayPeopleController(Controller *_prevController) : Controller(_prevController) {
    people = PersonManager().getList();
    buildRange(1, page_size);
}
