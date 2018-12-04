#include "node.h"

Node::Node (void) {}

Node::Node (char s) {
    symbol = s ;
}

Node::Node (char s, double f) {
    symbol = s ;
    freq = f ;
    left = -1 ;
    right = -1 ;
    dad = -1 ;
}
Node::Node (char s, int l, int r, int d, double f) {
    symbol = s ;
    left = l ;
    right = r ;
    dad = d ;
    freq = f ;
}

double Node::getFreq (void) const {return (this->freq) ;}

int Node::getLeftSon (void) const {return (this->left) ;}

int Node::getRightSon (void) const {return (this->right) ;}

int Node::getDad (void) const {return (this->dad) ;}

char Node::getSymbol (void) const {return (this->symbol) ;}

void Node::setFreq (double f) {freq = f ;}

void Node::setLeftSon (int l) {left = l ;}

void Node::setRightSon (int r) {right = r ;}

void Node::setDad (int d) {dad = d ;}

void Node::setSymbol (char s) {symbol = s ;}

void Node::print (void) const {
    cout << "[" << symbol << "\t:" << freq << "\t," << left << "\t," << right << "\t," << dad << "]" << endl ;
}

bool Node::leaf (void) const {
    return ((left == -1) && (right == -1)) ;
}

bool Node::root (void) const {
    return (dad == -1) ;
}

bool Node::operator< (const Node & a) const {return (this->freq < a.freq) ;}

bool Node::operator== (const Node & a) const {
    if (this->symbol != a.symbol) return (false) ;
    if (this->freq != a.freq) return (false) ;
    return (true);
}

Node & Node::operator= (const Node & a) {
    this->symbol = a.symbol ;
    this->freq = a.freq ;
    this->left = a.left ;
    this->right = a.right ;
    this->dad = a.dad ;
    return (*this) ;
}