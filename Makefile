#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS=$(wildcard *.h*)
# SOURCES=$(wildcard *.cpp)
SOURCES=FamilyTree.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

run: demo
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test
