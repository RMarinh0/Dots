#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "showranking.h"
void menu()
{

    short int x=0,y=0;
    printf("-> START\n-> OPTIONS\n-> CREDITS\n-> RANKING\n-> EXIT\n");
    while(1)
    {
        gotoxy(x,y);
        switch(getch())
        {
        case 'W':
        case 'w':
            y--;
            if(y<0)
            {
                y=4;
            }
            break;
        case 'S':
        case 's':
            y++;
            if(y>4)
            {
                y=0;
            }
            break;
        case 32:
            if(y==0)
            {
                system("cls");
                instrucoes();
            }
            else if(y==1)
            {
                system("cls");
                opcoes();
            }
            else if(y==2)
            {
                system("cls");
                creditos();
            }
            else if(y==3)
            {
                system("cls");
                showranking();
            }
            else if(y==4)
            {
                system("cls");
                printf("THANKS FOR PLAYING!!");
                exit(0);
            }
            break;
        default:
            system("cls");
            menu();
        }
    }
}
