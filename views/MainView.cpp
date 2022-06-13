#include "MainView.h"
#include <ios>
#include <iomanip>
#include <sstream>
#include "boost/format.hpp"
#include "../utils.h"


string MainView::getScreenData() {
    std::ostringstream sstream;
    auto w = getWinsize();
    int listSize = 4;

    sstream << std::setw(w.ws_col / 2 + header.size() / 2) << std::right << header << std::endl;
    for (int i = 0; i < w.ws_col; i++) {
        sstream << "-";
    }

    for (int i = 0; i < w.ws_row / 2 - listSize; i++) {
        sstream << std::endl;
    }

    sstream << setw(w.ws_col / 3) << std::right << " " << "1. Manage people" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "2. Manage dwellings" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "3. Manage queue" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "0. Quit" << endl;

    for (int i = 0; i < w.ws_row / 2 - (listSize + 1); i++) {
        sstream << std::endl;
    }

    return sstream.str();
}

/*
 * 1. Manage people
 * 2. Manage dwellings
 * 3. Manage queue
*/
