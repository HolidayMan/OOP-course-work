#include "ManageQueueController.h"
#include "../models/QueueDwelling.h"
#include "../views/DisplayQueueView.h"
#include "../views/ChooseDwellingView.h"
#include "../views/PromptView.h"
#include "../utils.h"
#include "../models/DwellingManager.h"
#include "../models/Filter.h"


View *ManageQueueController::getView() {
    if (step == choosePerson) {
        if (queue->empty()) {
            return new PromptView("Queue: No people in queue");
        }

        if (page_size > queue->size()) {
            int _page_size = (int)queue->size();
            buildRange(1, _page_size);
        }

        vector<PersonInQueue*> personInQueueSlice;
        for (int i = range[0] - 1; i < range[range.size() - 1]; i++) {
            personInQueueSlice.push_back((*queue)[i]);
        }
        return new DisplayQueueView("Queue (" + std::to_string(range[0]) + "-" +
                                        std::to_string(range[range.size() - 1]) + " of " + std::to_string(queue->size()) + ")",
                                        *(new QueueDwelling(personInQueueSlice)),
                                        range);
    } else if (step == chooseDwelling) {
        if (data.dwellings.empty()) {
            return new PromptView("You have no dwellings to choose from. Enter \"cancel\" to return to the previous menu or \"q\" to quit.");
        }

        if (page_size > data.dwellings.size()) {
            int _page_size = (int)data.dwellings.size();
            buildRange(1, _page_size);
        }

        vector<Dwelling*> dwellingsSlice;
        for (int i = range[0] - 1; i < range[range.size() - 1]; i++) {
            dwellingsSlice.push_back(data.dwellings[i]);
        }
        return new ChooseDwellingView("Choose dwelling by entering its number: (" + std::to_string(range[0]) + "-" +
                                            std::to_string(range[range.size() - 1]) + " of " + std::to_string(data.dwellings.size()) + ")",
                                            dwellingsSlice, range);
    }
    return new PromptView("Error: Unknown step");
}

Controller *ManageQueueController::getNextController(string input) {
    if (strcmp(input.c_str(), "") == 0) {
        return this;
    }
    switch (step) {
        case choosePerson:
            if (strcmp(input.c_str(), "p") == 0) { // previous page
                if (queue->size() == page_size) { // if there is only one page
                    return this;
                }
                if (range[0] != 1) { // if we are not on the first page
                    buildRange(range[0] - page_size, range[0] - 1);
                }
                return this;
            }

            if (strcmp(input.c_str(), "n") == 0) { // next page
                if (queue->size() == page_size) { // if there is only one page
                    return this;
                }
                if (range[range.size() - 1] + page_size > queue->size() && range[range.size() - 1] != queue->size()) { // if last page's length is less than page_size
                    buildRange(range[range.size() - 1] + 1, (int)queue->size());
                    return this;
                }
                if (range[range.size() - 1] != queue->size()) { // if we are not on the last page
                    buildRange(range[range.size() - 1] + 1, range[range.size() - 1] + page_size);
                }
                return this;
            }
            if (!isNumber(input) || stoi(input) < 1 || stoi(input) > queue->size()) {
                return this;
            }
            step = chooseDwelling;
            buildRange(1, page_size);
            data.chosenPersonInQueue = (*queue)[stoi(input) - 1];
            data.dwellings = DwellingManager().filter(new NotInFilter("id", "(SELECT dwelling FROM person_in_queue where is_satisfied = 1)"));
            return this;

        case chooseDwelling:
            if (strcmp(input.c_str(), "p") == 0) { // previous page
                if (data.dwellings.size() <= page_size) { // if there is only one page
                    return this;
                }
                if (range[0] != 1) { // if we are not on the first page
                    buildRange(range[0] - page_size, range[0] - 1);
                }
                return this;
            }

            if (strcmp(input.c_str(), "n") == 0) { // next page
                if (data.dwellings.size() <= page_size) { // if there is only one page
                    return this;
                }
                if (range[range.size() - 1] + page_size > data.dwellings.size() && range[range.size() - 1] != data.dwellings.size()) { // if last page's length is less than page_size
                    buildRange(range[range.size() - 1] + 1, (int)data.dwellings.size());
                    return this;
                }
                if (range[range.size() - 1] != data.dwellings.size()) { // if we are not on the last page
                    buildRange(range[range.size() - 1] + 1, range[range.size() - 1] + page_size);
                }
                return this;
            }

            if (strcmp(input.c_str(), "cancel") == 0) {
                step = choosePerson;
                data.clear();
                buildRange(1, page_size);
                return this;
            }

            if (!isNumber(input) || stoi(input) < 1 || stoi(input) > data.dwellings.size()) {
                return this;
            }
            data.chosenDwelling = data.dwellings[stoi(input) - 1];
            save();
            queue = new QueueDwelling();
            step = choosePerson;
            return this;
    }
    return this;
}

ManageQueueController::ManageQueueController(Controller *_prevController) : Controller(_prevController) {
    buildRange(1, page_size);
    queue = new QueueDwelling();
}

void ManageQueueController::buildRange(int start, int end) {
    range.clear();
    for (int i = start; i <= end; i++) {
        range.push_back(i);
    }
}

void ManageQueueController::save() {
    data.chosenPersonInQueue->dwelling = data.chosenDwelling;
    data.chosenPersonInQueue->isSatisfied = true;
    data.chosenPersonInQueue->save();
    data.clear();
}