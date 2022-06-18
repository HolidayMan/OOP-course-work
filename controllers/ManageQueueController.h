#pragma once
#include "Controller.h"
#include "../models/QueueDwelling.h"

enum Step {choosePerson, chooseDwelling};
struct Data{
    PersonInQueue* chosenPersonInQueue;
    Dwelling* chosenDwelling;
    vector<Dwelling*> dwellings;
    void clear() {
        chosenPersonInQueue = nullptr;
        chosenDwelling = nullptr;
        dwellings.clear();
    }
};

class ManageQueueController : public Controller {
public:
    explicit ManageQueueController(Controller *_prevController);
    View* getView() override;
    Controller* getNextController(string input) override;
private:
    QueueDwelling* queue;
    vector<int> range;
    Step step = choosePerson;
    int page_size = 7;
    Data data;
    void buildRange(int start, int end);
    void save();
};