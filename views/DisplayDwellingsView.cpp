#include "DisplayDwellingsView.h"
#include <ios>
#include <iomanip>
#include <sstream>
#include "../utils.h"


string DisplayDwellingsView::getScreenData() {
    std::stringstream sstream;
    auto w = getWinsize();
    int listSize = (int)dwellings.size();
    string sep = " | ";

    sstream << std::setw(w.ws_col / 2 + header.size() / 2) << std::right << header << std::endl;
    for (int i = 0; i < w.ws_col; i++) {
        sstream << "-";
    }
    sstream << endl << endl;

    sstream << setw(7) << std::right << "N" << sep << setw(w.ws_col / 2) <<
            "Address" << sep << setw(4) << "Rooms count" << sep << endl;
    for (int i = 0; i < w.ws_col; i++) {
        sstream << "-";
    }

    for (int i = 0; i < w.ws_row / 3 - listSize * 2; i++) {
        sstream << std::endl;
    }

    sstream << endl;

    for (int i = 0; i < listSize; i++) {
        auto* dwelling = dwellings[i];
        int num = range[i];
        sstream << setw(7) << std::right << num << sep << setw(w.ws_col / 2) <<
                dwelling->address << sep << setw(4) << dwelling->rooms << sep << endl;
    }

    for (int i = 0; i < w.ws_row / 3 - listSize; i++) {
        sstream << std::endl;
    }

    sstream << setw(w.ws_col / 3) << std::right << " " << "0. Previous page" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "q. Quit" << endl;

    sstream << endl;

    return sstream.str();
}
