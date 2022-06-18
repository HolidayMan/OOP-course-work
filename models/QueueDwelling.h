#pragma once


#include "PersonInQueue.h"

class QueueDwelling {
public:
    QueueDwelling();
    explicit QueueDwelling(vector<PersonInQueue*> _queue);
    ~QueueDwelling();
    PersonInQueue* begin();
    PersonInQueue* end();
    size_t size() const;
    PersonInQueue* operator[](size_t index);
    bool empty() const;
private:
    PersonInQueue* queue;
    size_t _size;
};


