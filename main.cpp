#include<Pilha.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <DPilha.h>
#include <math.h>
#include <ctype.h>

using namespace std;

double p = 3.1415926535898; //declarando pi p/ usar na expressao e no calculo das funçoes trigonometricas
double Valor[26]; //vetor de armazenamento do valor das variaveis
string auxiliar; //string refinada apos a funçao Parser
pilha *PosFix; //pilha que contem a expressao pos-fixa
int PosFixa();
int main();

bool isNumber()
{
    int i = 0;
    if ((auxiliar[i] >= 48 && auxiliar[i] <= 57) || auxiliar[i] == 46 || auxiliar[i] == 44 )
        return true;
    else
        return false;
}

void zeraVetor()//funçao para guardar os valores das variaveis A-Z
{
    for(int i=0;i<26;i++){
        Valor[i]=0575678657650.0;
        }
}

int Priority(char y, char z)// funçao para setar a prioridade dos operadores na notaçao pos-fixa
{
    int py = 0, pz = 0;
    if (y == ';' || y == '|' || y == '%' || y == '#'  || y == '!' || y == '@' || y == '$')
      /*antigo s   antigo a     antigo c    antigo l     antigo p    antigo t    antigo q */
    {
        py = 5;
    }
    else if (y == '^')
    {
        py = 4;
    }
    else if(y == '*' || y == '/')
    {
        py = 2;
    }
    else if(y == '+' || y == '-')
    {
        py = 1;
    }
    else if(y == '(')
    {
        py = 5;
    }

    if (z == ';' || z == '|' || z == '%' || z == '#' || z == '!' || z == '@' || z == '$')
    {
        pz = 5;
    }
    else if (z == '^')
    {
        pz = 3;
    }
    else if(z == '*' || z == '/')
    {
        pz = 2;
    }
    else if(z == '+' || z == '-')
    {
        pz = 1;
    }
    else if(z == '(')
    {
        pz = 0;
    }

    return (py>pz);
}

