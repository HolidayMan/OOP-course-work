#include <iostream>
#include "Tests.h"
#include "models/DwellingManager.h"

using namespace std;


int main(int argc, char** argv) {
    if (argc > 1 && strcmp(argv[1], "test") == 0) {
        return runTests();
    }

    return 0;
}
