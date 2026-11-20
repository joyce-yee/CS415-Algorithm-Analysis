CXX = c++
CXXFLAGS = -g -std=c++20 -Wall -Wextra -Wpedantic
TARGET = main.x
OBJECTS = greed.o dynamic.o main.o

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

greed.o: greed.cpp greed.hpp
dynamic.o: dynamic.cpp dynamic.hpp
main.o: main.cpp greed.hpp dynamic.hpp

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TARGET)	 data/out*