int Parser (string expression)//funçao que analisa toda a expressao de entrada e refina para melhor ser utilizada durante o programa
{
    int i = 0, j = 0, valida = 0, cont = 0;
    do //varre a expressao
    {
        if (expression[0] == '^' || expression[0] == '*' || expression[0] == '/' || expression[0] == '+' || expression[0] == ')')
        {
            cout << "EXPRESSAO INVALIDA!" << endl;
            valida = -1;
            break;
        }
        else if (expression[i] == ' ')//achar um espaço
        {
            ++i;
        }
        else if ((expression[i] == 's' && expression[i+1] == 'e' && expression[i+2] == 'n') || (expression[i] == 'S' && expression[i+1] == 'E' && expression[i+2] == 'N'))//achar um sen
        {
            auxiliar[j] = ';' ;
            i = i + 2;
        }
        else if ((expression[i] == 'c' && expression[i+1] == 'o' && expression[i+2] == 's') || (expression[i] == 'C' && expression[i+1] == 'O' && expression[i+2] == 'S'))//achar um cos
        {
            auxiliar[j] = '%';
            i = i + 2;
        }
        else if ((expression[i] == 't' && expression[i+1] == 'a' && expression[i+2] == 'n') || (expression[i] == 'T' && expression[i+1] == 'A' && expression[i+2] == 'N'))//achar um tan
        {
            auxiliar[j] = '@';
            i = i + 2;
        }
        else if ((expression[i] == 'l' && expression[i+1] == 'o' && expression[i+2] == 'g') || (expression[i] == 'L' && expression[i+1] == 'O' && expression[i+2] == 'G'))//achar um log
        {
            auxiliar[j] = '#';
            i = i + 2;
        }
        else if ((expression[i] == 'a' && expression[i+1] == 'b' && expression[i+2] == 's') || (expression[i] == 'A' && expression[i+1] == 'B' && expression[i+2] == 'S'))//achar um abs
        {
            auxiliar[j] = '|';
            i = i + 2;
        }
        else if ((expression[i] == 's' && expression[i+1] == 'q' && expression[i+2] == 'r' && expression[i+3] == 't') || (expression[i] == 'S' && expression[i+1] == 'Q' && expression[i+2] == 'R' && expression[i+3] == 'T'))// achar um sqrt
        {
            auxiliar[j] = '$';
            i = i + 3;
        }
        else if ((expression[i] == 'p' && expression[i+1] == 'i')||(expression[i] == 'P' && expression[i+1] == 'I'))//achar um PI
        {
            auxiliar[j] = '!';
            i = i + 1;
        }
        else if ((expression[i] <= 'Z' && expression[i] >= 'A') || (expression[i] <= '+' && expression[i] >= '(') || expression[i] == '-' || expression[i] == '/' || expression[i] == '^' || (expression[i] >= '0' && expression[i] <= '9'))
        {
            auxiliar[j] = expression[i];
            if (expression[i] == '(')
            {
                cont++;
            }
            if (expression[i] == ')')
            {
                cont--;
            }
        }
        else
        {
            cout << "EXPRESSAO INVALIDA!" << endl;
            valida = -1;
            break;
        }
        i++;
        j++;
    } while (expression[i] != '\0');
    if (cont != 0)
    {
        cout << "EXPRESSAO INVALIDA!" << endl;
        valida = -1;
    }
    cout << endl;
    // verificaçao se a expressao é valida para continuar o processo
    if (valida == -1)// caso nao for valida, pede outra entrada
    {
        cout << "POR FAVOR INSIRA OUTRA EXPRESSAO: " << endl;
        main();
    }
    else // caso for valida, continua o processo solicitando os valores das respectivas variaveis
    {
        int j = 0;
        i=0;
        zeraVetor();
        int HashCode;
        do
        {
            if (auxiliar[i] >= 65 && auxiliar[i] <= 90)
            {
                HashCode=auxiliar[i]-65;
                if (Valor[HashCode] == 575678657650.0)
                {
                    cout << "Insira o valor da variavel "<< auxiliar[i] << ": ";
                    cin >> Valor[HashCode];
                }
            }
            i++;
        }
        while(auxiliar[i] != '\0');
        PosFixa();
    }
    return 0;
}

int PosFixa() //funçao que coloca em notaçao pos-fixa, utilizando prioridades entre operadores, e seta a expressao em uma pilha de mesmo nome
{
   pilha *w;
   w = new pilha;
   pilha *auxposfix;
   auxposfix = new pilha;
   int i = 0;
   char y,z;
   w->push('(');
   cout << "\nNOTACAO POS-FIXA: ";
   do
   {
       y = auxiliar[i];
       i++;
       if ((y >= 'A' && y <= 'Z'))
       {
           auxposfix->push(y);
       }
       /*else if (y == 33)
       {
           auxposfix->push(y);
       }*/
       else if (y == '(')
       {
           w->push(y);
       }
       else if(y == ')' || y == '\0')
       {
           do
           {
               z = w->pop();
               if (z != '(')
               {
                   auxposfix->push(z);
               }
           }
           while (z != '(');
       }
       else if (y == '+' || y == '-' || y == '*' || y == '/' || y == '^' || y == 35 || y == 36 || y == 37 || y == 59 || y == 64 || y == 124)
       {
           while(1)
           {
               z = w->pop();
               if (Priority(y,z))
               {
                   w->push(z);
                   w->push(y);
                   break;
               }
               else
               {
                   auxposfix->push(z);
               }
           }
       }
   }
   while (y != '\0');
   char teste;
   while (w->isVazia())
   {
       teste = w->pop();
       auxposfix->push(teste);
   }
   PosFix = new pilha;

   //Pilha auxiliar para printar
    pilha *PrintPilha;
    PrintPilha = new pilha;

     while (auxposfix->isVazia())
   {
       teste = auxposfix->pop();
       PrintPilha->push(teste);
   }

    while(PrintPilha->isVazia()){
        char p;
        p = PrintPilha->pop();
        auxposfix->push(p);
        p = auxposfix->top();
            if(p == ';')
                cout << "sen ";
            else if(p == '#')
                cout << "log ";
            else if(p == '|')
                cout << "abs ";
            else if(p == '%')
                cout << "cos ";
            else if(p == '!')
                cout << "pi ";
            else if(p == '@')
                cout << "tan ";
            else if(p == '$')
                cout << "sqrt ";
            else
                cout << p << " ";
   }

   while (auxposfix->isVazia())
   {
       teste = auxposfix->pop();
       PosFix->push(teste);
   }

   delete PrintPilha;
   delete auxposfix;
   delete w;
   return 0;
}

