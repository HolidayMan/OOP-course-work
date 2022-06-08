#pragma once

#include "Model.h"
#include "DwellingManager.h"

class DwellingManager;

class Dwelling: Model {
    DwellingManager* manager;
    string type;
    string address;
    int rooms;
};
