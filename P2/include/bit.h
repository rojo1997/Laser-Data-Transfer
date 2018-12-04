#ifndef BIT
#define BIT

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>

using namespace std ;

/*  CLASE BIT
    Clase preparada para almacenar y gestinar un número de bits.
*/
class Bits {
    private:
        unsigned int size = 0 ;
        unsigned int max = 0 ;
        unsigned char * array ;

    public:
        // Constructor vacio
        Bits (void) ;
        // Constructor sobre el numero de bits teniendo en cuenta el \n
        Bits (int i) ;
        // Constructor por puntero y numero de bits
        Bits (unsigned char * a, int b) ;
        // Insertar la posicion a el valor value
        void insert (int a, unsigned char value) ;
        // Obtener el valor de la posicion a
        unsigned char get (int a) const ;
        // Numero de bits en el vector
        unsigned int length (void) const ;
        // Obtener el puntero del array
        unsigned char * getarray (void) ;

        // Operador de suma de arrays de bits
        Bits operator+ (Bits) const ;
        Bits operator+= (Bits) ;

        // ToString
        string ToString (void) const ;

        // Print
        void print (void) const ;
};


// Codificacion uniforme
int codifica (string cadena, unsigned char * array) ;
string descodifica (unsigned char * array, int size) ;

// Funciones para presentar datos
void printstr8 (unsigned char * cad, int size) ;
void printstr5 (string cad) ;
void print_string (string cad) ;

#endif
