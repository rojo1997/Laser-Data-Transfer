#include "bit.h"
#include "code.h"
#include "node.h"

Code::Code (void) {}

Code::Code (set<Node> freq) {
    for (auto it : freq) matrix.push_back(it) ;
}

void Code::add (Node node) {matrix.push_back(node) ;}

string Code::des (Bits b) const {
    // Cadena codificada para pasarle cad
    // Interface sobre un simbolo
    Bits aux (5) ;
    // Cadena de salida
    string out = "" ;
    // Devemos extraer cadenas de 5 bits
    for (unsigned int i = 0 ; i < b.length() ; i++) {
        if (i % 5) out += getDeco(aux) ;
        aux.insert(i % 5, b.get(i)) ;
    }
    return (out) ;
}
Bits Code::cod (Bits decode) const {
    // Cadena para guardar bits de salida
    Bits code ((decode.length() / 8) * 5) ;
    // String de salida
    string out ;
    for (unsigned int i = 0 ; i < decode.length()/8 ; i++) {
        unsigned char value = decode.getarray()[i] ;
        cout << value << endl ;
        code += getCode (value) ;
        /*cout << "code:" ;
        getCode (value).print() ;
        cout << endl ;*/
    }
    return (code) ;
}

unsigned int Code::find (const Node & node) const {
    /*for (unsigned int i = 0 ; i < matrix.size(); i++) {
        if (node == matrix[i]) return (i) ;
    }*/
    auto it = std::find(matrix.cbegin(), matrix.cend(), node) ;
    return (distance(matrix.cbegin(), it)) ;
}

Node Code::findDad (const Node & node) const {
    return (matrix[node.getDad()]) ;
}

Node Code::findLeftSon (const Node & node) const {
    return (matrix[node.getLeftSon()]) ;
}

Node Code::findRightSon (const Node & node) const {
    return (matrix[node.getRightSon()]) ;
}

Node Code::findMe (char s) const {
    for (auto it : matrix)
        if (it.getSymbol() == s) return (it) ;
    return (*matrix.end()) ;
}

bool Code::direction (const Node & p, const Node & h) const {
    Node aux = findRightSon(p);
    if (aux == h) return (true) ;
    else return (false) ;            
}

// Falta probarlo
/* Funcion que recibe un caracter ascii y lo codifica
en funcion de la matrix
*/
Bits Code::getCode (char a) const {
    // Cadena de bits de salida
    Bits out ;
    // Buscamos el nodo hoja con la letra a
    Node son = findMe ((a)) ; int i = 0 ;
    // Recorremos el arbol de forma ascendente
    /*do {
        //out.insert(out.length() - i - 1, direction(findDad (son), son)) ;
        i++ ; son = findDad (son) ;
    } while (!son.root()) ;*/
    return (out);
}

// Falta probarlo
char Code::getDeco (Bits b) const {
    // Buscamos el nodo root
    Node aux = findDad (Node ()) ;
    for (unsigned int i = 0 ; i < b.length(); ++i) {
        if (b.get(i) == 0) aux = findLeftSon(aux) ;         
        else aux = findRightSon(aux) ;
    }
    return (aux.getSymbol()) ;     
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

    (*this)[min1].setDad(find(n3)) ;
    (*this)[min2].setDad(find(n3)) ;
  }
}

void Code::huffman (string file, unsigned int n_symbols) {
    huffman(getProb(file, n_symbols)) ;
}

void Code::print (void) {
    int i = 0 ;for (auto it : matrix) {
        cout << "[" << i++ << "]" ; 
        it.print() ; cout << endl ;
    }
}
