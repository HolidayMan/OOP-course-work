#include <iostream>
#include "Exceptions.h"

using namespace std;

Exception::Exception(string _message) noexcept : message(move(_message)) { }

const char *Exception::what() const noexcept {
    return message.c_str();
}

