#include "doubleNode.h"
#ifndef DPILHA_H
#define DPILHA_H


class DPilha
{
private:
    doubleNode * blocoTopo;
    public:
    DPilha();
    bool push(double valor);
    bool get(char valor);
    double pop();
    int print();
    bool isVazia();
    int tamPilha();
    ~DPilha();
};

#endif // DPILHA_H
