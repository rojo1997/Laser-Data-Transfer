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

using namespace std ;

const int NUM_SYM = 32 ;

class Node ;
class Codigo ;

set<Node> getProb(string archivo) ;
Codigo Huffman (set<Node> frecuencias) ;


class Node {
  private:
    char symbol ;
    int left ;
    int right ;
    int dad ;
    double freq ;

  public:
    Node (void) {}

    Node (char s, double f) {
        symbol = s ;
        freq = f ;
        left = -1 ;
        right = -1 ;
        dad = -1 ;
    }
    Node (char s, int l, int r, int d, double f) {
      symbol = s ;
      left = l ;
      right = r ;
      dad = d ;
      freq = f ;
    }

    double getFreq (void) const {return (this->freq) ;}

    int getLeftSon (void) const {return (this->left) ;}

    int getRightSon (void) const {return (this->right) ;}

    int getDad (void) const {return (this->dad) ;}

    char getSymbol (void) const {return (this->symbol) ;}

    void setFreq (double f) {freq = f ;}

    void setLeftSon (int l) {left = l ;}

    void setRightSon (int r) {right = r ;}

    void setDad (int d) {dad = d ;}

    void setSymbol (char s) {symbol = s ;}

    void print (void) const {
      cout << "[" << symbol << "\t:" << freq << "\t," << left << "\t," << right << "\t," << dad << "]" << endl ;
    }

    bool operator< (const Node & a) const {return (this->freq < a.freq) ;}

    bool operator== (const Node & a) const {
      if (this->symbol != a.symbol) return (false) ;
      if (this->freq != a.freq) return (false) ;
      return (true);
    }

    Node & operator= (const Node & a) {
      this->symbol = a.symbol ;
      this->freq = a.freq ;
      this->left = a.left ;
      this->right = a.right ;
      this->dad = a.dad ;
      return (*this) ;
    }
} ;

class Codigo {
  private:
    vector<Node> matrix ;

  public:
    Codigo (void) {}

    Codigo (set<Node> freq) {
      for (auto it : freq) matrix.push_back(it) ;
    }

    void add (Node node) {matrix.push_back(node) ;}

    string des (string cad) {return (cad) ;}
    string cod (string cad) {return (cad) ;}

    unsigned int find (Node & node) const {
      for (unsigned int i = 0 ; i < matrix.size(); i++) {
        if (node == matrix[i]) return (i) ;
      }
    }

    unsigned int size (void) {return (matrix.size()) ;}

    Node & operator[] (Node & node) {
      return (matrix[find(node)]) ;
    }

    Node operator[] (unsigned int i) const {
      return (matrix[i]) ;
    }

    Codigo & operator= (const Codigo & a) {
      this->matrix = a.matrix ;
      return (*this) ;
    }
} ;


int main(){
  string file = "data/quijote.txt" ;
  set<Node> prob = getProb(file) ;
  //cout << "probabilidades:" << endl ;
  for (auto it : prob) it.print() ;

  Codigo micodigo = Huffman (prob) ;

  cout << endl << endl ;

  for (unsigned int i = 0 ; i < micodigo.size() ; i++) {
    micodigo[i].print() ;
  }
}


Codigo Huffman (set<Node> frecuencias) {
  Codigo micodigo (frecuencias) ;

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
