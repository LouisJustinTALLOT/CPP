CXX = g++
CXXFLAGS = -Wall 

all: recap tableaux_1 str statements fonc segfault NPI

recap: recap.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

tableaux_1: tableaux_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

str : str.cpp

statements : statements.cpp

fonc : fonc.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
segfault : segfault.cpp 
NPI : NPI.cpp
clean:
	rm recap
	rm tableaux_1
	rm str
	rm statements
	rm NPI
	rm fonc
	rm segfault