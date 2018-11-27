#include "ArduTIC.h"

// CONSTANTES
const int U = 6 ;
const int TAM = 512 ;

void sendBit (char bit) {

    digitalWrite(8,HIGH) ;
    digitalWrite(12,HIGH) ;
    if (bit == 0) {

        delay(U) ;
        digitalWrite(8,LOW) ;
    
    } else if (bit == 1) {

        delay(U*2) ;
    }
    digitalWrite(12,LOW) ;
    digitalWrite(8,LOW) ;
    delay(U) ;
}

void sendByte (char byte) {

    for (int i = 0 ; i < 8 ; i++) {
    
        int mask = byte & (1 << i) ;
        mask = mask >> i ;
        sendBit (mask) ;
    }
}

void sendNBytes (char * buffer, int N) {
    
    for (int i = 0 ; i < N ; i++) {

        sendByte (buffer[i]) ;
    }
}

int main (void) {

    // Inicializar puerto serie a 9600 baudios
    Serial.begin(9600) ;
    // Configurar pines de entrada y salida
    pinMode(8,OUTPUT) ; pinMode(12,OUTPUT) ;
    // Inicializar pines
    digitalWrite(12,LOW) ; digitalWrite(8,LOW) ;
    
    // BUFFER
    char buffer [TAM] ;

    // Tamaño del mensaje
    unsigned char size;

    while (1) {

        // Si hay datos disponibles
        if (Serial.available()) {

            // Leer tamaño desde PC
            size = Serial.read() ;
            // Devolver tamaño al PC
            Serial.print(size - 48) ;
            // Enviar el tamaño al otro Arduino
            sendByte (size) ;

            // Leer mensaje desde PC
            Serial.readString(buffer) ;
            // Devolver mensaje a PC
            Serial.print(buffer) ;
            // Enviar el mensaje al otro Arduino
            sendNBytes (buffer, ceil (size / 8.0)) ;

        // En otro caso, esperar U
        } else {
        
            delay(U) ;
        }
    }
}
