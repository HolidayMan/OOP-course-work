#include "DisplayPeopleView.h"
#include "sstream"
#include <ios>
#include <iomanip>
#include "../utils.h"


DisplayPeopleView::~DisplayPeopleView() {
    for (auto person : people) {
        delete person;
    }
    delete &people;
}


string DisplayPeopleView::getScreenData() {
    std::stringstream sstream;
    auto w = getWinsize();
    int listSize = (int)people.size();
    string sep = " | ";

    sstream << std::setw(w.ws_col / 2 + header.size() / 2) << std::right << header << std::endl;
    for (int i = 0; i < w.ws_col; i++) {
        sstream << "-";
    }
    sstream << endl << endl;

    sstream << setw(7) << std::right << "N" << sep << setw(w.ws_col / 2) <<
            "Name" << sep << setw(4) << "Birth date" << sep << "Sex" << sep << "Family" << sep << endl;
    for (int i = 0; i < w.ws_col; i++) {
        sstream << "-";
    }

    for (int i = 0; i < w.ws_row / 3 - listSize; i++) {
        sstream << std::endl;
    }

    sstream << endl;

    for (int i = 0; i < listSize; i++) {
        auto* person = people[i];
        int num = range[i];
        sstream << setw(7) << std::right << num << sep << setw(w.ws_col / 2) <<
                person->name << sep << setw(4) << person->birthDate->toString() << sep <<
                person->sex << sep << person->family << endl;
    }

    for (int i = 0; i < w.ws_row / 3 - listSize; i++) {
        sstream << std::endl;
    }

    sstream << setw(w.ws_col / 3) << std::right << " " << "s <your search query>. Search" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "0. Previous page" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "q. Quit" << endl;

    sstream << endl;

    return sstream.str();

}
