TARGET = storesim
LIBS = -lm #Math Library, just a placeholder
HEADERS = Queue.h QueueArray.h config.h
SRCS = storesim.cpp QueueArray.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))
CXX = g++
CXX_FLAGS = -Wall -std=c++14

.PHONY: default all clean

all: depend $(TARGET)

#Rules to recompile template headers when they change
depend: .depend
.depend: $(HEADERS)
	rm -f ./.depend
	$(CXX) $(CXX_FLAGS) -MM $^ > ./.depend;
include .depend

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f ./.depend
	-rm -f $(TARGET)
	-rm -f test

test:
	g++ -Wall -std=c++14 -c test7.cpp -o test7.o
	g++ -Wall -std=c++14 -c QueueArray.cpp -o QueueArray.o
	g++ -Wall -std=c++14 test7.o QueueArray.o -lm  -o test