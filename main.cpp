#include <iostream>
#include <cstring>
#include "Tests.h"
#include "Exceptions.h"

using namespace std;

int runProgram() {
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
