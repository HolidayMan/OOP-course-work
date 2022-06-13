#pragma once
#include "CRUD.h"
#include "../models/Dwelling.h"
#include "../models/DwellingManager.h"


class DwellingController : CRUD<Dwelling>{
    View<Dwelling>* getView() override;
    Dwelling* create() override;
    Dwelling* read() override;
    Dwelling* update() override;
    Dwelling* remove() override;
};
