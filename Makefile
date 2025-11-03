CXX = g++
CXXFLAGS = -std=c++17 -I.

SRCS := $(filter-out DemoMain.cpp, $(wildcard *.cpp))
SRCS += tests/UnitTests.cpp catch_amalgamated.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = nursery_test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(TARGET)
	./$(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
