#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

TEACHER_SOURCES := Demo.cpp TestCounter.cpp Test.cpp
HEADERS := $(wildcard *.h*)
STUDENT_SOURCES := $(filter-out $(TEACHER_SOURCES), $(wildcard *.cpp))
STUDENT_OBJECTS := $(subst .cpp,.o,$(STUDENT_SOURCES))

run: demo
	./$^

demo: Demo.o $(STUDENT_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(STUDENT_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test
