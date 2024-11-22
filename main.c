#include <stdio.h>
#include <stdlib.h>
#include "control.h"

int main() {
    char play;

    //loop para jogar de novo
    do {
        runGame();
        printf("pressione 0 para sair qualquer outra tecla para reiniciar: ");
        scanf(" %c", &play);
    } while (play != '0');

    printf("obrigado por jogar");
    return 0;
}

int runGame() {
    int turn = 1, i, j, gameOver = 0, validPlay;
    char table[4][4], line, column;

    //função para criar a tabela do jogo
    buildTable(table);

    //loop para rodar o jogo
    while (gameOver == 0 && turn <= 9) {
        //limpa o console, faz uma grande diferença
        system("cls");
        //função para mostrar a tabela
        showTable(table);

        validPlay = 0;
        //controle de jogadas, para impedir jogadas invalidas
        do {
            printf("jogador %d(%c) digite a linha que deseja marcar: ", turn%2!=0?1:2, turn%2!=0?'X':'O');
            scanf(" %c", &line);

            printf("jogador %d(%c) digite a coluna que deseja marcar: ", turn%2!=0?1:2, turn%2!=0?'X':'O');
            scanf(" %c", &column);

            //funcao para verificar se a jogada é valida e colocar na tabela caso seja
            validPlay = inputValue(table, turn%2!=0?'X':'O', line, column);
        } while (validPlay == 0);

        //só a partir da quinta jogada que é possivel ter um vencedor antes disso é inutil verificar se alguem ganhou
        if (turn >= 5) {
            //funcao para ver se alguem ganhou
            gameOver = checkGameState(table);
        }
        turn ++;
    }

    //só é possivel ter nove turnos pois só existem 9 jogadas possiveis a partir do turno 10 se ninguem ganhou é empate
    if (turn == 10 && gameOver == 0) {
        system("cls");
        showTable(table);
        printf("Deu Velha, ninguem ganhou\n");
    }

    return 0;
}
