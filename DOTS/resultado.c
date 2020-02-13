#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "enterranking.h"
void resultado(int player_1, int player_2)
{

    if(player_1>player_2)
    {
        printf("O JOGADOR 1 VENCEU!\n");
        printf("PLACAR:\n");
        printf("JOGADOR | PONTUACAO\n");
        printf("PLAYER 1| %d\n",player_1);
        printf("PLAYER 2| %d\n",player_2);
        system("pause");
        system("cls");
        enterranking(player_1);

    }
    else
    {

        printf("O JOGADOR 2 VENCEU!\n");
        printf("PLACAR:\n");
        printf("JOGADOR | PONTUACAO\n");
        printf("PLAYER 1| %d\n",player_1);
        printf("PLAYER 2| %d\n",player_2);
        system("pause");
        system("cls");
        enterranking(player_2);

    }


}
