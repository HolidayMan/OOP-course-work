#include <iostream>
#include <cstring>
#include "Tests.h"
#include "Exceptions.h"
#include "controllers/MainScreenController.h"
#include "views/View.h"
#include "utils.h"
#include <boost/algorithm/string.hpp>


using namespace std;

int runProgram() {
    auto mainScreenController = new MainScreenController();
    auto mainView = mainScreenController->getView();
    Controller* controller = mainScreenController;
    View* view = mainView;

    while (true) {
        system("clear");
        cout << view->getScreenData() << endl;

        string input;
        cin >> input;
        boost::trim(input);
        if (input == "q" or input == "Q") {
            break;
        }

        controller = controller->getNextController(input);
        view = controller->getView();
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc > 1 && strcmp(argv[1], "test") == 0) {
        try {
            return runTests();
        } catch (Exception const &e) {
            cout << "Fatal error: " << e.what();
        }
    }

    try {
        return runProgram();
    } catch (Exception const &e) {
        cout << "Fatal error: " << e.what();
    }
}
