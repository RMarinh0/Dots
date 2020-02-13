#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "resultado.h"
#include "menu.h"
#include "gotoxy.h"

void level()
{
    int getch();
    char tamanhotab[8][8];
    int l, m, desenhe = 0, pontos_pl1=0, pontos_pl2=0,*pontos_1=&pontos_pl1,*pontos_2=&pontos_pl2;
    short x = 0, y = 0, player=0, i = 0, xmax = 4, ymax = 2,c=1;
    for(l=0; l<8; l++)
    {
        for(m=0; m<8; m++)
        {
            if(l%2==0&&m%2==0)
            {
                tamanhotab[l][m]='*';
                printf("%c",tamanhotab[l][m]);
                if(m!=8-1)
                {
                    printf("     ");
                }

            }
            else
            {
                tamanhotab[l][m]=' ';
                printf("%c",tamanhotab[l][m]);
                if(m!=8-1)
                {
                    printf("     ");
                }
            }
        }
        printf("\n\n\n");
    }

    for(l=0;l<11;l++)
    {
        gotoxy(45,l);
        for(m=0;m<15;m++)
        {
            if( (m==0) || (l==10) || (l==0) || (m==14) )
            {
                printf("*");
            }
            else printf(" ");
        }
    }

    gotoxy(47,1);
    printf("TURNO:");
    gotoxy(47,2);
    printf("PLAYER: 1");
    gotoxy(47,4);
    printf("PONTOS:");
    gotoxy(47,5);
    printf("PLAYER 1: %d",*pontos_1);
    gotoxy(47,6);
    printf("PLAYER 2: %d",*pontos_2);
    gotoxy(47,9);
    printf("\"M\" -> MENU");


    if(8==8)
    {
        xmax=xmax*9;
        ymax=ymax*9;
    }
    if(8==12)
    {
        xmax=xmax*15;
        ymax=ymax*15;
    }
    while(c==1)
    {
        if(pontos_pl1 + pontos_pl2 < 9)
        {
            gotoxy(x,y);
            switch(getch())
            {
            case 'w':
            case 'W':
            case 72:
                if(desenhe == 1 && y>0)
                {
                    for(i=y; i > y-7; i--)
                    {
                        gotoxy(x,i);
                        if(i==y||i==y-6)
                        {
                            printf("*");
                        }
                        else
                            printf("%c", 124);
                    }
                    desenhe=!desenhe;
                    tamanhotab[(y-3)/3][x/6]=124;
                    if(x==0 && tamanhotab[(y-6)/3][(x+6)/6]=='-' && tamanhotab[(y-3)/3][(x+12)/6]==124 && tamanhotab[y/3][(x+6)/6]=='-' && tamanhotab[(y-3)/3][x/6]==124 && tamanhotab[(y-3)/3][(x+6)/6]==' ')
                    {

                        if(player==0)
                        {
                            tamanhotab[(y-3)/3][(x+6)/6]='1';
                            pontos_pl1+=1;
                        }
                        else if(player==1)
                        {
                            tamanhotab[(y-3)/3][(x+6)/6]='2';
                            pontos_pl2+=1;
                        }
                        gotoxy(x+6,y-3);
                        printf("%c",tamanhotab[(y-3)/3][(x+6)/6]);
                        gotoxy(x,y-6);
                        player=!player;


                    }
                    else if(x==36 && tamanhotab[(y-3)/3][x/6]== 124 && tamanhotab[(y-6)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x-12)/6]== 124 && tamanhotab[y/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x-6)/6]== ' ')
                    {

                        if(player==0)
                        {
                            tamanhotab[(y-3)/3][(x-6)/6]= '1';
                            pontos_pl1+=1;
                        }
                        else if(player==1)
                        {
                            tamanhotab[(y-3)/3][(x-6)/6]= '2';
                            pontos_pl2+=1;
                        }
                        gotoxy(x-6,y-3);
                        printf("%c",tamanhotab[(y-3)/3][(x-6)/6]);
                        gotoxy(x,y-6);
                        player=!player;


                    }
                    else if(x!=0 && x!=36)
                    {

                        if(tamanhotab[(y-6)/3][(x+6)/6]=='-' && tamanhotab[(y-3)/3][(x+12)/6]==124 && tamanhotab[y/3][(x+6)/6]=='-' && tamanhotab[(y-3)/3][x/6]==124 && tamanhotab[(y-3)/3][x/6]== 124 && tamanhotab[(y-6)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x-12)/6]== 124 && tamanhotab[y/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x+6)/6]==' ' && tamanhotab[(y-3)/3][(x-6)/6]== ' ')
                        {
                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='1';
                                tamanhotab[(y-3)/3][(x-6)/6]='1';
                                pontos_pl1+=2;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='2';
                                tamanhotab[(y-3)/3][(x-6)/6]='2';
                                pontos_pl2+=2;
                            }
                            gotoxy(x+6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x+6)/6]);
                            gotoxy(x-6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x-6)/6]);
                            gotoxy(x,y-6);
                            player=!player;
                        }
                        else if(tamanhotab[(y-3)/3][(x+6)/6] == ' ' && tamanhotab[(y-3)/3][(x-6)/6] == 'X' && tamanhotab[(y-3)/3][(x)/6] == 124 && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x+12)/6] == 124 && tamanhotab[(y-6)/3][(x+6)/6] == '-' )
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x+6)/6]);
                            gotoxy(x,y-6);
                            player=!player;
                        }
                        else if(tamanhotab[(y-3)/3][(x+6)/6] == 'X' && tamanhotab[(y-3)/3][(x-6)/6] == ' ' && tamanhotab[(y-3)/3][(x)/6] == 124 && tamanhotab[(y-6)/3][(x-6)/6] == '-' && tamanhotab[(y-3)/3][(x-12)/6] == 124 && tamanhotab[(y)/3][(x-6)/6] == '-')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6] = '1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6] = '2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x-6)/6]);
                            gotoxy(x,y-6);
                            player=!player;

                        }
                        else if(tamanhotab[(y-3)/3][(x+6)/6] == ' ' && tamanhotab[(y-3)/3][(x)/6] == 124 && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x+12)/6] == 124 && tamanhotab[(y-6)/3][(x+6)/6] == '-')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x+6)/6]);
                            gotoxy(x,y-6);
                            player=!player;
                        }
                        else if(tamanhotab[(y-3)/3][(x-6)/6] == ' ' && tamanhotab[(y-3)/3][(x)/6] == 124 && tamanhotab[(y-6)/3][(x-6)/6] == '-' && tamanhotab[(y-3)/3][(x-12)/6] == 124 && tamanhotab[(y)/3][(x-6)/6] == '-')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6] = '1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6] = '2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x-6)/6]);
                            gotoxy(x,y-6);
                            player=!player;
                        }

                    }
                    player=!player;
                }
                y-=6;
                if(y<0)
                {
                    y=ymax;
                }
                break;
            case 'a':
            case 'A':
            case 75:
                if(desenhe == 1 && x>0)
                {
                    gotoxy(x-12,y);
                    printf("*-----------*");
                    gotoxy(x-12,y);
                    desenhe=!desenhe;
                    tamanhotab[(y)/3][(x-6)/6]='-';
                    if(x!=0 && y==0)
                    {

                        if(tamanhotab[y/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][(x-12)/6]== 124 && tamanhotab[(y+6)/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][x/6]== 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x-6)/6]);
                            gotoxy(x-12,y);
                            player=!player;
                        }

                    }
                    else if(x!=0 && y==18)
                    {

                        if(tamanhotab[(y)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x-12)/6]== 124 && tamanhotab[(y-6)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x)/6]== 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x-6)/6]);
                            gotoxy(x-12,y);
                            player=!player;
                        }
                    }
                    else if(y>0 && y<18 && x!=0)
                    {

                        if(tamanhotab[(y+3)/3][(x-6)/6] == ' ' && tamanhotab[y/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][(x-12)/6]== 124 && tamanhotab[(y+6)/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][x/6]== 124 && tamanhotab[(y-3)/3][(x-6)/6] == ' ' && tamanhotab[(y)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x-12)/6]== 124 && tamanhotab[(y-6)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x)/6]== 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='1';
                                tamanhotab[(y-3)/3][(x-6)/6]='1';
                                pontos_pl1+=2;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='2';
                                tamanhotab[(y-3)/3][(x-6)/6]='2';
                                pontos_pl2+=2;
                            }
                            gotoxy(x-6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x-6)/6]);
                            gotoxy(x-6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x-6)/6]);
                            gotoxy(x-12,y);
                            player=!player;

                        }
                        else if(tamanhotab[(y+3)/3][(x-6)/6] == ' ' && tamanhotab[y/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][(x-12)/6]== 124 && tamanhotab[(y+6)/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][x/6]== 124 && tamanhotab[(y-3)/3][(x-6)/6] == 'X')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x-6)/6]);
                            gotoxy(x-12,y);
                            player=!player;

                        }
                        else if(tamanhotab[(y+3)/3][(x-6)/6] == 'X' && tamanhotab[(y-3)/3][(x-6)/6] == ' ' && tamanhotab[(y)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x-12)/6]== 124 && tamanhotab[(y-6)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x)/6]== 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x-6)/6]);
                            gotoxy(x-12,y);
                            player=!player;
                        }
                        else if(tamanhotab[(y+3)/3][(x-6)/6] == ' ' && tamanhotab[y/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][(x-12)/6]== 124 && tamanhotab[(y+6)/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][x/6]== 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x-6)/6]);
                            gotoxy(x-12,y);
                            player=!player;
                        }
                        else if(tamanhotab[(y-3)/3][(x-6)/6] == ' ' && tamanhotab[(y)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x-12)/6]== 124 && tamanhotab[(y-6)/3][(x-6)/6]== '-' && tamanhotab[(y-3)/3][(x)/6]== 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x-6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x-6)/6]);
                            gotoxy(x-12,y);
                            player=!player;
                        }

                    }
                    player=!player;
                }
                x-=12;
                if(x<0)
                {
                    x=xmax;
                }
                break;
            case 's':
            case 'S':
            case 80:
                if(desenhe == 1 && y<ymax)
                {
                    for(i=y; i < y+7; i++)
                    {
                        gotoxy(x,i);
                        if(i==y||i==y+6)
                        {
                            printf("*");
                        }
                        else
                            printf("%c",124);
                    }
                    desenhe=!desenhe;
                    tamanhotab[(y+3)/3][(x)/6]= 124;
                    if(x==0)
                    {
                        if(tamanhotab[(y+3)/3][(x+6)/6]== ' ' && tamanhotab[(y+3)/3][(x)/6]== 124 && tamanhotab[(y+6)/3][(x+6)/6]== '-' && tamanhotab[(y+3)/3][(x+12)/6]== 124 && tamanhotab[(y)/3][(x+6)/6]== '-')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6]= '1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6]= '2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x+6)/6]);
                            gotoxy(x,y+6);
                            player=!player;
                        }
                    }
                    else if(x==36)
                    {
                        if(tamanhotab[(y+3)/3][(x-6)/6]== ' ' && tamanhotab[(y+3)/3][(x)/6]== 124 && tamanhotab[(y+6)/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][(x-12)/6]== 124 && tamanhotab[(y)/3][(x-6)/6]== '-')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x-6)/6]);
                            gotoxy(x,y+6);
                            player=!player;
                        }

                    }
                    else if(x!=0 && x!=36)
                    {
                        if(tamanhotab[(y+3)/3][(x+6)/6]== ' ' && tamanhotab[(y+3)/3][(x)/6]== 124 && tamanhotab[(y+6)/3][(x+6)/6]== '-' && tamanhotab[(y+3)/3][(x+12)/6]== 124 && tamanhotab[(y)/3][(x+6)/6]== '-' && tamanhotab[(y+3)/3][(x-6)/6]== ' ' && tamanhotab[(y+3)/3][(x)/6]== 124 && tamanhotab[(y+6)/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][(x-12)/6]== 124 && tamanhotab[(y)/3][(x-6)/6]== '-')
                        {



                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6]= '1';
                                tamanhotab[(y+3)/3][(x-6)/6]='1';
                                pontos_pl1+=2;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6]= '2';
                                tamanhotab[(y+3)/3][(x-6)/6]='2';
                                pontos_pl2+=2;
                            }
                            gotoxy(x+6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x+6)/6]);
                            gotoxy(x-6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x-6)/6]);
                            gotoxy(x,y+6);
                            player=!player;
                        }
                        else if(tamanhotab[(y+3)/3][(x+6)/6]== ' ' && tamanhotab[(y+3)/3][(x)/6]== 124 && tamanhotab[(y+6)/3][(x+6)/6]== '-' && tamanhotab[(y+3)/3][(x+12)/6]== 124 && tamanhotab[(y)/3][(x+6)/6]== '-' && tamanhotab[(y+3)/3][(x-6)/6]== 'X')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6]= '1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6]= '2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x+6)/6]);
                            gotoxy(x,y+6);
                            player=!player;
                        }
                        else if(tamanhotab[(y+3)/3][(x-6)/6]== ' ' && tamanhotab[(y+3)/3][(x)/6]== 124 && tamanhotab[(y+6)/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][(x-12)/6]== 124 && tamanhotab[(y)/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][(x+6)/6]== 'X')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x-6)/6]);
                            gotoxy(x,y+6);
                            player=!player;
                        }
                        else if(tamanhotab[(y+3)/3][(x+6)/6]== ' ' && tamanhotab[(y+3)/3][(x)/6]== 124 && tamanhotab[(y+6)/3][(x+6)/6]== '-' && tamanhotab[(y+3)/3][(x+12)/6]== 124 && tamanhotab[(y)/3][(x+6)/6]== '-')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6]= '1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6]= '2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x+6)/6]);
                            gotoxy(x,y+6);
                            player=!player;
                        }
                        else if(tamanhotab[(y+3)/3][(x-6)/6]== ' ' && tamanhotab[(y+3)/3][(x)/6]== 124 && tamanhotab[(y+6)/3][(x-6)/6]== '-' && tamanhotab[(y+3)/3][(x-12)/6]== 124 && tamanhotab[(y)/3][(x-6)/6]== '-')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x-6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x-6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x-6)/6]);
                            gotoxy(x,y+6);
                            player=!player;
                        }
                    }
                    player=!player;
                }
                y+=6;
                if(y>ymax)
                {
                    y=0;
                }
                break;
            case 'd':
            case 'D':
            case 77:
                if(desenhe == 1 && x<xmax)
                {
                    printf("*-----------*");
                    desenhe=!desenhe;
                    tamanhotab[y/3][(x+6)/6]= '-';
                    if(x!=36 && y==0)
                    {
                        if(tamanhotab[(y+3)/3][(x+6)/6]== ' ' && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y+3)/3][(x+12)/6] == 124 && tamanhotab[(y+6)/3][(x+6)/6] == '-' && tamanhotab[(y+3)/3][(x)/6] == 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6] = '1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6] = '2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x+6)/6]);
                            gotoxy(x+12,y);
                            player=!player;
                        }
                    }
                    else if(x!=36 && y==18)
                    {
                        if(tamanhotab[(y-3)/3][(x+6)/6] == ' ' && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x+12)/6] == 124 && tamanhotab[(y-6)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x)/6] == 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x+6)/6]);
                            gotoxy(x+12,y);
                            player=!player;
                        }
                    }
                    else if (x!=36 && y>0 && y<18)
                    {
                        if(tamanhotab[(y+3)/3][(x+6)/6]== ' ' && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y+3)/3][(x+12)/6] == 124 && tamanhotab[(y+6)/3][(x+6)/6] == '-' && tamanhotab[(y+3)/3][(x)/6] == 124 && tamanhotab[(y-3)/3][(x+6)/6] == ' ' && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x+12)/6] == 124 && tamanhotab[(y-6)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x)/6] == 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6] = '1';
                                tamanhotab[(y-3)/3][(x+6)/6]='1';
                                pontos_pl1+=2;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6] = '2';
                                tamanhotab[(y-3)/3][(x+6)/6]='2';
                                pontos_pl2+=2;
                            }
                            gotoxy(x+6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x+6)/6]);
                            gotoxy(x+6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x+6)/6]);
                            gotoxy(x+12,y);
                            player=!player;
                        }
                        else if(tamanhotab[(y+3)/3][(x+6)/6]== ' ' && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y+3)/3][(x+12)/6] == 124 && tamanhotab[(y+6)/3][(x+6)/6] == '-' && tamanhotab[(y+3)/3][(x)/6] == 124 && tamanhotab[(y-3)/3][(x+6)/6] == 'X')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6] = '1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6] = '2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x+6)/6]);
                            gotoxy(x+12,y);
                            player=!player;
                        }
                        else if(tamanhotab[(y-3)/3][(x+6)/6] == ' ' && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x+12)/6] == 124 && tamanhotab[(y-6)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x)/6] == 124 && tamanhotab[(y+3)/3][(x+6)/6]== 'X')
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x+6)/6]);
                            gotoxy(x+12,y);
                            player=!player;
                        }
                        else if(tamanhotab[(y+3)/3][(x+6)/6]== ' ' && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y+3)/3][(x+12)/6] == 124 && tamanhotab[(y+6)/3][(x+6)/6] == '-' && tamanhotab[(y+3)/3][(x)/6] == 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6] = '1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y+3)/3][(x+6)/6] = '2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y+3);
                            printf("%c",tamanhotab[(y+3)/3][(x+6)/6]);
                            gotoxy(x+12,y);
                            player=!player;
                        }
                        else if(tamanhotab[(y-3)/3][(x+6)/6] == ' ' && tamanhotab[(y)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x+12)/6] == 124 && tamanhotab[(y-6)/3][(x+6)/6] == '-' && tamanhotab[(y-3)/3][(x)/6] == 124)
                        {


                            if(player==0)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='1';
                                pontos_pl1+=1;
                            }
                            else if(player==1)
                            {
                                tamanhotab[(y-3)/3][(x+6)/6]='2';
                                pontos_pl2+=1;
                            }
                            gotoxy(x+6,y-3);
                            printf("%c",tamanhotab[(y-3)/3][(x+6)/6]);
                            gotoxy(x+12,y);
                            player=!player;
                        }
                    }
                    player=!player;
                }
                x+=12;
                if(x>xmax)
                {
                    x=0;
                }

                break;
            case 32:
            case 13:
                desenhe = !desenhe;
                break;
            case 'm':
                system("cls");
                menu();

            }

        }
        else
        {
            c=!c;
            system("cls");
            resultado(pontos_pl1,pontos_pl2);
        }

    gotoxy(47,2);
    if(player==0)
        printf("PLAYER: 1");
    else
        printf("PLAYER: 2");

    gotoxy(47,5);
    printf("PLAYER 1: %d",*pontos_1);
    gotoxy(47,6);
    printf("PLAYER 2: %d",*pontos_2);
    }

}