bool isOperador(char op) //funçao auxiliar para a funçao Calculadora para diferenciar operadores e operandos
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == ';' || op == '%' || op == '@' || op == '$' || op == '|' || op == '#')
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Calculadora() //funçao que calcula a expressao dada, atraves da pilha em notação pos-fixa
{
    DPilha *calc;
    calc = new DPilha;
    char op;
    double aux1 = 0, aux2 = 0, aux3 = 0;
    while (PosFix->isVazia())
    {
        op = PosFix->pop();
        if (isOperador(op) == true)
        {
            if (op == '+')
            {
                aux1 = calc->pop();
                aux2 = calc->pop();
                aux3 = aux2 + aux1;
                calc->push(aux3);
            }
            else if (op == '*')
            {
                aux1 = calc->pop();
                aux2 = calc->pop();
                aux3 = aux2 * aux1;
                calc->push(aux3);
            }
            else if (op == '/')
            {
                aux1 = calc->pop();
                aux2 = calc->pop();
                aux3 = aux2 / aux1;
                calc->push(aux3);
            }
            else if (op == '-')
            {
                if (calc->tamPilha()!=0)
                {
                    aux1 = calc->pop();
                    aux3 = aux1 * (-1);
                    calc->push(aux3);
                }
                else
                {
                    aux1 = calc->pop();
                    aux2 = calc->pop();
                    aux3 = aux2 - aux1;
                    calc->push(aux3);
                }
            }
            else if (op == '^')
            {
                aux1 = calc->pop();
                aux2 = calc->pop();
                aux3 = pow(aux2, aux1);
                calc->push(aux3);
            }
            else if (op == ';')
            {
                aux1 = calc->pop();
                aux3 = sin(aux1*p/180);
                calc->push(aux3);
            }
            else if (op == '%')
            {
                aux1 = calc->pop();
                aux3 = cos(aux1*p/180);
                calc->push(aux3);
            }
            else if (op == '@')
            {
                aux1 = calc->pop();
                aux3 = tan(aux1*p/180);
                calc->push(aux3);
            }
            else if (op == '$')
            {
                aux1 = calc->pop();
                aux3 = sqrt(aux1);
                calc->push(aux3);
            }
            else if (op == '#')
            {
                aux1 = calc->pop();
                aux3 = log10(aux1);
                calc->push(aux3);
            }
            else if (op == '!')
            {
                aux1 = calc->pop();
                if (aux1 < 0)
                {
                    aux3 = aux1*(-1);
                }
                else
                {
                    aux3 = aux1;
                }
                calc->push(aux3);
            }
        }
        else
        {
            if (op == '!')
            {
                aux1 = p;
                calc->push(aux1);
            }
            else
            {
                    aux1 = Valor[op-65];
                    calc->push(aux1);
            }
        }
    }
    cout << "\n\nRESULTADO FINAL: ";
    calc->print();
    return 0;
}

int main() //print das "regras" da calculadora e chamada das funções principais
{
    cout << "\t CALCULADORA POS-FIXA" << endl;
    cout << "Insira uma expressao valida com variaveis MAIUSCULAS sem ESPACOS" << endl;
    cout << "Operadores validos: +,-,*,/,^,sen,cos,tan,abs,log,sqrt,PI." << endl;
    cout << "(as funcoes trigonometricas informadas devem estar em graus)\n" << endl;
    string expression;
    cin >> expression;
    Parser(expression);
    Calculadora();
    return 0;
}
