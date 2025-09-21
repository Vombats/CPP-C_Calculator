# Compiler settings
ifeq ($(OS),Windows_NT)
    # Windows settings
    CC = g++
    CFLAGS = -Wall -Wextra -Werror -std=c++11 -g
    TARGET = calculator.exe
    RM = del
    PATHSEP = \\
else
    # Unix/Linux settings
    CC = g++
    CFLAGS = -Wall -Wextra -Werror -std=c++11 -g
    TARGET = calculator
    RM = rm -f
    PATHSEP = /
endif

HEADER = input_output.h

# Source files
SOURCES = main.cpp input_validation.cpp arithmetic.cpp calculator.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "Build successful! Cleaning up object files..."
	@rm -f $(OBJECTS)
	@echo "Object files cleaned."

# Compile source files to object files
%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
ifeq ($(OS),Windows_NT)
	if exist *.o del *.o
	if exist $(TARGET) del $(TARGET)
else
	$(RM) *.o $(TARGET)
endif

# Rebuild everything
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug version with additional flags
debug: CFLAGS += -DDEBUG -O0
debug: $(TARGET)

# Release version with optimization
release: CFLAGS += -O2 -DNDEBUG
release: $(TARGET)

# Install (copy to /usr/local/bin)
install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  clean    - Remove build files"
	@echo "  rebuild  - Clean and build"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build debug version"
	@echo "  release  - Build optimized release version"
	@echo "  install  - Install to system"
	@echo "  uninstall- Remove from system"
	@echo "  help     - Show this help"

# Declare phony targets
.PHONY: all clean rebuild run debug release install uninstall help