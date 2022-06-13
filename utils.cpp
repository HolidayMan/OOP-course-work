#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>


winsize getWinsize() {
    winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w;
}

using namespace std;
