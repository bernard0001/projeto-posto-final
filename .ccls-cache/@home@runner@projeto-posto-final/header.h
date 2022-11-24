#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\e[0;31m"
#define WHT "\e[0;37m"
#define GRN "\e[0;32m"
#define MAG "\e[0;35m"
#define BLK "\e[0;30m"
#define BLU "\e[0;34m"
#define YEL "\e[0;33m"
//Função de espera para pausas.
void espera(){
  printf(GRN"\nAperte enter para continuar...\n"WHT);
  getchar();
  }
//Função de validação de variável.
float teste(char *gol){
  float teste1 = 0;
  while (teste1<=0){
  printf("%s%s", MAG, gol);
    scanf("%f", &teste1);
    }
return(teste1);
  }
//Função de menu.
void menu(int fila, float tanque, float preco){
printf(MAG"\n                            =MENU=                           \n\n\n");
  printf("Preço da gasolina:"GRN" %.2f\n\n"MAG, preco);
  printf("Carros na fila:"GRN" %d\n\n"MAG, fila);
  if(tanque>100){ 
    printf("Gasolina disponível no tanque:"GRN" %.2f\n\n"MAG, tanque);
  } else if (tanque>50){
    printf("Gasolina disponível no tanque:"YEL" %.2f\n\n"MAG, tanque);
  } else {
    printf("Gasolina disponível no tanque:"RED" %.2f\n\n"MAG, tanque);
    }
  printf("("GRN"1"MAG") Adicionar um carro a fila\n"
           "("GRN"2"MAG") Abastecimento\n"
           "("GRN"3"MAG") Exibir carros na fila de espera\n"
           "("GRN"4"MAG") Relatórios\n" 
           "("GRN"5"MAG") Encerrar\n");
    printf("\nPor favor, escolha uma das opções.\n"WHT);
}
//Função de adição de carros a fila.
void addcarro(int *carros, int fila){
        if (*carros == fila) {
          printf(RED"\n                Tamanho de fila máximo atingido.\n"WHT);
        } else {
        printf(GRN"\n                  Carro adicionado na fila.\n"WHT);
        *carros += 1;
        }
  }
//Função de flush.
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}
struct Tcarro{
  char placa[15];
  char cor[20];
  char modelo[25];
  int ano;
  float Gvalor;
  float Glitro;
};
