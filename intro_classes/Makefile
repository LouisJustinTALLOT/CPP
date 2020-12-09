CXX=g++
CXXFLAGS=-Wall -Iinclude

all: classe_integer classe_intstack corr_integer

classe_integer : 
	classe_integer.cpp

classe_intstack :
	classe_intstack.cpp

corr_integer : 
	integer_bounds.cpp Integer_correction.cpp Integer.h

clean :
	rm classe_integer
	rm classe_intstack
	rm corr_integer