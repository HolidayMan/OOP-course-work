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
    Dwelling* get(int pk) const override;
    vector<Dwelling*> filter(Filter* condition) const override;
    Dwelling* save(const Dwelling* model)  const override;
    int remove(const Dwelling* model) const override;
};

Dwelling* initDwellingWithPk(int pk, string address, int rooms);