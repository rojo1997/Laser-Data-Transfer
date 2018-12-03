#include "code.h"
#include "node.h"

Code::Code (void) {}

Code::Code (set<Node> freq) {
    for (auto it : freq) matrix.push_back(it) ;
}

void Code::add (Node node) {matrix.push_back(node) ;}

string Code::des (string cad) {

    return (cad) ;
}
string Code::cod (string cad) {
    //Bits decode (cad.c_str(), cad.length() * 8) ;
    //Bits (5 * cad.length()) ;
    for (int i = 0 ; i < cad.length() ; i++) {
        unsigned char value = cad[i] ;

    }
    return (cad) ;
}

unsigned int Code::find (Node & node) const {
    for (unsigned int i = 0 ; i < matrix.size(); i++) {
    if (node == matrix[i]) return (i) ;
    }
}

unsigned int Code::size (void) const {return (matrix.size()) ;}

Node & Code::operator[] (Node & node) {
    return (matrix[find(node)]) ;
}

Node Code::operator[] (unsigned int i) const {
    return (matrix[i]) ;
}

Code & Code::operator= (const Code & a) {
    this->matrix = a.matrix ;
    return (*this) ;
}

set<Node> Code::getProb(string fichero, unsigned int n_symbol = 32) {
  unordered_map<char,double> prob(n_symbol) ;

  // Abrir fichero
  ifstream t(fichero) ;
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

void Code::huffman (set<Node> frecuencias) {
  for (auto it : frecuencias) matrix.push_back(it) ;

  while (frecuencias.size() != 1) {
    auto it = frecuencias.begin() ;
    Node min1 = *it ;
    frecuencias.erase(it) ;
    it = frecuencias.begin() ;
    Node min2 = *it ;
    frecuencias.erase(it) ;

    Node n3 ('#', find(min1), find(min2), -1, min1.getFreq() + min2.getFreq()) ;
    add (n3) ;
    frecuencias.insert (n3) ;

    //this->[min1].setDad(find(n3)) ;
    //this->[min2].setDad(find(n3)) ;
  }
} ;

void Code::huffman (string file, unsigned int n_symbols) {
    huffman(getProb(file, n_symbols)) ;
}

