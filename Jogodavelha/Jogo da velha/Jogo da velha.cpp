// Jogo da velha 

#include <iostream>
#include <conio.h>

using namespace std;

void imprimiPosicaoMatrix();
void imprimiTabela();
int adicionaMarca();
int checa();

char tabela[3][3] = {' ', ' ', ' ',
                    ' ', ' ', ' ',
                    ' ', ' ', ' ' };

int rodada = 1; // 1-Player 1, 0-Player 2
char marca = 'O';
int entrada;

int main()
{
    int ganhou = 0;
    int entradaValida = 0;

    for (int i = 0; i < 9; i++) {
        system("cls");
        imprimiTabela();
        if (rodada) cout << endl << "Rodada do Jogador 1 ( Simbolo: X)" << endl;
        else cout << endl<<"Rodada do Jogador 2 ( Simbolo: O)" << endl;
        imprimiPosicaoMatrix();
        cout << endl <<"Digite uma entrada para Matrix:";

        cin >> entrada;
        while (entrada < 0 || entrada > 9) {
            cout << "Entrada Invalida. Por Favor redigite uma entrada:";
            cin >> entrada;
        }

        if (rodada) marca = 'X';
        else marca = 'O';

        entradaValida = adicionaMarca();
        if (!entradaValida) {
            i--;
            continue;
        }

        ganhou = checa();
        if (ganhou) {
            system("cls");
            imprimiTabela();
            if (rodada) cout << endl << "Jogador 1 - Voce Ganhou";
            else cout << endl << "Jogador 2 - Voce Ganhou";
            _getch();
            break;
        }

        if (i == 8) {
            system("cls");
            imprimiTabela();
            cout << endl << "EMPATE";
        }

        rodada = !rodada;


    }



    return 0;
}

void imprimiPosicaoMatrix(){
    cout << endl << "===NUMEROS DA TABELA===" << endl;
    cout << " 1 | 2 | 3 " << endl;
    cout << "----------" << endl;
    cout << " 4 | 5 | 6 " << endl;    
    cout << "----------" << endl;
    cout << " 7 | 8 | 9 " << endl;
}

void imprimiTabela(){
    cout << endl << endl << "===TABELA===" << endl;
    cout << " " << tabela[0][0] << " | " << tabela[0][1] << " | " << tabela[0][2] << "" << endl;
    cout << "----------" << endl;
    cout << " " << tabela[1][0] << " | " << tabela[1][1] << " | " << tabela[1][2] << "" << endl;
    cout << "----------" << endl;
    cout << " " << tabela[2][0] << " | " << tabela[2][1] << " | " << tabela[2][2] << "" << endl;

}

int adicionaMarca() {
    for (int i = 0, k = 1; i < 3; i++) {
        for (int j = 0; j < 3; j++, k++) {
            if (k == entrada) {
                if (tabela[i][j] == ' ') {
                    tabela[i][j] = marca;
                }
                else{
                    cout << "Entrada invalida";
                    _getch();
                    return 0;
                
                }

            }
        }
    }
}

int checa() {
    //Checa linhas
    if (tabela[0][0] == marca && tabela[0][1] == marca && tabela[0][2] == marca) return 1;
    if (tabela[1][0] == marca && tabela[1][1] == marca && tabela[1][2] == marca) return 1;
    if (tabela[2][0] == marca && tabela[1][1] == marca && tabela[2][2] == marca) return 1;

    //Checa colunas
    if (tabela[0][0] == marca && tabela[1][0] == marca && tabela[2][0] == marca) return 1;
    if (tabela[0][1] == marca && tabela[1][1] == marca && tabela[2][1] == marca) return 1;
    if (tabela[0][2] == marca && tabela[1][2] == marca && tabela[2][2] == marca) return 1;

    //Checa diagonais
    if (tabela[0][0] == marca && tabela[1][1] == marca && tabela[2][2] == marca) return 1;
    if (tabela[0][2] == marca && tabela[1][1] == marca && tabela[2][0] == marca) return 1;

    return 0;
}