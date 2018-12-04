escritorPORT=/dev/ttyACM0
lectorPORT=/dev/ttyACM1
INCLUDES=-I./include -I./lib

# Directorios
INCLUDE=include
LIB=lib
OBJ=obj
SRC=src
BIN=bin
CC=g++-8

# Opciones del compilador
OPT=-O2 -std=c++17 -W -Wall

all: clean emisorPC

OBJECTS: code.o node.o 

emisorPC: node.o code.o bit.o emisorPC.o
	$(CC) -o $(BIN)/emisorPC $(OBJ)/emisorPC.o $(OBJ)/node.o $(OBJ)/code.o $(OBJ)/bit.o $(OPT)

emisorPC.o: $(SRC)/emisorPC.cpp $(INCLUDE)/code.h $(INCLUDE)/bit.h
	$(CC) -c -o $(OBJ)/emisorPC.o $(SRC)/emisorPC.cpp -I$(INCLUDE) $(OPT)

code.o: $(SRC)/code.cpp $(INCLUDE)/code.h $(INCLUDE)/node.h $(INCLUDE)/bit.h
	$(CC) -c -o $(OBJ)/code.o $(SRC)/code.cpp -I$(INCLUDE) $(OPT)

node.o: $(SRC)/node.cpp $(INCLUDE)/node.h
	$(CC) -c -o $(OBJ)/node.o $(SRC)/node.cpp -I$(INCLUDE) $(OPT)

bit.o: $(SRC)/bit.cpp $(INCLUDE)/bit.h
	$(CC) -c -o $(OBJ)/bit.o $(SRC)/bit.cpp -I$(INCLUDE) $(OPT)

clean:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*

exec:
	./bin/emisorPC
