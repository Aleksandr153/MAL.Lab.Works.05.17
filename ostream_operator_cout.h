#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

#include "string_set.h"

ostream& operator << (ostream& out, string_set a);   //функция потокового вывода последовательности для консоли ( операция << );