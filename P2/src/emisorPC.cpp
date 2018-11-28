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

#include "code.h"

using namespace std ;

const int NUM_SYM = 32 ;

set<Node> getProb(string archivo) ;
Code Huffman (set<Node> frecuencias) ;

int main(){
  string file = "data/quijote.txt" ;
  set<Node> prob = getProb(file) ;
  //cout << "probabilidades:" << endl ;
  for (auto it : prob) it.print() ;

  Code micodigo = Huffman (prob) ;

  cout << endl << endl ;

  for (unsigned int i = 0 ; i < micodigo.size() ; i++) {
    micodigo[i].print() ;
  }
}


Code Huffman (set<Node> frecuencias) {
  Code micodigo (frecuencias) ;

  while (frecuencias.size() != 1) {
    auto it = frecuencias.begin() ;
    Node min1 = *it ;
    frecuencias.erase(it) ;
    it = frecuencias.begin() ;
    Node min2 = *it ;
    frecuencias.erase(it) ;

    Node n3 ('#', micodigo.find(min1), micodigo.find(min2), -1, min1.getFreq() + min2.getFreq()) ;
    micodigo.add (n3) ;
    frecuencias.insert (n3) ;

    micodigo[min1].setDad(micodigo.find(n3)) ;
    micodigo[min2].setDad(micodigo.find(n3)) ;
  }
  return (micodigo) ;
} ;

set<Node> getProb(string archivo) {
  unordered_map<char,double> prob(NUM_SYM) ;

  // Abrir archivo
  ifstream t(archivo) ;
  string texto((istreambuf_iterator<char>(t)), istreambuf_iterator<char>()) ;
  texto.erase(remove(texto.begin(), texto.end(), '\n'), texto.end()) ;
  int length = texto.length() ; double elem = 1.0/length;
  for(int i = 0 ; i < length ; i++){
    char letrai = toupper(texto[i]) ;
    if(!prob.count(letrai)) prob.insert(make_pair(letrai,elem)) ;
    else prob[letrai]+= elem ;
  }
  set<Node> order_prob ;
  for (auto it : prob) order_prob.insert(Node(it.first,it.second)) ;
  return (order_prob) ;
}
