#ifndef CODE
#define CODE

#include <iostream>
#include <vector>
#include <set>
#include <string>

#include "node.h"

using namespace std ;

class Code {
  private:
    vector<Node> matrix ;

  public:
    Code (void) {}

    Code (set<Node> freq) {
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

    Code & operator= (const Code & a) {
      this->matrix = a.matrix ;
      return (*this) ;
    }
} ;

#endif