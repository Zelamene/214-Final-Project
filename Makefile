# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -I.

# Source files for tests
SRC = $(filter-out DemoMain.cpp, $(wildcard *.cpp))
TEST_SRC = tests/UnitTests.cpp catch_amalgamated.cpp

# Test executable
TEST_TARGET = nursery_test

# Default target: compile tests
all: $(TEST_TARGET)

# Compile unit tests
$(TEST_TARGET): $(SRC) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST_SRC) -o $(TEST_TARGET)

# Run unit tests
run: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean build artifacts
clean:
	rm -f $(TEST_TARGET)
