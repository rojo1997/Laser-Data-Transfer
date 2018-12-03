#ifndef BIT
#define BIT

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>

using namespace std ;

class Bits {
    private:
        int size;
        unsigned char * array;

    public:
        // Constructores
        Bits (void) ;
        Bits (int i) ;

        Bits (unsigned char * a, int b) ;

        void insert (int a, unsigned char value) ;

        unsigned char get (int a) ;

        int length (void) ;

        unsigned char * getarray (void) ;
};

int codifica (string cadena, unsigned char * array) ;
string descodifica (unsigned char * array, int size) ;
void printstr8 (unsigned char * cad, int size) ;
void printstr5 (string cad) ;
void print_string (string cad) ;

#endif
