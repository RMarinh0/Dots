#include <stdio.h>
  struct{
        char iniciais[3];
        int pontos;
    }jogador;


int enterranking(int vencedor)
{  int tamanhoranking=0;
   int i=0;
   char caractere;

    FILE *rank;
    rank=fopen("rankingjogo.dat","ab");
    printf("SUBMIT YOUR INITIALS:  ");
    fflush(stdin);
    do{
    caractere=getchar();
    if(caractere>='A'&&caractere<='Z'||caractere>='a'&&caractere<='z')
    {
        if(caractere>=97&&caractere<=122){
            caractere=caractere-32;
        }
    jogador.iniciais[i]=caractere;
    }else{
      --i;
    }
    ++i;
  }while(caractere!='\n'&&i<=2);
    jogador.iniciais[i]='\0';
    printf("PLAYER: %s\n", jogador.iniciais);
    jogador.pontos = vencedor;
    printf("PONTUACAO: %i\n", jogador.pontos);
    fwrite(&jogador,sizeof(jogador), 1, rank);
    fclose(rank);
    system("pause");
    system("cls");
    menu();
}
