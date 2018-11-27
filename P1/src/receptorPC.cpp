#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>

#include "bit.h"
#include "PCSerialUSB.h"

using namespace std ;

// CONSTANTES
const int TAM = 512 ;
// TAM BUFFER ARDU
const int LENGTH = 32 ;
const string PUERTO = "/dev/ttyACM1" ;

int main (void) {

    string cadena = "" ;
    char array [TAM] = {0} ;
    char size ;

    int fd = InicializarUSB (PUERTO.c_str()) ;
    if (fd < 0) {

        cout << "ERROR: No hay conexion con USB." << endl ;
        return (0) ;
    }

    char a[1] ; a[0] = 'a' ;
    if (sendUSB (fd, a)) {

        cout << "Esperando señal..." << endl ;
    }

    char array_size[2] ;
    if (receiveUSB(fd, array_size)) {

        size = array_size[0] ;
        cout << "Tamaño del mensaje: " << +array_size[0] << endl ;
    }

    if (receiveUSB (fd, array)) {
            
        cout << "Cadena codificada decimal (8): " ;
        for (int i = 0 ; i < ceil (size / 8.0) ; i++) {

            cout << +(unsigned char)array[i] << " " ;
        }
        cout << endl << "Mensaje recibido: " << descodifica((unsigned char*) array, (int) size) << endl ;
    }

    CerrarUSB(fd) ;

    return (0) ;
}
