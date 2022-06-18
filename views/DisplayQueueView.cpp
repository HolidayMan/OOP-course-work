#include "DisplayQueueView.h"
#include "../models/PersonInQueue.h"
#include "../models/QueueDwelling.h"
#include "../utils.h"
#include <iomanip>
#include <ios>

DisplayQueueView::~DisplayQueueView() {
    delete &queue;
    range.clear();
    vector<int>().swap(range);
    delete &range;
}

string DisplayQueueView::getScreenData() {
    std::stringstream sstream;
    auto w = getWinsize();
    int listSize = (int)queue.size();
    string sep = " | ";

    sstream << std::setw(w.ws_col / 2 + header.size() / 2) << std::right << header << std::endl;
    for (int i = 0; i < w.ws_col; i++) {
        sstream << "-";
    }
    sstream << endl << endl;

    sstream << setw(7) << std::right << "N" << sep << setw(10) << "Date added" << sep << setw(w.ws_col / 4) <<
            "Name" << sep << setw(10) << "Birth date" << sep << setw(6) << "Sex" << sep << setw(w.ws_col / 4) << "Family" << sep << endl;
    for (int i = 0; i < w.ws_col; i++) {
        sstream << "-";
    }

    for (int i = 0; i < w.ws_row / 3 - listSize; i++) {
        sstream << std::endl;
    }

    sstream << endl;

    for (int i = 0; i < listSize; i++) {
        auto* pInQueue = queue[i];
        int num = range[i];
        sstream << setw(7) << std::right << num << sep << pInQueue->dateAdded->toString() << sep << setw(w.ws_col / 4) <<
                pInQueue->person->name << sep << setw(10) << pInQueue->person->birthDate->toString() <<
                sep << setw(6) << pInQueue->person->sex << sep << setw(w.ws_col / 4) << pInQueue->person->family << sep << endl;
    }

    for (int i = 0; i < w.ws_row / 3 - listSize; i++) {
        sstream << std::endl;
    }

    sstream << setw(w.ws_col / 4) << std::right << " " << "<n>. You can choose specific person-in-line with entering his number" << endl;
    sstream << setw(w.ws_col / 4) << std::right << " " << "0. Previous page" << endl;
    sstream << setw(w.ws_col / 4) << std::right << " " << "q. Quit" << endl;

    sstream << endl;

    return sstream.str();

}
