#include <stdio.h>
#include <stdlib.h>
#define RED "\e[0;31m"
#define WHT "\e[0;37m"
#define GRN "\e[0;32m"
#define MAG "\e[0;35m"
#define BLK "\e[0;30m"
#define BLU "\e[0;34m"
//Função de espera para pausas.
void espera(){
  printf("Aperte enter para continuar\n");
  getchar();
  getchar();
  }
//Função de validação de variável.
float teste(char *gol){
  float teste1 = 0;
  while (teste1<=0){
  printf("%s%s", BLU, gol);
    scanf("%f", &teste1);
    }
return(teste1);
  }
//Função de menu.
void menu(int carros){
printf(MAG"\n                            =MENU=                           \n\n\n\n");
    printf("Carros na fila: %d\n\n", carros);
    printf("(1) Adicionar um carro a fila\n"
           "(2) Abastecimento\n"
           "(3) Exibir carros na fila de espera\n"
           "(4) Relatórios\n" 
           "(5) Encerrar\n");
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


int main(void) {
  int opcao = 0, fila, carros, abastecimento, atendrel, opcaogas2= 0;
  float preco, pausa, tanque, gasolina, gasorel, vendasrel;
  char opcao2 = ' ', opcaogas = ' ';
  preco = 0, carros=0, fila = 0, atendrel = 0, tanque = 200, gasolina = 0, gasorel = 0, vendasrel = 0;
    
  preco = teste("Por favor, informe o preço da gasolina se precisar "
          "use ponto para valores não inteiros:\n");
  fila = teste("Por favor, informe a quantidade de carros máxima que a"
           " fila terá:\n");
    system("clear");
  while (opcao != 5) { 
    menu(carros);
    scanf("\n%d", &opcao);
    switch (opcao) {
      case 1:
      system("clear");
      addcarro(&carros, fila);
        break;
      case 2:
        system("clear");
        if (carros==0){
          printf(RED"\nNão é possível abastecer pois não há nenhum carro na fila.\n"WHT);
          } else {
          if (carros>=1){
            while (gasolina<=0) {
            printf(MAG"Abastecer com quantos litros? OBS: Até 2 casas " 
                   "decimais."WHT);
                scanf("%f", &gasolina);
              system("clear");
              }
              if ((tanque-gasolina)>0){
            vendasrel += (gasolina*preco);
            tanque -= gasolina;
            atendrel += 1;
            gasorel += gasolina;
            carros -= 1;
            gasolina=0;
              } else {
              if (tanque = 0){
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
                    atendrel += 1;
                    gasorel += tanque;
                    carros -= 1;
                    tanque -= tanque;
                    gasolina=0;
                    opcaogas2 = 1;
                    system("clear");
                    break;
                  case 'N':
                    printf(RED"\NPor favor se retire do posto e perdão" 
                              "pela incoveniência."WHT);
                  scanf("%f", &pausa);
                    carros -= 1;
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
        break;
      case 4:
        system("clear");
        opcao2= ' ';
        while (opcao2 != 'F') {
          printf(MAG"\nA - Quantidade de litros vendida.\n" 
                 "B - Valor total arrecadado com as vendas.\n"
                 "C - Quantidade de carros atendidos.\n" 
                 "D - Quantidade de combustível restante no" 
                 "tanque.\n" 
                 "E - Gerar arquivo para impressão (com todas as"
                 "informações de A,B,C e D.\n"
                 "F - Voltar ao menu anterior.\n");
          printf("\nPor favor escolha uma das opções. "WHT);
          scanf("\n%c", &opcao2);
          switch (opcao2) {
          case 'A':
            system("clear");
            printf(MAG"\nA quantidade de litros vendida é: %2.f\n"WHT, gasorel);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'B':
            system("clear");
            printf(MAG"\nValor total arrecadado: %2.f\n"WHT, vendasrel);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'C':
            system("clear");
            printf(MAG"\nQuantidade de carros atendida é: %d\n"WHT, atendrel);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'D':
            system("clear");
            printf(MAG"\nQuantidade de combustível restante no " 
                   "tanque é: %2.f\n"WHT, tanque);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'E':
            system("clear");
            printf(MAG"\nArquivo para impressão:\n A : %.2f.\n B :" 
                   "%2.f.\n C : %d.\n D : %2.f.\n"WHT, gasorel, vendasrel, atendrel, tanque);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'F':
            system("clear");
            printf(GRN"\nVoltando ao outro menu.\n"WHT);
            scanf("%f", &pausa);
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
        printf(RED"Opção não conhecida."WHT);
        break;
      }
    } 
  return 0;
  }
  