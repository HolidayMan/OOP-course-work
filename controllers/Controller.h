#pragma once

#include "../models/Model.h"
#include "../views/View.h"


class Controller {
public:
    explicit Controller(Controller* prevController) : prevController(prevController) {}
    virtual View* getView() = 0;
    virtual Controller* getNextController(string input) = 0;
    virtual Controller* getPrevController();

protected:
    Controller* prevController;
};
