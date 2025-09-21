#include "input_output.h"

int readInteger(int *value)
{
    char input[12]; // Enough for INT_MIN with null terminator
    char overflow_check;
    int i;
    
    if (scanf("%11s", input) != 1)
    {
        printf("Invalid input!\n");
        exit(1);
    }
    
    // Check if there are more characters (input too long)
    if (scanf("%c", &overflow_check) == 1 && overflow_check != '\n')
    {
        printf("Invalid input!\n");
        exit(1);
    }
    
    // Check if input contains only digits (and optional leading minus)
    i = 0;
    if (input[0] == '-')
        i = 1;
    
    while (input[i])
    {
        if (input[i] < '0' || input[i] > '9')
        {
            printf("Invalid input!\n");
            exit(1);
        }
        i++;
    }
    
    // Quick length-based overflow check first
    int len = i; // i is now at the end of the string
    
    // Check for obvious overflow based on length
    if (len > 10 || (len == 10 && input[0] != '-') || 
        (len == 11 && input[0] == '-' && input[1] > '2'))
    {
        printf("Invalid input!\n");
        exit(1);
    }
    
    // For 10-digit positive numbers, check if first digit > 2
    if (len == 10 && input[0] > '2')
    {
        printf("Invalid input!\n");
        exit(1);
    }
    
    // For 11-char negative numbers starting with -2, need detailed check
    if (len == 11 && input[0] == '-' && input[1] == '2')
    {
        // Check against INT_MIN: -2147483648
        char int_min_str[] = "2147483648";
        int j;
        for (j = 1; j < 11; j++)
        {
            if (input[j] > int_min_str[j-1])
            {
                printf("Invalid input!\n");
                exit(1);
            }
            if (input[j] < int_min_str[j-1])
                break; // Definitely smaller, safe
        }
    }
    
    // For 10-digit positive numbers starting with 2, check against INT_MAX
    if (len == 10 && input[0] == '2')
    {
        // Check against INT_MAX: 2147483647
        char int_max_str[] = "147483647";
        int j;
        for (j = 1; j < 10; j++)
        {
            if (input[j] > int_max_str[j-1])
            {
                printf("Invalid input!\n");
                exit(1);
            }
            if (input[j] < int_max_str[j-1])
                break; // Definitely smaller, safe
        }
    }
    
    // Convert string to integer manually (since we know it's valid)
    *value = 0;
    i = 0;
    int sign = 1;
    if (input[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    
    while (input[i])
    {
        *value = *value * 10 + (input[i] - '0');
        i++;
    }
    *value *= sign;
    
    return 1;
}