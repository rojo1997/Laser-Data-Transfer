#ifndef CODE
#define CODE

#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>

#include "bit.h"
#include "node.h"
#include "code.h"

using namespace std ;

class Code {
  private:
    // Arbol de codificacion y decodificacion
    vector<Node> matrix ;

    // Metodos auxiliares
    set<Node> getProb (string, unsigned int) ;

  public:
    // Constructores
    Code (void) ;
    Code (set<Node>) ;

    // Operadores sobre nodos
    void add (Node) ;
    unsigned int find (const Node &) const ;
    Node findDad (const Node &) const ;
    Node findLeftSon (const Node &) const ;
    Node findRightSon (const Node &) const ;
    Node findMe (char s) const ;
    bool direction (const Node &, const Node &) const ;
    Bits getCode (char) const ;
    char getDeco (Bits) const ;
    unsigned int size (void) const ;

    // Codificadores y descodificadores
    string des (Bits) const ;
    Bits cod (Bits) const ;

    // Sobrecarga de operadores
    Node & operator[] (Node & node) ;
    Node operator[] (unsigned int i) const ;
    Code & operator= (const Code &) ;

    // Algoritmos de codificación
    void huffman (string, unsigned int n_symbols = 32) ;
    void huffman (set<Node>) ;

    // Print
    void print (void) ;
} ;

#endif