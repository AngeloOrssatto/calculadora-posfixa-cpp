#include "Node.h"
#include <cstdlib>
#include <iostream>

#ifndef PILHA_H
#define PILHA_H

class pilha{
private:
    Node * blocoTopo;
public:
    pilha();
    bool push(char valor);
    char get(char valor);
    char top();
    char pop();
    int print();
    bool isVazia();
    ~pilha();
};

#endif // PILHA_H
