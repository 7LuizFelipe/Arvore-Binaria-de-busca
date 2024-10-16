// Inclusao das bibliotecas necessarias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinariaBusca.h"

using namespace std;

// Funcao principal para testar operacoes em uma Arvore Binaria de Busca
int main() {
    int valor; // Variavel para armazenar o valor digitado pelo usuario e inserir na arvore
    int escolha; // Variavel para controle do menu de operacoes
    int tipoPercurso; // Variavel para escolha do tipo de percurso na arvore

    ArvoreBinariaBusca_Construtor(); // Inicializa a arvore binaria

    do { // Loop do menu de operacoes da arvore
        system("cls");

        cout << "Programa de Operacoes com Arvore Binaria de Busca\n\n";
        cout << "Escolha uma das opcoes abaixo:";
        cout << "\n\nMenu: \n";
        cout << "\n1 - Inserir elemento";
        cout << "\n2 - Pesquisar elemento";
        cout << "\n3 - Contar elementos";
        cout << "\n4 - Verificar se arvore esta vazia";
        cout << "\n5 - Realizar percurso";
        cout << "\n6 - Imprimir elementos por nivel";
        cout << "\n7 - Sair\n";
        cout << "\nOpcao: ";
        cin >> escolha;

        system("cls");

        switch (escolha) {
            case 1:
                cout << "\nDigite o valor a ser inserido: ";
                setbuf(stdin, NULL);
                cin >> valor;

                if (ArvoreBinariaBusca_Inserir(valor))
                    cout << "Valor inserido com sucesso.\n\n";
                else
                    cout << "Erro ao inserir o valor.\n\n";

                system("pause");
                break;

            case 2:
                cout << "\nDigite o valor para pesquisa: ";
                setbuf(stdin, NULL);
                cin >> valor;

                if (ArvoreBinariaBusca_Pesquisar(valor))
                    cout << "Valor encontrado na arvore.\n\n";
                else
                    cout << "Valor nao encontrado.\n\n";

                system("pause");
                break;

            case 3:
                cout << "\nNumero total de elementos na arvore: " << ArvoreBinariaBusca_Tamanho() << "\n\n";
                system("pause");
                break;

            case 4:
                if (ArvoreBinariaBusca_Vazia())
                    cout << "A arvore esta vazia.\n\n";
                else
                    cout << "A arvore possui elementos.\n\n";

                system("pause");
                break;

            case 5:
                cout << "\nSelecione o tipo de percurso desejado:\n";
                cout << "1 - Pre-ordem\n";
                cout << "2 - Em-ordem\n";
                cout << "3 - Pos-ordem\n";
                cout << "\nOpcao: ";
                cin >> tipoPercurso;
                ArvoreBinariaBusca_Percurso(tipoPercurso);
                cout << "\n";
                system("pause");
                break;

            case 6:
                int nivelDesejado;
                cout << "Digite o nivel a ser exibido: ";
                cin >> nivelDesejado;
                ArvoreBinariaBusca_Imprimir_Por_Nivel(nivelDesejado);
                cout << "\n\n";
                system("pause");
                break;

            case 7:
                ArvoreBinariaBusca_Destrutor();
                cout << "Arvore destruida. Encerrando programa.\n";
                break;

            default:
                cout << "\nOpcao invalida. Tente novamente.\n\n";
                system("pause");
        }
    } while (escolha != 7);

    return 0;
}
