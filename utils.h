#pragma once

#include <sys/ioctl.h>
#include <string>

winsize getWinsize();
bool isNumber(const string& str);
