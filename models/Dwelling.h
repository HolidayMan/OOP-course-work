#pragma once

#include "Model.h"
#include "DwellingManager.h"

class DwellingManager;

class Dwelling: public Model {
public:
    const string tableName = "dwelling";
    Dwelling(string _address, int _rooms);
    const DwellingManager* manager;
    string address;
    int rooms;
    Dwelling* save() const override;
    int remove() const override;
};
