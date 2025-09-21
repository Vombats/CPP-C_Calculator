# Calculator Project

## Project Description

A robust hybrid C/C++ calculator application featuring modular architecture and comprehensive input validation. This project demonstrates professional programming practices including:

- **Hybrid Architecture**: C++ main function calling C-style modules (excellent example of language interoperability)
- **Modular Design**: Separated into logical components (main, input validation, arithmetic operations, calculator logic)
- **Input Validation**: Strict integer input validation with overflow protection
- **Error Handling**: Safe arithmetic operations with overflow detection for addition and multiplication
- **Cross-Platform**: Runs on Linux, Windows, and macOS
- **Professional Build System**: Makefile with automatic cleanup and Visual Studio project files

### Features

- Interactive calculator with menu-driven interface using modern C++ I/O streams
- Square, addition, subtraction, multiplication, and division operations
- **Complete geometry module**: Rectangle, circle, and triangle area calculations
- **Rectangle area calculation** with C++ style I/O
- **Circle area calculation** with precise floating-point arithmetic
- **Triangle area calculation** with (base × height) ÷ 2 formula
- **Clean user interface** with automatic screen clearing between operations
- Integer overflow protection using mathematical bounds checking
- Robust input validation rejecting non-numeric input (C++ std::cin with C-style validation)
- Memory-safe implementation using standard C/C++ libraries
- Zero-warning compilation with strict compiler flags
- **Language Mixing**: Demonstrates seamless integration of C++ and C code

### Project Structure

```text
├── .vscode/
│   └── tasks.json             # VS Code build tasks configuration
├── main.cpp                   # Program entry point (C++ style)
├── input_validation.cpp       # Input validation and overflow detection (C style)
├── arithmetic.cpp             # Safe arithmetic operations (C style)
├── calculator.cpp             # Calculator logic and display (C style)
├── geometry.cpp               # Geometry calculations (C++ style)
├── utilities.cpp              # Utility functions (cross-platform)
├── input_output.h             # Header with function declarations
├── Makefile                   # Cross-platform build system
├── Calculator.sln             # Visual Studio solution file
├── Calculator.vcxproj         # Visual Studio project file (C++14)
├── Calculator_Compatible.vcxproj # Visual Studio project file (compatible)
└── README.md                  # This documentation
```

### Architecture: Hybrid C/C++ Design

This project demonstrates **seamless integration** of C and C++ code:

#### **C++ Components:**

- **`main.cpp`**: Modern C++ with `std::cout`, `std::cin`, stream error handling
- **`geometry.cpp`**: C++ style geometry calculations with stream I/O
- **`utilities.cpp`**: Cross-platform utility functions (screen clearing)
- **Language Features**: `true`/`false`, stream chaining, automatic type deduction

#### **C Components:**

- **`input_validation.cpp`**: C-style `scanf`/`printf` with robust validation
- **`arithmetic.cpp`**: Pure C arithmetic with overflow protection
- **`calculator.cpp`**: C-style functions with `printf` output

#### **Interoperability:**

- **Function Calls**: C++ main calls C functions seamlessly
- **Data Structures**: Shared `CalcData` struct works in both languages
- **Compilation**: Single g++ command compiles mixed C/C++ codebase
- **Linking**: Automatic linkage between C and C++ object files

This design shows how to **modernize legacy C code** by replacing just the user interface while keeping proven algorithms intact.

## Running on Linux/Unix

### Method 1: Make (Recommended)

```bash
# Build the project
make

# Run the calculator
./calculator

# Clean build files
make clean

# Build and run in one step
make run
```

### Method 2: Direct Compilation

```bash
# Compile all source files
g++ -Wall -Wextra -Werror -std=c++11 -g -o calculator main.cpp input_validation.cpp arithmetic.cpp calculator.cpp

# Run the calculator
./calculator
```

### Method 3: VS Code Integration

- Open the project folder in VS Code
- Use `Ctrl+Shift+P` → "Tasks: Run Task"
- Select "Build Calculator (Makefile)" or "Build and Run Calculator"

## Running on Windows

### Method 1: Visual Studio (Recommended)

1. Open `Calculator.sln` in Visual Studio
2. Press `F5` or click "Debug > Start Debugging"
3. Or press `Ctrl+F5` for "Start Without Debugging"

**Note**: If you encounter C++ language standard errors, try:

