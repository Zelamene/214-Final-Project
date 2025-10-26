# Compiler and flags
CC = g++
CFLAGS = -std=c++11 -Wall -Werror -Werror=sign-compare -Werror=delete-non-virtual-dtor \
         -g -O1 -fsanitize=address,undefined -MMD -MP
LFLAGS = -fsanitize=address,undefined

# Target executable
TARGET = nursery_test

# Source files (updated to remove species-specific care classes)
SOURCES = main.cpp \
          Customer.cpp Order.cpp Staff.cpp Invoker.cpp \
          PrepareCommand.cpp PackageOrderCommand.cpp DeliverOrderCommand.cpp \
          WaterPlantCommand.cpp FertilizeBedCommand.cpp \
          Aloe.cpp Baobab.cpp CherryBlossom.cpp Rose.cpp \
          Tree.cpp FloweringPlant.cpp NurseryPlant.cpp CareStrategy.cpp \
          HighMaintenancePlantCare.cpp LowMaintenancePlantCare.cpp \
          HighMaintenanceTreeCare.cpp LowMaintenanceTreeCare.cpp \
          Aloe.cpp AloeCare.cpp Baobab.cpp BaobabCare.cpp \
          CherryBlossom.cpp CherryCare.cpp Rose.cpp RoseCare.cpp \
          Tree.cpp FloweringPlant.cpp NurseryPlant.cpp CareStrategy.cpp \
          CashierHandler.cpp ManagerHandler.cpp DisputeHandler.cpp Issue.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link objects
$(TARGET): $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(TARGET)

# Generic compilation rule
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Include dependency files if they exist
-include $(OBJECTS:.o=.d)

# Clean build files
clean:
	rm -f $(TARGET) $(OBJECTS) $(OBJECTS:.o=.d) *~

# Run program
run: $(TARGET)
	./$(TARGET)

# Debug target
debug: CFLAGS += -DDEBUG -g3
debug: $(TARGET)

# Release target
release: CFLAGS = -std=c++11 -O3 -DNDEBUG
release: LFLAGS =
release: $(TARGET)

# Test individual patterns
test-strategy: $(TARGET)
	./$(TARGET) | grep -A 100 "TESTING STRATEGY PATTERN"

test-command: $(TARGET)
	./$(TARGET) | grep -A 100 "TESTING COMMAND PATTERN"

test-cor: $(TARGET)
	./$(TARGET) | grep -A 100 "TESTING CHAIN OF RESPONSIBILITY"
