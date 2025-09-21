#include "input_output.h"

void clearScreen()
{
#ifdef _WIN32
    // Windows
    system("cls");
#else
    // Linux/Unix/macOS
    system("clear");
#endif
}