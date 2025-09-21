#include "input_output.h"

void squareNumber(CalcData* data)
{
    CalcData square_data = {data->a, data->a, 0};
    if (safeMultiply(&square_data))
    {
        printf("Result: %i^2 = %i\n", data->a, square_data.result);
    }
    else
    {
        printf("Error: Square of %i causes integer overflow!\n", data->a);
    }
}

void addNumbers(CalcData* data)
{
    CalcData add_data = {data->a, data->b, 0};
    if (safeAdd(&add_data))
    {
        printf("Result: %i + %i = %i\n", data->a, data->b, add_data.result);
    }
    else
    {
        printf("Error: %i + %i causes integer overflow!\n", data->a, data->b);
    }
}

void subtractNumbers(CalcData* data)
{
    int neg_b = -data->b;
    CalcData sub_data = {data->a, neg_b, 0};
    if (data->b != INT_MIN && safeAdd(&sub_data))
    {
        printf("Result: %i - %i = %i\n", data->a, data->b, sub_data.result);
    }
    else
    {
        printf("Error: %i - %i causes integer overflow!\n", data->a, data->b);
    }
}

void multiplyNumbers(CalcData* data)
{
    if (safeMultiply(data))
    {
        printf("Result: %i * %i = %i\n", data->a, data->b, data->result);
    }
    else
    {
        printf("Error: %i * %i causes integer overflow!\n", data->a, data->b);
    }
}

void divideNumbers(CalcData* data)
{
    if (data->b != 0)
    {
        double res_double = (double)data->a / data->b;
        printf("Result: %i / %i = %.2f\n", data->a, data->b, res_double);
    }
    else
    {
        printf("Error: Division by zero is undefined!\n");
    }
}