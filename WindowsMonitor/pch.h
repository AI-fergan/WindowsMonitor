#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h> 
#include <iostream>
#include <tchar.h>
#include <psapi.h>
#include <iomanip>
#include <tchar.h>
#include <vector>
#include <dxgi.h>

#pragma comment(lib, "dxgi.lib")

#define EXIT -1
#define INFO_BUFFER_SIZE 32767
#define GIGABYTE 1073741824 // b * kb * mb = 1024 * 3

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::wcerr;
using std::wcout;