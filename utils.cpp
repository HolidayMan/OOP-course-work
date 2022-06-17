#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std;

winsize getWinsize() {
    winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w;
}

bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