- Use `Calculator_Compatible.vcxproj` instead (no language standard specified)
- Or manually set C++ Language Standard in Project Properties → C/C++ → Language → C++ Language Standard to "ISO C++14 Standard" or "Default"

### Method 2: MinGW/MSYS2 with Make

1. Install [MSYS2](https://www.msys2.org/)
2. Open MSYS2 terminal
3. Install build tools: `pacman -S mingw-w64-x86_64-gcc make`
4. Navigate to project directory
5. Run: `make`
6. Execute: `./calculator.exe`

### Method 3: Command Line (Windows)

```cmd
g++ -Wall -Wextra -std=c++11 -o calculator.exe main.cpp input_validation.cpp arithmetic.cpp calculator.cpp
calculator.exe
```

## Compatibility Features

✅ **Cross-platform Makefile** - Detects Windows/Unix automatically
✅ **Visual Studio project files** - Ready for VS 2019/2022
✅ **Standard C++ code** - No platform-specific dependencies
✅ **Portable libraries** - Uses only standard C/C++ headers

## Build Options

| Platform | Tool | Command | Notes |
|----------|------|---------|--------|
| Linux/Mac | Make | `make` | Recommended method |
| Linux/Mac | Direct | `g++ *.cpp -o calculator` | Quick compilation |
| Linux/Mac | VS Code | Use integrated tasks | IDE integration |
| Windows | Make (MSYS2) | `make` | Requires MSYS2 setup |
| Windows | Visual Studio | Open `.sln` file | Full IDE experience |
| Windows | Command Line | `g++ *.cpp -o calculator.exe` | MinGW required |

## Development

### Requirements

- **C++ Compiler**: g++ with C++11 support or Visual Studio 2019+
- **Build Tools**: Make (Linux/Mac) or Visual Studio (Windows)
- **Standards**: C++11, POSIX-compatible where applicable

### Compiler Flags Used

- `-Wall -Wextra`: Enable comprehensive warnings
- `-Werror`: Treat warnings as errors (zero-warning policy)
- `-std=c++11`: Use C++11 standard
- `-g`: Include debugging information

### Testing

The calculator has been tested with:

- Valid integer inputs within INT_MAX/INT_MIN bounds
- Invalid inputs (letters, symbols, mixed alphanumeric)
- Edge cases (division by zero, integer overflow scenarios)
- Cross-platform compilation on Linux and Windows

## Example Usage

```text
=== Calculator Menu ===
1. Square a number
2. Add two numbers
3. Subtract two numbers
4. Multiply two numbers
5. Divide two numbers
6. Rectangle area
7. Circle area
8. Exit
Enter your choice (1-8): 2

Enter the first number: 15
Enter the second number: 25
Result: 15 + 25 = 40

=== Calculator Menu ===
1. Square a number
2. Add two numbers
3. Subtract two numbers
4. Multiply two numbers
5. Divide two numbers
6. Rectangle area
7. Circle area
8. Exit
Enter your choice (1-8): 7

Circle radius (cm) -> 7
Area of the circle is 153.9380 sq.cm
```

## Troubleshooting

### Visual Studio Build Errors

**Problem**: "Language standard not supported" or similar C++ standard errors
**Solutions**:

1. Use `Calculator_Compatible.vcxproj` instead of `Calculator.vcxproj`
2. Manually set C++ Language Standard:
   - Right-click project → Properties
   - C/C++ → Language → C++ Language Standard
   - Select "ISO C++14 Standard" or "Default"

**Problem**: "'scanf': This function or variable may be unsafe. Consider using scanf_s instead"
**Solution**: This is already fixed in both project files with `_CRT_SECURE_NO_WARNINGS` preprocessor definition. If you still see this:

- Right-click project → Properties
- C/C++ → Preprocessor → Preprocessor Definitions
- Add `_CRT_SECURE_NO_WARNINGS` to the list

**Problem**: "Cannot find stdio.h" or similar header errors
**Solution**: Ensure you're building as a Console Application, not Windows Application

### Linux/Mac Build Errors

**Problem**: `make: command not found`
**Solution**: Install build tools

- Ubuntu/Debian: `sudo apt install build-essential`
- CentOS/RHEL: `sudo yum install gcc-c++ make`
- macOS: Install Xcode Command Line Tools

**Problem**: Permission denied when running `./calculator`
**Solution**: `chmod +x calculator`
