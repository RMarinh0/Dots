#include <stdio.h>
#include <stdlib.h>
void showranking()
{  printf("======== HALL OF CHAMPIONS ========\n\n");

     FILE *show;

    struct{
        char iniciais[3];
        int pontos;
    }vencedor;

   show=fopen("rankingjogo.dat","rb");
   while(fread(&vencedor,sizeof(vencedor),1,show)!= 0){
   printf("%s --> %d\n", vencedor.iniciais, vencedor.pontos);
   }
   printf("\nPRESS ANY BUTTON TO RETURN TO THE MENU...\n");
    char i;
    i=getch();
    system("cls");
    menu();
   fclose(show);
    return 0;
}
