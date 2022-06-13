#pragma once

#include "../models/Model.h"
#include "../views/View.h"


class Controller {
public:
    virtual View* getView() = 0;
    virtual Controller* getNextController(string input) = 0;
};