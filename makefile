#Tyler Forrester
#Makefile for Lab H InputValid,  WriteFile
#Aug 11, 2016
CXX =  g++ -g
OBJSL2 = main.o
SRCSL2 = main.cpp

OBJSL3 = InputValid.o
SRCSL3 = InputValid.cpp
HEAD3 = InputValid.hpp

OBJSL5 = WriteFile.o
SRCSL5 = WriteFile.cpp
HEAD5 = WriteFile.hpp

OBJSL6 = Sort.o
SRCSL6 = Sort.cpp
HEAD6 = Sort.hpp

OBJSL7 = Dice.o
SRCSL7 = Dice.cpp
HEAD7 = Dice.h

PROG = LabH
#PROGT = Test

all: $(PROG) 

$(PROG): $(OBJSL2) $(OBJSL3) $(OBJSL5) $(OBJSL6) $(OBJSL7) $(HEAD3) $(HEAD5) $(HEAD6) $(HEAD7) 
	$(CXX) $(OBJSL2) $(OBJSL3) $(OBJSL5) $(OBJSL6) $(OBJSL7) -o $(PROG)
$(OBJSL2): $(SRCSL2)
	$(CXX) -c $(SRCSL2)
$(OBJSL3): $(SRCSL3) $(HEAD3)
	$(CXX) -c $(SRCSL3)
$(OBJSL4): $(SRCSL4) $(HEAD4)
	$(CXX) -c $(SRCSL4)
$(OBJSL5): $(SRCSL5) $(HEAD5)
	$(CXX) -c $(SRCSL5)
$(OBJSL6): $(SRCSL6) $(HEAD6)
	$(CXX) -c $(SRCSL6)
$(OBJSL7): $(SRCSL7) $(HEAD7)
	$(CXX) -c $(SRCSL7)
$(OBJSL8): $(SRCSL8) $(HEAD8)
	$(CXX) -c $(SRCSL8)
$(OBJSL9): $(SRCSL9) $(HEAD9)
	$(CXX) -c $(SRCSL9)

clean:
	rm -rf $(PROG) *.o *~
