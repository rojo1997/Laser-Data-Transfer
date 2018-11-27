#include "ArduTIC.h"

// Constante de sincronización de tiempos de muestreo
const int U = 6 ;
// Tamaño del buffer de lectura
const int LENGTH = 32 ;

// Función para leer un bit del laser
char RecvBit (void) {

    digitalWrite(13,LOW) ;
    // Contador de pulsos
    int counter = 1 ;
    do {} while (digitalRead(8) == LOW) ;
    do {
        
        delay (U/3) ; 
        digitalWrite(13,LOW) ;
        if (digitalRead(8) == HIGH) {
          
          counter++ ;
          digitalWrite (13,HIGH);
        }

    } while (digitalRead(8) == HIGH) ;

    if (counter > 4) return (1) ;
    else return (0) ;
}

// Función para leer un byte del laser
char RecvByte (void) {

    char byte = 0 ;
    for (int i = 0 ; i < 8 ; i++)  byte |= (RecvBit() << i) ;
    return (byte) ;
}

// Función para leer N bytes del laser
int RecvNBytes (char * buffer, int N) {
  
    for (int i = 0 ; i < N ; i++) buffer[i] = RecvByte () ;
    return (N) ;
}

// Función para volcar buffer en PC N bytes
int DumpBuffer (char * buffer, int N) {
  
    // Colocamos \n y enviamos y marcamos ocupacion 0
    buffer[N] = '\n' ;
    // Enviamos a PC
    Serial.println (buffer) ;
    // Limpiamos buffer
    for (int k = 0 ; k < LENGTH ; k++) buffer[k] = 0 ;
    return (N) ;
}

// Función min(i,j)
int min (int i, int j) {
  
    if (i < j) return (i) ;
    else return (j) ;
}

int main (void) {

    // Marcamos la frecuencia
    Serial.begin (9600) ;
    // Establecemos los pines
    pinMode (8,INPUT) ; pinMode (13,OUTPUT) ;
    // Iniciamos la luz apagada
    digitalWrite (13,LOW) ;

    // Buffer de datos inicializado a 0
    char buffer [LENGTH] = {0} ;

    while (1) {

        digitalWrite(13,HIGH) ;

        if (Serial.available()) {

            digitalWrite(13,LOW) ;
            char size = RecvByte() ;
            Serial.println(&size) ;

            // Numero de bytes a recibir
            int i = ceil (size / 8.0) ;

            while (i > 0) {
                
                i -= DumpBuffer (buffer, RecvNBytes (buffer, min (i, LENGTH - 1))) ;
            }
        
        } else {

            delay(U);
        } 
    }    

    return (0) ;
}
