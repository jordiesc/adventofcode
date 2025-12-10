# Makefile for C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

# Source directory
SRC_DIR = src

# Source files (all .cpp files in src/)
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files (corresponding .o files)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=%.o)

# Executable name
TARGET = main

# Default target
.PHONY: all run clean

all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files
%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) *.o $(SRC_DIR)/*.o

# Rebuild everything
rebuild: clean all

# Print variables for debugging
print-%:
	@echo $* = $($*)
