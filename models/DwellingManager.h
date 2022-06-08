#pragma once

#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "Dwelling.h"

using namespace std;


class Dwelling;

class DwellingManager: public ModelManager<Dwelling> {
public:
    vector<Dwelling*> getList() const override;
    Dwelling* get() const override;
    vector<Dwelling*> filter() const override;
    Dwelling* save(const Dwelling* model)  const override;
};

