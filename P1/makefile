escritorPORT=/dev/ttyACM0
lectorPORT=/dev/ttyACM1
INCLUDES=-I./include -I./lib
INCLUDE=./include
LIB=./lib
OBJ=./obj
SRC=./src
BIN=./bin

all: receptorPC receptorArdu sendreceptorArdu emisorPC emisorArdu sendemisorArdu exec

emisorPC:
	g++ -o $(BIN)/emisorPC $(SRC)/emisorPC.cpp $(SRC)/bit.cpp $(LIB)/PCSerialUSB.cpp $(INCLUDES)

emisorArdu:
	avr-gcc -Os -mmcu=atmega328p -c -o $(OBJ)/emisorArdu.o $(SRC)/emisorArdu.cpp $(INCLUDES)
	avr-gcc -Os -mmcu=atmega328p $(OBJ)/emisorArdu.o $(INCLUDES) -lm -lArduTIC -L$(LIB) -o $(OBJ)/emisorArdu.bin
	avr-objcopy -O ihex -R .eeprom $(OBJ)/emisorArdu.bin $(BIN)/emisorArdu.hex

sendemisorArdu:
	avrdude -F -V -c arduino -p ATMEGA328p -P $(escritorPORT) -b 115200 -U flash:w:$(BIN)/emisorArdu.hex

receptorPC:
	g++ -o $(BIN)/receptorPC $(SRC)/receptorPC.cpp $(SRC)/bit.cpp $(LIB)/PCSerialUSB.cpp $(INCLUDES)

receptorArdu:
	avr-gcc -Os -mmcu=atmega328p -c -o $(OBJ)/receptorArdu.o $(SRC)/receptorArdu.cpp $(INCLUDES)
	avr-gcc -Os -mmcu=atmega328p $(OBJ)/receptorArdu.o $(INCLUDES) -lm -lArduTIC -L$(LIB) -o $(OBJ)/receptorArdu.bin
	avr-objcopy -O ihex -R .eeprom $(OBJ)/receptorArdu.bin $(BIN)/receptorArdu.hex

sendreceptorArdu:
	avrdude -F -V -c arduino -p ATMEGA328p -P $(lectorPORT) -b 115200 -U flash:w:$(BIN)/receptorArdu.hex

clean:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*

exec:
	./bin/receptorPC