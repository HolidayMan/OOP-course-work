#include <sstream>
#include <iomanip>
#include <ios>
#include "ManageDwellingsView.h"
#include "../utils.h"

string ManageDwellingsView::getScreenData() {
    std::stringstream sstream;
    auto w = getWinsize();
    int listSize = 5;

    sstream << std::setw(w.ws_col / 2 + header.size() / 2) << std::right << header << std::endl;
    for (int i = 0; i < w.ws_col; i++) {
        sstream << "-";
    }

    for (int i = 0; i < w.ws_row / 2 - listSize; i++) {
        sstream << std::endl;
    }

    sstream << setw(w.ws_col / 3) << std::right << " " << "1. Show all dwellings" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "2. Search dwellings" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "3. Add new dwelling" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "0. Previous page" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "q. Quit" << endl;

    for (int i = 0; i < w.ws_row / 2 - (listSize + 1); i++) {
        sstream << std::endl;
    }

    return sstream.str();
}
