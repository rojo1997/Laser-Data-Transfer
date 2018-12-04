#include "bit.h"

Bits::Bits (void) {}

Bits::Bits (int i) {

    if (i % 8 != 0) {
        
        array = new unsigned char [i/8 + 1] ;

    } else {
        
        array = new unsigned char [i/8] ;
    }

    size = i ;

    for (int i = 0 ; i < ceil (size / 8.0) ; i++) {

        array[i] = 0 ;
    }
}

Bits::Bits (unsigned char * a, int b) {

    array = a ;
    size = b ;
}

void Bits::insert (int a, unsigned char value) {

    int i = a / 8 ; int j = a % 8 ;
    array[i] |= (value << j) ;
}

unsigned char Bits::get (int a) const {

    int i = a / 8 ; int j = a % 8 ;
    return ((array[i]) & (1 << j)) >> j ;
}

unsigned int Bits::length (void) const {
    return (size) ;
}

unsigned char * Bits::getarray (void) {

    return (array) ;
}

Bits Bits::operator+ (Bits b) const {
    Bits out (length() + b.length()) ;
    for (unsigned int i = 0 ; i < length() ; i++) {
        out.insert(i, get(i)) ;
    }
    for (unsigned int i = length(), j = 0 ; i < out.length() ; i++, j++) {
        out.insert(i, b.get(j)) ;
    }
    return (out) ;
}

Bits Bits::operator+= (Bits b) {
    return ((*this) + b) ;
}

string Bits::ToString (void) const {
    string out ;
    if (!(length() % 8)) return ("Error") ;
    for(unsigned int i = 0; i < (length()/8) ; i++) {
        out += array[i] ;
    }
    return (out) ;
}

void Bits::print (void) const {
    for (unsigned int i = 0 ; i < length() ; i++) {
        if (get(i) == 0) cout << "0" ;
        else cout << "1" ;
    }
}

int codifica (string cadena, unsigned char * array) {

    const unsigned int NUM_BITS = cadena.length() * 5 ;
    const unsigned int NUM_BYTES = ceil (NUM_BITS / 8.0) ;
    // Creamos el array de bits del tamaño definido por la app biyectiva
    Bits str (cadena.length() * 5.0) ;
    // Iteramos sobre los caracteres leidos
    for (unsigned int i = 0, k = 0; i < cadena.length() ; i++) {
    
        unsigned char letra = ((unsigned char) cadena[i]) ;
        if (letra == ' ') letra = 26 ;
        else if (letra == ',') letra = 27 ;
        else if (letra == ';') letra = 28 ;
        else if (letra == '.') letra = 29 ;
        else if (letra == ':') letra = 30 ;
        else letra -= 65 ;
        for (unsigned char j = 0 ; j < 5 ; j++, k++) {
            
            str.insert(k, (letra & (1 << j)) >> j) ;
        }
    }
    for (unsigned int i = NUM_BITS ; i < NUM_BYTES * 8 ; i++) str.insert(i, 0) ;
    for (unsigned int i = 0 ; i < NUM_BYTES ; i++) array[i] = str.getarray()[i] ;
    array[NUM_BYTES] = '\0' ;
    // Devolvemos el numero de bits
    return (NUM_BITS) ;
}

string descodifica (unsigned char * array, int size) {

    // const int NUM_BITS = size ;
    const int NUM_WORDS = size / 5 ;
    // const int NUM_BYTES = ceil (size / 8.0) ;
    // Creamos el array de bits para extraer datos
    Bits str (array, size) ;
    string cadena ;
    for (int i = 0 ; i < NUM_WORDS ; i++) {

        unsigned char letra = 0 ;
        for (int j = 0 ; j < 5 ; j++) letra |= (str.get(i * 5 + j) << j) ;
        if (letra == 26) cadena += ' ' ;
        else if (letra == 27) cadena += ',' ;
        else if (letra == 28) cadena += ';' ;
        else if (letra == 29) cadena += '.' ;
        else if (letra == 30) cadena += ':' ;
        else cadena += (char)(letra + 65) ;
    }
    return (cadena) ;
}

void printstr8 (unsigned char * cad, int size) {

    for (int i = 0 ; i < size ; i++) {

        cout << +cad[i] << " " ;
    }
    cout << endl;
}

void printstr5 (string cad) {

    for (unsigned int i = 0 ; i < cad.length() ; i++) {

        cout << +((unsigned char) cad[i]) - 65 << " " ;
    }
    cout << endl;
}

void print_string (string cad) {

    for (unsigned int i = 0 ; i < cad.length() ; i++) {

        cout << +((unsigned char) cad[i]) << " " ;
    }
    cout << endl;
}
