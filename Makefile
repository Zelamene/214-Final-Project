CXX = g++
CXXFLAGS = -std=c++17 -I.

MAIN ?= DemoMain.cpp

# Output directory
TARGET_DIR = bin
TARGET = $(TARGET_DIR)/$(basename $(notdir $(MAIN)))

# Common sources (exclude main files and Catch)
COMMON_SRCS := $(filter-out DemoMain.cpp tests/UnitTests.cpp api/Api.cpp catch_amalgamated.cpp, $(wildcard *.cpp))

# Automatically include Catch only for tests
ifeq ($(MAIN),tests/UnitTests.cpp)
    SRCS = $(COMMON_SRCS) $(MAIN) catch_amalgamated.cpp
else
    SRCS = $(COMMON_SRCS) $(MAIN)
endif

OBJS = $(SRCS:.cpp=.o)

# Rules
all: $(TARGET)

# Ensure bin/ exists before building
$(TARGET): | $(TARGET_DIR)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

run: $(TARGET)
	./$(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(TARGET_DIR)



# Build demo

# make

# Build and run API

# make MAIN=api/Api.cpp
# make run MAIN=api/Api.cpp

# Build and run Unit Tests

# make MAIN=tests/UnitTests.cpp
# make run MAIN=tests/UnitTests.cpp

# Clean

# make clean