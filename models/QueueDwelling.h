#pragma once


#include "PersonInQueue.h"

class QueueDwelling {
public:
    QueueDwelling();
    PersonInQueue* begin();
    PersonInQueue* end();
    size_t Size() const;
private:
    PersonInQueue* persons;
    size_t size;
};


