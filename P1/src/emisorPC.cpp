#include <cmath>
#include <ctype.h>
#include <locale>
#include <iostream>
#include <stdio.h>
#include <string>

#include "bit.h"
#include "PCSerialUSB.h"

using namespace std ;

// CONSTANTES
const int TAM = 512 ;
const string PUERTO = "/dev/ttyACM0" ;

int main (void) {

    // Cadena de lectura
    string cadena = "" ;

    // Cadena de bytes codificados
    unsigned char array [TAM] ;
    for (int i = 0 ; i < TAM ; i++) array[i] = 0 ;

    // Numero de bytes a enviar
    int size ;
    unsigned char size_codified ;

    // Apertura del canal
    int fd = InicializarUSB (PUERTO.c_str()) ;
    if (fd < 0) {

        cout << "ERROR: No hay conexion con USB." << endl ;
        return (0) ;
    }

    do {

        // Lectura del mensaje
        cout << "Introduzca el mensaje: " ;
        std::getline(std::cin,cadena) ; cout << endl ;

        if (cadena != "exit") {

            // Codificación del mensaje y añadir \0 que devuelve el número
            // bits de la codificación.
            size = codifica (cadena, array) ;

            int s = ceil (size / 8.0);

            cout << "Numero de bits necesarios: " << size << endl ;
            cout << "Numero de bytes necesarios: " << s << endl ;
            cout << "Numero de bits sobrantes: " << s * 8 - size << endl ;
            cout << "Numero de bytes con BARRA0: " << s + 1 << endl ;
            cout << endl << endl ;
            cout << "Cadena sin codificar decimal (8): " ; print_string (cadena) ;
            cout << "Cadena codificada decimal (8): " ; printstr8 (array, s) ;
            cout << "Cadena codificada decimal (5): " ; printstr5 (cadena) ;

            cadena = descodifica (array, size) ;

            cout << "Cadena descodificada: " << cadena << endl ;

            // Envio del tamaño del mensaje
            size_codified = size ;
            cout << "char size: " << +size_codified << endl ;

            cout << endl << endl ;
            // Check envío y recepción del tamaño del mensaje correctos
            if (sendByteUSB (fd, size_codified)) {

                cout << "PC - Tamaño del mensaje enviado. \n";
            }
            // Esperar a que Arduino reciba el tamaño y mostrarlo por pantalla
            size_codified = 0 ;
            if (receiveByteUSB (fd, size_codified)) {


                cout << "Arduino - Tamaño del mensaje recibido: " << +size_codified << endl;
            }
            // Check envío y recepción del mensaje correctos
            if (sendUSB (fd, (char *) array)) {

                cout << "PC - Mensaje enviado. \n";
            }
            // Esperar a que Arduino reciba el mensaje y mostrarlo por pantalla
            if (receiveUSB (fd, (char *) array)) {

                cadena = descodifica (array, size) ;
                cout << "Arduino - Mensaje recibido: " << cadena << endl;
            }
            cout << endl << "================================================" << endl << endl;
        }

    } while (cadena != "exit") ;

    CerrarUSB(fd) ;

    return (0) ;
}
