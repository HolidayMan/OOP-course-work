#include "MenuListView.h"
#include "../utils.h"
#include <sstream>
#include <iomanip>
#include <ios>


string MenuListView::getScreenData() {
    std::stringstream sstream;
    auto w = getWinsize();
    int listSize = list.size();

    sstream << setw(w.ws_col / 2 + header.size() / 2) << std::right << header << std::endl;
    for (int i = 0; i < w.ws_col; i++) {
        sstream << "-";
    }

    for (int i = 0; i < w.ws_row / 3 - listSize; i++) {
        sstream << std::endl;
    }
    for (const auto& l: list) {
        sstream << setw(w.ws_col / 3) << std::right << " " << l << endl;
    }
    sstream << setw(w.ws_col / 3) << std::right << " " << "0. Previous page" << endl;
    sstream << setw(w.ws_col / 3) << std::right << " " << "q. Quit" << endl;

    for (int i = 0; i < w.ws_row / 3 - listSize; i++) {
        sstream << std::endl;
    }

    return sstream.str();
}
