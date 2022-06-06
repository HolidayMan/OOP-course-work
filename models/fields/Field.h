#pragma once

template<class T>
class Field {
public:
    virtual T toRepresentation() = 0;
};

