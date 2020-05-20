#include "DPilha.h"
#include <cstdlib>
#include <iostream>

using namespace std;

DPilha::DPilha()
{
    blocoTopo=NULL;
}

bool DPilha::push(double valor)
{
    doubleNode * novoBloco = (doubleNode * ) malloc(sizeof(doubleNode));
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

bool DPilha::get(char valor)
{
    if(blocoTopo==NULL)
    {
        return false;
    }
    else
    {
        valor = blocoTopo->item;
        return true;
    }
}

double DPilha::pop()
{
    if(blocoTopo==NULL)
    {
        return NULL;
    }
    else
    {
        doubleNode * temp;
        temp = blocoTopo;
        blocoTopo = blocoTopo->anterior;
        return temp->item;
        free(temp);
    }
}

DPilha::~DPilha()
{
    if(blocoTopo!=NULL)
    {
        doubleNode * temp;
        while(blocoTopo!=NULL)
        {
            temp = blocoTopo;
            blocoTopo = blocoTopo->anterior;
            temp = NULL;
            free(temp);
        }
    }
}

int DPilha::print() // metodo de print da pilha
{
   doubleNode *temp;
   temp = blocoTopo;
   if (temp == NULL)
   {
       cout << "\nPilha vazia" << endl;
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

int DPilha::tamPilha() //metodo para verificar o tamanho da pilha e retorna o modulo de 2 do seu tamanho
{
    int i = 0;
    doubleNode *temp;
    temp = blocoTopo;
    if (temp == NULL)
    {
        return -1;
    }
    else
    {
       while (temp != NULL)
       {
           i++;
           temp = temp->anterior;
       }
       return i%2;
    }
}
bool DPilha::isVazia() // metodo para verificar se a pilha está fazia
{
    if(blocoTopo!=NULL)
    {
        return true;
    }
    return false;
}
