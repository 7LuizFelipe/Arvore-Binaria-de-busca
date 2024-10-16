//Bibliotecas necess�rias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinariaBusca.h"

using namespace std;

TipoCelula *Raiz;

int Contador;

void ArvoreBinariaBusca_Construtor()
{

    Raiz = NULL;
    Contador = 0;
}

void ArvoreBinariaBusca_Destrutor(){


     ArvoreBinariaBusca_Destrutor(Raiz);
     Contador = 0;
}

void ArvoreBinariaBusca_Destrutor(TipoCelula *&Raiz){


     if(Raiz!=NULL)
     {
         ArvoreBinariaBusca_Destrutor(Raiz->Esq);
         ArvoreBinariaBusca_Destrutor(Raiz->Dir);

         delete(Raiz);
         Raiz = NULL;
     }
}

bool ArvoreBinariaBusca_Vazia()
{

   return Raiz == NULL;
}

int ArvoreBinariaBusca_Tamanho()
{

   return Contador;
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento)
{

     return ArvoreBinariaBusca_Inserir(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento, TipoCelula *&Raiz)
{

     if(Raiz == NULL)
     {
        if((Raiz = new(TipoCelula)) == NULL)
           return false;
        else
        {
            Raiz->Item = Elemento;
            Raiz->Esq = Raiz->Dir = NULL;
            Contador++;
            return true;
        }
     }
     else
     {
         if(Elemento < Raiz->Item)
           return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Item)
              return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Dir);
            else return false;
         }
     }
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento)
{

     return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento, TipoCelula *Raiz)
{

     if(Raiz == NULL) return false;
     else
     {
         if(Elemento < Raiz->Item)
           return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Item)
              return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Dir);
            else return true;
         }
     }
}

void ArvoreBinariaBusca_Percurso(int modo)
{

     switch (modo)
     {
        case 1: ArvoreBinariaBusca_PreOrdem(Raiz); break;
        case 2: ArvoreBinariaBusca_EmOrdem(Raiz); break;
        case 3: ArvoreBinariaBusca_PosOrdem(Raiz); break;
        default: cout <<"Ordem desconhecida";
     }
     cout << endl << endl;
     system("pause");
}

void ArvoreBinariaBusca_EmOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         ArvoreBinariaBusca_EmOrdem(Raiz->Esq);
         cout << Raiz->Item << " ";
         ArvoreBinariaBusca_EmOrdem(Raiz->Dir);
     }
}

void ArvoreBinariaBusca_PreOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         cout << Raiz->Item << " ";
         ArvoreBinariaBusca_PreOrdem(Raiz->Esq);
         ArvoreBinariaBusca_PreOrdem(Raiz->Dir);
     }
}

void ArvoreBinariaBusca_PosOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         ArvoreBinariaBusca_PosOrdem(Raiz->Esq);
         ArvoreBinariaBusca_PosOrdem(Raiz->Dir);
         cout << Raiz->Item << " ";
     }
}

#include <queue> // Para usar a fila

void ArvoreBinariaBusca_Imprimir_Por_Nivel(int nivel) {
    if (Raiz == NULL) {
        cout << "A arvore esta vazia.\n";
        return;
    }
    std::queue<TipoCelula*> fila;
    fila.push(Raiz);
    int currentLevel = 0;

    while (!fila.empty()) {
        int nodesAtCurrentLevel = fila.size();
        if (currentLevel == nivel) {
            for (int i = 0; i < nodesAtCurrentLevel; i++) {
                TipoCelula* node = fila.front();
                cout << node->Item << " ";
                fila.pop();
            }
            cout << endl;
            return;
        }
        for (int i = 0; i < nodesAtCurrentLevel; i++) {
            TipoCelula* node = fila.front();
            fila.pop();
            if (node->Esq != NULL) {
                fila.push(node->Esq);
            }
            if (node->Dir != NULL) {
                fila.push(node->Dir);
            }
        }
        currentLevel++;
    }
    cout << "Nivel " << nivel << " nao encontrado na arvore.\n";
}
