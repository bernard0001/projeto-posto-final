#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loco.h"
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
//Função de espera para pausas que necessitam de 2 getchars.
void espera2(){
  printf(GRN"\nAperte enter para continuar...\n"WHT);
  getchar();
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
  char cor[15];
  char modelo[15];
  int ano;
  float Gvalor;
  float Glitro;
};
int main(void) {
  int opcao = 0,atendimento=0, fila=0, carros=0, abastecimento, atendrel=0, opcaogas2= 0, contfila=0, tamanhofila=0,i=0, tamanhoatend=1;
  float preco=0, pausa, tanque=200, gasolina=0, gasorel=0, vendasrel=0;
  char opcao2 = ' ', opcaogas = ' ';
  
  struct Tcarro *filacarro;
  struct Tcarro *atendimentos;
  
  preco = teste("Por favor, informe o preço da gasolina se precisar "
          "use ponto para valores não inteiros:\n"WHT);
  tamanhofila = teste("Por favor, informe a quantidade de carros máxima que a"
           " fila terá:\n"WHT);
  filacarro = (struct Tcarro*)calloc(tamanhofila,sizeof(struct Tcarro));  
  atendimentos = (struct Tcarro*)calloc(0,sizeof(struct Tcarro));
  if (filacarro == NULL){
    printf(RED"Memória insuficiente para o tamanho da fila inserido."WHT);
    exit(0);
    }
  system("clear");
  while (opcao != 5) { 
    menu(fila,tanque,preco);
    scanf("\n%d", &opcao);
    switch (opcao) {
      case 1:
      system("clear");
      if (tanque == 0){
        printf(RED"Não é possível adicionar carros na fila pois não há gasolina no tanque.\n"WHT);
      } else {
        if (fila<tamanhofila){
          printf(MAG"Informe a placa do carro:\n"WHT);
          flush_in();
          fgets(filacarro[fila].placa,15,stdin);
          filacarro[fila].placa[strcspn(filacarro[fila].placa, "\n")]=0;
          
          printf(MAG"Informe o modelo do carro:\n"WHT);
          fgets(filacarro[fila].modelo,15,stdin);
          filacarro[fila].modelo[strcspn(filacarro[fila].modelo, "\n")]=0;
          
          printf(MAG"Informe a cor do carro:\n"WHT);
          fgets(filacarro[fila].cor,15,stdin);
          filacarro[fila].cor[strcspn(filacarro[fila].cor, "\n")]=0;

          printf(MAG"Informe o ano do carro:\n"WHT);
          scanf("%d", &filacarro[fila].ano);

          i++;
          fila++;     
          system("clear");
          } else {
          printf(RED"Não é possível adicionar carros na fila, tamanho máximo de fila atingido.\n"WHT);
          }
      }
        break;
      case 2:
        system("clear");
        if (fila==0){
          printf(RED"Não é possível abastecer pois não há nenhum carro na fila.\n"WHT);
          } else {
          if (fila>=1){
            while (gasolina<=0) {
            printf(MAG"Abastecer com quantos litros? OBS: Até 2 casas " 
                   "decimais."WHT);
                scanf("%f", &gasolina);
              system("clear");
              }
              if ((tanque-gasolina)>=0){          
            vendasrel += (gasolina*preco);
            tanque -= gasolina;
            gasorel += gasolina;
            fila -= 1;
            tamanhoatend++;
            atendimentos=realloc(atendimentos,tamanhoatend * sizeof(struct Tcarro));
              strcpy(atendimentos[atendrel].placa, filacarro[0].placa);
                strcpy(atendimentos[atendrel].cor, filacarro[0].cor);
                  strcpy(atendimentos[atendrel].modelo, filacarro[0].modelo);
                    atendimentos[atendrel].ano = filacarro[0].ano;
                      atendimentos[atendrel].Gvalor = (gasolina*preco);
                        atendimentos[atendrel].Glitro = gasolina;
            atendrel ++;
            gasolina=0;    
                printf(GRN"\n\n                     Reorganizando fila...\n"WHT);
                for (int k = 0; k<i; k++){
                filacarro[k] = filacarro[k+1];
                  }
                i-=1;
                } else {
              if (tanque == 0){
                printf(RED"Não há mais gasolina no tanque"WHT);
                }
                if (tanque-gasolina<0){
                printf(MAG"Não há gasolina o suficiente no tanque para "                            "essa quantidade,gostaria de abastecer com o que"
                         " resta no tanque? "GRN"S "MAG"ou"RED" N"WHT);
                  scanf("\n%c", &opcaogas);
                opcaogas2=0;
                while (opcaogas2 != 1){
                switch(opcaogas){
                  case 'S':                   
                    vendasrel += (tanque*preco);
                    gasorel += tanque;
                    fila -= 1;
                    tanque -= tanque;
                    opcaogas2 = 1;                    
                    tamanhoatend++;
                    atendimentos=realloc(atendimentos,tamanhoatend * sizeof(struct Tcarro));
                    strcpy(atendimentos[atendrel].placa, filacarro[0].placa);
                    strcpy(atendimentos[atendrel].cor, filacarro[0].cor);
                    strcpy(atendimentos[atendrel].modelo, filacarro[0].modelo);
                    atendimentos[atendrel].ano = filacarro[0].ano;
                    atendimentos[atendrel].Gvalor = (gasolina*preco);
                    atendimentos[atendrel].Glitro = gasolina;
                    atendrel += 1;
                    gasolina = 0;
                    printf(GRN"\n\n                     Reorganizando fila...\n"WHT);
                for (int k = 0; k<i; k++){
                filacarro[k] = filacarro[k+1];
                  }
                i-=1;
                    system("clear");
                    break;
                  case 'N':
                    printf(RED"\nPor favor se retire do posto e perdão" 
                              "pela incoveniência."WHT);
                  espera();
                printf(GRN"\n\n                     Reorganizando fila...\n"WHT);               
                for (int k = 0; k<i; k++){
                filacarro[k] = filacarro[k+1];
                  }
                i-=1;                 
                  fila -= 1;
                  gasolina=0;
                    opcaogas2=1;
                    system ("clear");
                    break;
                  default:
                  printf(RED"\NOpção fora do escopo, voltando ao menu "
                            "principal."WHT);
                    scanf("%f", &pausa);
                    opcaogas2=1;
                    system("clear");
                    break;
                  }
                  } 
              }
              }
            }
          }
        break;
      case 3:
      flush_in();
      system("clear");
      printf(MAG"                            =FILA DE ESPERA=                            \n\n");        
        if (fila==0){
        printf("\n\n\n\n\nNão há nenhum carro na fila...\n");
          } else{
        for (int k=0;k<i;k++){
          printf("\n\nCarro %d\n\n", k+1);
            printf("Modelo: %s\n", filacarro[k].modelo);
              printf("Placa: %s\n", filacarro[k].placa);
                printf("Cor: %s\n", filacarro[k].cor);
                  printf("Ano: %d\n", filacarro[k].ano);  
          }
        }
        espera();
        system("clear");
        break;
      case 4:
        system("clear");
        opcao2= ' ';
        while (opcao2 != 'F') {
          printf(MAG"\nA - Quantidade de litros vendida.\n" 
                 "B - Valor total arrecadado com as vendas.\n"
                 "C - Quantidade de carros atendidos.\n" 
                 "D - Quantidade de combustível restante no " 
                 "tanque.\n" 
                 "E - Gerar arquivo para impressão (com todas as "
                 "informações de A,B,C e D.\n"
                 "F - Voltar ao menu anterior.\n");
          printf("\nPor favor escolha uma das opções. "WHT);
          scanf("\n%c", &opcao2);
          switch (opcao2) {
          case 'A':
            system("clear");
            printf(MAG"\nA quantidade de litros vendida é: %2.f\n"WHT, gasorel);
            espera2();
            system("clear");
            break;
          case 'B':
            system("clear");
            printf(MAG"\nValor total arrecadado: %2.f\n"WHT, vendasrel);
            espera2();
            system("clear");
            break;
          case 'C':
            system("clear");
          printf(MAG"A quantidade de carros atendidos é:"GRN" %d\n", atendrel);
          printf("\nOs seguintes carros foram atendidos:\n");        
          for (int k=0;k<atendrel;k++){        
            printf("\nCarro %d\n\n", k+1);
              printf(MAG"Modelo:"GRN" %s\n", atendimentos[k].modelo);
                printf(MAG"Placa:"GRN" %s\n", atendimentos[k].placa);
                  printf(MAG"Cor:"GRN" %s\n", atendimentos[k].cor);
                    printf(MAG"Ano:"GRN" %d\n", atendimentos[k].ano); 
                     printf(MAG"Valor gasto:"GRN" %.2f\n", atendimentos[k].Gvalor);
                      printf(MAG"Gasolina comprada em litros:"GRN" %.2f\n", atendimentos[k].Glitro);
          }  
          espera2();
            system("clear");
            break;
          case 'D':
            system("clear");
            printf(MAG"\nQuantidade de combustível restante no" 
                   " tanque é: %2.f\n"WHT, tanque);
            espera2();
            system("clear");
            break;
          case 'E':
            system("clear");
            printf(MAG"\nArquivo para impressão:\n A : %.2f.\n B :" 
                   "%2.f.\n C : %d.\n D : %2.f.\n"WHT, gasorel, vendasrel, atendrel, tanque);
            espera2();
            system("clear");
            break;
          case 'F':
            system("clear");
            printf(GRN"\nVoltando ao outro menu.\n"WHT);
            espera2();
            system("clear");
            break;
          default:
            system("clear");
            printf(RED"\n               " "Opção fora do escopo.\n"WHT);
            break;
          }
        }
        break;
      case 5:
        system("clear");
        printf(MAG"Encerrando programa."WHT);
        exit(0);
        break;
      default:
        printf(RED"                     Opção não conhecida.\n"WHT);
        getchar();
        system("clear");
        break;
      }
    } 
  return 0;
  }
  