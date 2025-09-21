#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

// C includes (for C-style modules)
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// C++ includes (for C++ main module)
#ifdef __cplusplus
#include <iostream>
#include <limits>
#include <iomanip>
#endif

// Structure to hold calculation data
typedef struct {
    int a;
    int b;
    int result;
} CalcData;

// Input validation functions (input_validation.cpp)
int readInteger(int* value);

// Arithmetic operation functions (arithmetic.cpp)
int safeAdd(CalcData* data);
int safeMultiply(CalcData* data);

// Calculator functions (calculator.cpp)
void squareNumber(CalcData* data);
void addNumbers(CalcData* data);
void subtractNumbers(CalcData* data);
void multiplyNumbers(CalcData* data);
void divideNumbers(CalcData* data);

// Geometry functions (geometry.cpp) - C++ style
void calculateRectangleArea(CalcData* data);
void calculateCircleArea(CalcData* data);
void calculateTriangleArea(CalcData* data);

#endif // INPUT_OUTPUT_H