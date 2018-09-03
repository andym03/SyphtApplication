# *****************************************************
# Variables to control Makefile operation

CXX = g++-7
CXXFLAGS = -Wall

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o
	$(CXX) $(CXXFLAGS) -o sypht main.o node.h

# The main.o target

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp