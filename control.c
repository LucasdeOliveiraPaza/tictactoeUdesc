#include "control.h"

void buildTable(char table[4][4]) {
    int i, j;

    //bordas da tabela
    table[0][0] = '_';
    table[0][1] = '1';
    table[0][2] = '2';
    table[0][3] = '3';
    table[1][0] = '1';
    table[2][0] = '2';
    table[3][0] = '3';

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i != 0 && j != 0) {
                table[i][j] = '_';
            }
        }
    }
}

void showTable(char table[4][4]) {
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("_%c_|", table[i][j]);
        }
        printf("\n");
    }
}

int inputValue(char table[4][4], char value, char line, char column) {
    //verifica se os valores são validos
    if (line != '1' && line != '2' && line != '3') {
        printf("Valor da linha invalido!\n");
        return 0;
    }

    if (column != '1' && column != '2' && column != '3') {
        printf("Valor da coluna invalido!\n");
        return 0;
    }

    //verifica se o lugar ja foi selecionado
    if (table[line - '0'][column - '0'] != '_') {
        printf("posicao ja esta ocupada\n");
        return 0;
    }

    //o - '0' é para converter os valores para inteiro pois como são char não acham o index certo no array
    //por algum motivo o zero tambem tem que ser em string não faço ideia do motivo mas se for int não funciona
    table[line - '0'][column - '0'] = value;

    return 1;
}

int checkGameState(char table[4][4]) {
    //função para verificar todos os possiveis status de vitoria organizadas dessa forma para ser mais facil de visualizar
    int vrc1[8] = {0,3,6,0,1,2,0,2}, i;
    int vrc2[8] = {1,4,7,3,4,5,4,4}, j;
    int vrc3[8] = {2,5,8,6,7,8,8,6}, x = 0;
    char marks[9];

    for (i = 1; i < 4; i++) {
        for (j = 1; j < 4; j++) {
            marks[x] = table[i][j];
            x++;
        }
    }

    for (x = 0; x < 8; x++) {
        if (marks[vrc1[x]] == marks[vrc2[x]] && marks[vrc1[x]] == marks[vrc3[x]] && marks[vrc1[x]] != '_') {
            system("cls");
            showTable(table);
            printf("Parabens jogador %d, voce e o ganhador\n", marks[vrc1[x]]=='X'?1:2);
            return 1;
        }
    }

    return 0;
}



