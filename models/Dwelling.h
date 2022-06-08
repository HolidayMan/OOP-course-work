#pragma once

#include "Model.h"
#include "DwellingManager.h"

class DwellingManager;

class Dwelling: Model {
    Dwelling(string _address, int _rooms);
    DwellingManager* manager;
    string address;
    int rooms;
};
