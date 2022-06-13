#pragma once
#include "View.h"
#include "../models/Model.h"


class MainView: public View<View<Model>> {
    string getScreenData() override;
};


/*
 * 1. Manage people
 * 2. Manage dwellings
 * 3. Manage queue
*/