#include <iostream>
#include "Tests.h"

using namespace std;


int main(int argc, char** argv) {
    if (argc > 0 && strcmp(argv[1], "test") == 0) {
        return runTests();
    }
    return 0;
}
