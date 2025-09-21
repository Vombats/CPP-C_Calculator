#include "input_output.h"

int safeAdd(CalcData* data)
{
    // Check for positive overflow
    if (data->a > 0 && data->b > 0 && data->a > INT_MAX - data->b)
    {
        return 0;
    }
    // Check for negative overflow
    if (data->a < 0 && data->b < 0 && data->a < INT_MIN - data->b)
    {
        return 0;
    }
    data->result = data->a + data->b;
    return 1;
}

int safeMultiply(CalcData* data)
{
    // Handle special cases
    if (data->a == 0 || data->b == 0)
    {
        data->result = 0;
        return 1;
    }

    // Check for overflow
    if (data->a > 0)
    {
        if (data->b > 0 && data->a > INT_MAX / data->b)
            return 0;
        if (data->b < 0 && data->b < INT_MIN / data->a)
            return 0;
    }
    else
    {
        if (data->b > 0 && data->a < INT_MIN / data->b)
            return 0;
        if (data->b < 0 && data->a < INT_MAX / data->b)
            return 0;
    }

    data->result = data->a * data->b;
    return 1;
}