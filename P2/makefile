escritorPORT=/dev/ttyACM0
lectorPORT=/dev/ttyACM1
INCLUDES=-I./include -I./lib
INCLUDE=./include
LIB=./lib
OBJ=./obj
SRC=./src
BIN=./bin

all: clean emisorPC

emisorPC:
	g++ -o $(BIN)/emisorPC $(SRC)/emisorPC.cpp -O2 -std=c++17

clean:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*

exec:
	./bin/emisorPC
