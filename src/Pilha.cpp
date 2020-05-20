#include "pilha.h"
#include <cstdlib>
#include <iostream>

using namespace std;

pilha::pilha()
{
    blocoTopo=NULL;
}

bool pilha::push(char valor)
{
    Node * novoBloco = (Node * ) malloc(sizeof(Node));
    if(novoBloco==NULL)
    {
        return false;
    }
    else
    {
        novoBloco->item = valor;
        novoBloco->anterior = blocoTopo;
        blocoTopo = novoBloco;
        return true;
    }
}

char pilha::get(char valor)
{
    if(blocoTopo==NULL)
    {
        return (0);
    }
    else
    {
        valor = blocoTopo->item;
        return (valor);
    }
}
char pilha::pop()
{
    if(blocoTopo==NULL)
    {
        return NULL;
    }
    else
    {
        Node * temp;
        temp = blocoTopo;
        blocoTopo = blocoTopo->anterior;
        return temp->item;
        free(temp);
    }
}
pilha::~pilha()
{
    if(blocoTopo!=NULL)
    {
        Node * temp;
        while(blocoTopo!=NULL)
        {
            temp = blocoTopo;
            blocoTopo = blocoTopo->anterior;
            temp = NULL;
            free(temp);
        }
    }
}

int pilha::print()//metodo de print da pilha
{
   Node *temp;
   temp = blocoTopo;
   if (temp == NULL)
   {
       cout << "\n\nPilha vazia\n" << endl;
       return -1;
   }
   else
   {
       //cout<<"------"<<endl;
       while (temp != NULL)
       {
           cout << temp->item << endl;
           temp = temp->anterior;
       }
       return 0;
   }
}
bool pilha::isVazia() //metodo para verificar se a pilha está vazia
{
    if(blocoTopo!=NULL)
    {
        return true;
    }
    return false;
}

char pilha::top(){
    return(get(0));
}
