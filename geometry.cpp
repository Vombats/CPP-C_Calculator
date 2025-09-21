#include "input_output.h"

void calculateRectangleArea(CalcData* data)
{
    // C++ style output for rectangle area calculation
    std::cout << "\nRectangle width (cm) -> ";
    readInteger(&data->a);  // Use existing C-style validation for robustness
    
    std::cout << "Rectangle height (cm) -> ";
    readInteger(&data->b);  // Use existing C-style validation for robustness
    
    // Calculate area using existing safe multiplication
    if (safeMultiply(data))
    {
        std::cout << "Area of the rectangle is " << data->result << " sq.cm" << std::endl;
    }
    else
    {
        std::cout << "Error: Rectangle dimensions cause integer overflow!" << std::endl;
    }
}

void calculateCircleArea(CalcData* data)
{
    // C++ style output for circle area calculation
    std::cout << "\nCircle radius (cm) -> ";
    readInteger(&data->a);  // Use existing C-style validation for robustness
    
    // Calculate area using π * r²
    // Using double for precise floating-point calculation
    double radius = static_cast<double>(data->a);
    double area = 3.141592653589793 * radius * radius;  // π * r²
    
    std::cout << "Area of the circle is " << std::fixed << std::setprecision(4) 
              << area << " sq.cm" << std::endl;
}

void calculateTriangleArea(CalcData* data)
{
    // C++ style output for triangle area calculation
    std::cout << "\nEnter base of a triangle: ";
    readInteger(&data->a);  // Use existing C-style validation for robustness
    
    std::cout << "Enter height of a triangle: ";
    readInteger(&data->b);  // Use existing C-style validation for robustness
    
    // Calculate area using (base * height) / 2
    // Using double for precise floating-point calculation
    double base = static_cast<double>(data->a);
    double height = static_cast<double>(data->b);
    double area = (base * height) / 2.0;
    
    std::cout << "Area of the triangle is " << std::fixed << std::setprecision(7) 
              << area << " sq.cm" << std::endl;
}