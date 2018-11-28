escritorPORT=/dev/ttyACM0
lectorPORT=/dev/ttyACM1
INCLUDES=-I./include -I./lib
INCLUDE=include
LIB=lib
OBJ=obj
SRC=src
BIN=bin
OPT=-O2 -std=c++17

all: clean emisorPC

emisorPC: $(OBJ)/emisorPC.o $(OBJ)/code.o
	g++ -o $(BIN)/emisorPC $(OBJ)/emisorPC.o $(OBJ)/code.o $(OPT)

$(OBJ)/emisorPC.o: $(SRC)/emisorPC.cpp $(INCLUDE)/code.h
	g++ -c -o $(OBJ)/emisorPC.o $(SRC)/emisorPC.cpp -I$(INCLUDE) $(OPT)

$(OBJ)/code.o: $(SRC)/code.cpp $(INCLUDE)/node.h
	g++ -c -o $(OBJ)/code.o $(SRC)/code.cpp -I$(INCLUDE) $(OPT)

$(OBJ)/node.o: $(SRC)/node.cpp
	g++ -c -o $(OBJ)/node.o $(SRC)/node.cpp $(OPT)

clean:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*

exec:
	./bin/emisorPC
