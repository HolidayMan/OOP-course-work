#pragma once

#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "Dwelling.h"

using namespace std;


class Dwelling;

class DwellingManager: public ModelManager<Dwelling> {
public:
    vector<Dwelling*> getList() override;
    Dwelling* get() override;
    vector<Dwelling*> filter() override;
    Dwelling* save(Dwelling* model)  override;
};

