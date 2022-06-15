#include "AddDwellingView.h"
#include <sstream>
#include <ios>
#include <iomanip>
#include "../utils.h"

string AddDwellingView::getScreenData() {
    std::stringstream sstream;
    auto w = getWinsize();
    sstream << std::setw(w.ws_col / 2 + header.size() / 2) << std::right << header << std::endl;

    for (int i = 0; i < w.ws_row - 5; i++) {
        sstream << endl;
    }

    return sstream.str();
}
