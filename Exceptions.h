#pragma once
#include <iostream>

using namespace std;

class Exception : exception {
public:
    explicit Exception(string _message) noexcept;
    const char *what() const noexcept override;

private:
    string message;
};

