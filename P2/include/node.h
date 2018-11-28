#ifndef NODE
#define NODE

#include <iostream>

using namespace std ;

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

#endif