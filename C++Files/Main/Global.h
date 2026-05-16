#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"

using namespace std;

clsUser CurrentUser = clsUser::Find("", "");
clsDate CurrentDate;
const string cCyan = "\033[36m";
const string cGreen = "\033[32m";
const string cRed = "\033[31m";
const string cYellow = "\033[33m";
const string cReset = "\033[0m";
const string cMagenta = "\033[35m";
const string cWhite = "\033[37m";
const string cBlue = "\033[94m";