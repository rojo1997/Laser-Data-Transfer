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

unordered_map<char,double> getProb(string archivo){
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
  return (prob) ;
}

class Node {
  private:
    char symbol ;
    double freq ;
    int pos ;

  public:
    Node (char s, double f, int p) {
      symbol = s ;
      freq = f ;
      pos = p ;
    }
    Node(){}
    double getFreq (void) const {return (freq) ;}
    bool operator< (const Node & a) const {return (this->freq < a.freq) ;}
    bool operator== (const Node & a) const {
      if (this->symbol != a.symbol) return (false) ;
      if (this->freq != a.freq) return (false) ;
      if (this->pos != a.pos) return (false) ;
      return (true) ;
    }
    Node & operator= (const Node & a) {
      this->symbol = a.symbol ;
      this->freq = a.freq ;
      this->pos = a.pos ;
      return (*this) ;
    }
};

int main(){
  string file = "./data/quijote.txt" ;
  unordered_map<char,double> prob = getProb(file) ;
  cout << "probabilidades:" << endl ;
  for (auto it : prob) cout << it.first << ": " << it.second << endl ;

  set<Node> order_prob ;
  for (auto it : prob) order_prob.insert(Node(it.first,it.second,1)) ;

  for (auto it : order_prob) {
    cout << it.getFreq() << endl ;
    //prob.erase(order_prob.begin()) ;
  }
}
