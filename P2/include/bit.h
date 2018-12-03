#ifndef BIT
#define BIT

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>

using namespace std ;

/*  CLASE BIT
    Clase preparada para almacenar y gestinar un número de bits preestablecido.
*/
class Bits {
    private:
        int size;
        unsigned char * array;

    public:
        // Constructor vacio
        Bits (void) ;
        // Constructor sobre el numero de bits
        Bits (int i) ;
        // Constructor por puntero y numero de bits
        Bits (unsigned char * a, int b) ;
        // Insertar la posicion a el valor value
        void insert (int a, unsigned char value) ;
        // Obtener el valor de la posicion a
        unsigned char get (int a) ;
        // Numero de bits en el vector
        int length (void) ;
        // Obtener el puntero del array
        unsigned char * getarray (void) ;
};

int codifica (string cadena, unsigned char * array) ;
string descodifica (unsigned char * array, int size) ;
void printstr8 (unsigned char * cad, int size) ;
void printstr5 (string cad) ;
void print_string (string cad) ;

#endif
