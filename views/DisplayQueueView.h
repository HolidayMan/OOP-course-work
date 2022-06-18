#pragma once
#include "../models/PersonInQueue.h"
#include "View.h"
#include "../models/QueueDwelling.h"


class DisplayQueueView : public View {
public:
    DisplayQueueView(string header, const QueueDwelling& queue, vector<int> range)
    : View(std::move(header)), queue(queue), range(std::move(range)) {}
    ~DisplayQueueView();
    string getScreenData() override;
private:
    QueueDwelling queue;
    vector<int> range;
};