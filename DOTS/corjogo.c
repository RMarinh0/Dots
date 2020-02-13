#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void corjogo()
{

    short x=0,y=1;
    short int color=0;
    printf("Choose a color:\n");
    printf("-> BLACK\n-> BLUE\n-> WHITE\n-> RETURN TO OPTIONS");
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
                y=4;
            }
            break;
        case 'S':
        case 's':
            y++;
            if(y>4)
            {
                y=1;
            }
            break;
        case 32:
            if(y==1)
            {
                system("color 0f");
            }
            else if(y==2)
            {
                system("color 1f");
            }
            else if(y==3)
            {
                system("color f0");
            }
            else if(y==4)
            {
                system("cls");
                opcoes();
            }
            break;
        default:
            system("cls");
            corjogo();
        }
    }
}
