#include <iostream>
#include <string>

#include "code.h"
#include "bit.h"

using namespace std ;

int main (void) {
  // Ruta hacia el fichero
  string file = "data/quijote.txt" ;
  // Objeto codigo
  Code mycode ;
  // Generamos un codigo huffman a partir del fichero
  mycode.huffman(file) ;
  // Mostrar por pantalla
  mycode.print() ;

  // Obtenemos una cadena
  unsigned char * original = (unsigned char *) "HOLA" ;

  cout << original << endl ;

  Bits origin (original, 4 * 8) ;

  Bits codificada = mycode.cod (origin) ;
  //cout << endl << endl << "codificada: " ; codificada.print() ;
  /*string descodifica = mycode.des (codificada) ;

  cout << "Original: " << original << endl ;
  cout << "Descodificada: " << descodifica << endl ;*/

  return (0) ;
}
