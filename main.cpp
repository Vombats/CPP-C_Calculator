#include "input_output.h"

int main()
{
    int choice;
    CalcData data;

    while (true)  // C++ style: true instead of 1
    {
        // C++ style output with std::cout and stream chaining
        std::cout << "\n=== Calculator Menu ===\n"
                  << "1. Square a number\n"
                  << "2. Add two numbers\n"
                  << "3. Subtract two numbers\n"
                  << "4. Multiply two numbers\n"
                  << "5. Divide two numbers\n"
                  << "6. Exit\n"
                  << "Enter your choice (1-6): ";
        
        // C++ style input with error handling
        if (!(std::cin >> choice) || choice < 1 || choice > 6)
        {
            std::cout << "Invalid choice! Please enter a number between 1 and 6.\n";
            
            // C++ style input stream error recovery
            std::cin.clear();  // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
            continue;
        }

        // Exit option
        if (choice == 6)
        {
            std::cout << "Thank you for using the calculator!\n";
            break;
        }

        // Get input based on operation
        if (choice == 1)
        {
            std::cout << "\nEnter the number: ";
            readInteger(&data.a);  // Call C-style function from C++ main
            squareNumber(&data);   // Call C-style function from C++ main
        }
        else
        {
            std::cout << "\nEnter the first number: ";
            readInteger(&data.a);  // C function called from C++ code
            std::cout << "Enter the second number: ";
            readInteger(&data.b);  // C function called from C++ code

            // C++ style switch with C function calls
            switch (choice)
            {
                case 2:
                    addNumbers(&data);      // C function
                    break;
                case 3:
                    subtractNumbers(&data); // C function
                    break;
                case 4:
                    multiplyNumbers(&data); // C function
                    break;
                case 5:
                    divideNumbers(&data);   // C function
                    break;
            }
        }
    }

    return 0;
}