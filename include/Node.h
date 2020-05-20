#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Node{
public:
    Node();
    char item;
    Node * anterior;
};

#endif // NODE_H
