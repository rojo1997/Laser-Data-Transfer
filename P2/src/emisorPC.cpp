#include <iostream>
#include <string>

#include "code.h"

using namespace std ;

int main (void) {
  string file = "data/quijote.txt" ;
  Code mycode ;
  mycode.huffman(file) ;

  return (0) ;
}
