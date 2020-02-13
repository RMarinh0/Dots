#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void opcoes()
{
    int x=0,y=1;
    printf("OPTIONS:\n");
    printf("--> BACKGROUND COLOR\n--> INSTRUCTIONS\n--> RETURN TO MENU\n");
    while(1)
    {
        gotoxy(x,y);
        switch(getch())
        {
        case 'W':
        case 'w':
            y--;
            if(y<1)
            {
                y=3;
            }
            break;
        case 'S':
        case 's':
            y++;
            if(y>3)
            {
                y=1;
            }
            break;
        case 32:
            if(y==1)
            {
                system("cls");
                corjogo();
            }
            else if(y==2)
            {
                system("cls");
                instrucoes();
            }
            else if(y==3)
            {
                system("cls");
                menu();
            }
            break;
        default:
            system("cls");
            opcoes();
        }
    }
}
