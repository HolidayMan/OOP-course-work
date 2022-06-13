#pragma once
#include "CRUD.h"
#include "Controller.h"
#include "../models/Dwelling.h"
#include "../models/DwellingManager.h"


class DwellingController : public CRUD<Dwelling>, public Controller {
    View* getView() override;
    Dwelling* create() override;
    Dwelling* read() override;
    Dwelling* update() override;
    Dwelling* remove() override;
};
