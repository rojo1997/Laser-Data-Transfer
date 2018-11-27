#ifndef ___BIT___H__
#define ___BIT___H__

#include <iostream>

using namespace std ;

// CLASES
class Bits {

    private:

        int size;
        unsigned char * array;

    public:

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
