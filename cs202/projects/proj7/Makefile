CXX = g++
CXX_FLAGS = -Wall -std=c++11

TARGET = proj6.out
HEADERS = Vehicle.h Car.h
SRCS = proj6.cpp Vehicle.cpp Car.cpp

OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))
# OBJECTS == proj6.o Vehicle.o Car.o

#Rule that states that default all and clean are make commands and not associated with any files
.PHONY: default all clean

#Rule that defers make all to the TARGET rule
all: $(TARGET)

#Rule to compile a single object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

#Rule that makes all object files in the OBJECTS list, then links them all together to produce TARGET executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

#Rule to clean up the build (removes iteratively all object files .o and the execitable TARGET)
clean:
	-rm -f *.o
	-rm -f $(TARGET)
	-rm -f $(TEST_TARGET)

#############
## TESTING ##
#############

TEST_TARGET = test.out
TEST_SRCS = test.cpp Vehicle.cpp Car.cpp
TEST_OBJECTS = $(patsubst %.cpp,%.o,$(TEST_SRCS))

testing: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(CXX_FLAGS) $(TEST_OBJECTS) $(LIBS) -o $@

