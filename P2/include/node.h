#ifndef NODE
#define NODE

#include <iostream>

#include "node.h"

using namespace std ;

class Node {
  private:
    char symbol ;
    int left ;
    int right ;
    int dad ;
    double freq ;

  public:
    Node (void) ;

    Node (char, double) ;

    Node (char, int, int, int, double) ;

    double getFreq (void) const ;

    int getLeftSon (void) const ;

    int getRightSon (void) const ;

    int getDad (void) const ;

    char getSymbol (void) const ;

    void setFreq (double) ;

    void setLeftSon (int) ;

    void setRightSon (int) ;

    void setDad (int) ;

    void setSymbol (char) ;

    void print (void) const ;

    bool operator< (const Node &) const ;

    bool operator== (const Node &) const ;

    Node & operator= (const Node &) ;
} ;

#endif