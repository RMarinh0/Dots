#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void instrucoes()
{
    int x=0,y=11;
    printf("CONTROLS:\n");
    printf("Movimento -> WASD/Setas\n");
    printf("Ligar/Desligar Desenho -> \"SPACE\" e \"ENTER\"\n");
    printf("Retornar ao Menu -> \"M\"\n");
    printf("COMO JOGAR:\n");
    printf("-> Cada jogador tem direito a desenhar uma linha na matriz;\n");
    printf("-> Um jogador pontua quando completa o desenho de um quadrado; \n");
    printf("-> Vence aquele que possuir o maior numero de pontos enquanto o desenho for possivel;\n");
    printf("-> O primeiro a jogar sera sempre o jogador;ng  1\n");
    printf("-> O vencedor tera suas iniciais gravadas no Hall dos Campeoes");
    printf("-> RETURN TO MENU");
    while(1)
    {
        gotoxy(x,y);
        switch(getch())
        {
        case 'W':
        case 'w':
            y--;
            if(y<11)
            {
                y=12;
            }
            break;
        case 'S':
        case 's':
            y++;
            if(y>12)
            {
                y=11;
            }
            break;
        case 32:
            if(y==11)
            {
                system("cls");
                level();
            }
            else if(y==12)
            {
                system("cls");
                menu();
            }
        }
    }
}
