#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int opcao = 0, fila, carros, abastecimento, atendrel;
  float preco, pausa, tanque, gasolina, gasorel, vendasrel;
  char opcao2 = ' ';
  preco = 0, carros=0, fila = 0, atendrel = 0, tanque = 200, gasolina = 0, gasorel = 0, vendasrel = 0;
  
  while (preco <= 0) {
    printf("Por favor, informe o preço da gasolina se precisar "
           "use ponto para valores não inteiros:\n");
    scanf("%f", &preco);
  }
  printf(" \n");
  while (fila <= 0) {
    printf(
        "Por favor, informe a quantidade de carros máxima que a"
        " fila terá:\n");
    scanf("%d", &fila);
    printf(" \n");
  }
  system("clear");
  while (opcao != 5) { 
    printf("\n                            =MENU=                           \n");
    printf(" \n\n\n");
    printf("Carros na fila: %d\n\n", carros);
    printf("(1) Adicionar um carro a fila\n"
           "(2) Abastecimento\n"
           "(3) Exibir "
           "carros na fila de espera\n"
           "(4) Relatórios\n" 
           "(5) Encerrar\n");
    printf("\nPor favor, escolha uma das opções.\n");
    scanf("\n%d", &opcao);
    switch (opcao) {
      case 1:
      system("clear");
        if (carros == fila) {
        printf("\nTamanho de fila máximo atingido.\n");
        } else {
        printf("\nCarro adicionado na fila.\n");
        carros += 1;
        }
        break;
      case 2:
        system("clear");
        if (carros==0){
          printf("\nNão é possível abastecer pois não há nenhum carro na fila.\n");
          } else {
          if (carros>=1){
            while (gasolina<=0) {
            printf("Abastecer com quantos litros? OBS: Até 2 casas " 
                   "decimais.");
                scanf("%f", &gasolina);
              }
              if ((tanque-gasolina)>0){
            vendasrel = gasolina*preco;
            tanque -= gasolina;
            atendrel = atendrel + 1;
            gasorel = gasorel + gasolina;
            carros -= 1;
            gasolina=0;
              } else {
              if (tanque-gasolina<0){
                printf("Não há gasolina o suficiente no tanque para essa"
                       "quantidade");
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
          printf("\nA - Quantidade de litros vendida.\n" 
                 "B - Valor total arrecadado com as vendas.\n"
                 "C - Quantidade de carros atendidos.\n" 
                 "D - Quantidade de combustível restante no" 
                 "tanque.\n" 
                 "E - Gerar arquivo para impressão (com todas as"
                 "informações de A,B,C e D.\n"
                 "F - Voltar ao menu anterior.\n");
          printf("\nPor favor escolha uma das opções. ");
          scanf("\n%c", &opcao2);
          switch (opcao2) {
          case 'A':
            system("clear");
            printf("\nA quantidade de litros vendida é: %2.f\n", gasorel);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'B':
            system("clear");
            printf("\nValor total arrecadado: %2.f\n", vendasrel);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'C':
            system("clear");
            printf("\nQuantidade de carros atendida é: %d\n", atendrel);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'D':
            system("clear");
            printf("\nQuantidade de combustível restante no " 
                   "tanque é: %2.f\n", tanque);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'E':
            system("clear");
            printf("\nArquivo para impressão:\n A : %.2f.\n B :" 
                   "%2.f.\n C : %d.\n D : %2.f.\n", gasorel, vendasrel, atendrel, tanque);
            scanf("%f", &pausa);
            system("clear");
            break;
          case 'F':
            system("clear");
            printf("\nVoltando ao outro menu.\n");
            break;
          default:
            printf("\n               " "Opção fora do escopo.\n");
            break;
          }
        }
        break;
      case 5:
        system("clear");
        printf("Encerrando programa.");
        exit(0);
        break;
      default:
        printf("Opção não conhecida.");
        break;
      }
    }
    return 0;
  }