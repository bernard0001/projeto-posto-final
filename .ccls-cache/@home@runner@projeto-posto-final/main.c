#include <stdio.h>

int main(void) {
  int opcao = 0;
  float preco;
  int fila;
  int carros;
  char opcao2;

  carros = 0;
  printf("Seja bem vindo ao programa do programador Bernard Moreno, o mesmo "
         "possui a intenção de agilizar e melhorar a gestão de postos de "
         "gasolina através de diversos comandos e funcionalidades utéis.\n");
  printf(" \n");
  printf("Por favor, informe o preço da gasolina se precisar use ponto para "
         "valores não inteiros:\n");
  scanf("%f", &preco);
  printf(" \n");
  printf(
      "Por favor, informe a quantidade de carros que se encontram na fila:\n");
  scanf("%d", &fila);
  printf(" \n");
  while (opcao != 5) {
    printf("                            =MENU=                           \n");
    printf(" \n\n");
    printf(" ");
    printf("Carros na fila: %d\n", carros);
    printf(" \n");
    printf(" (1) Adicionar um carro a fila\n (2) Abastecimento\n (3) Exibir "
           "carros na fila de espera\n (4) Relatórios\n (5) Encerrar\n");
    printf("\nPor favor, escolha uma das opções.");
    scanf("\n%d", &opcao);
    switch (opcao) {
    case 1:
      printf("\nCarro adicionado na fila.\n");
      carros++;
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      printf("\n A - Quantidade de litros vendida.\n B - Valor total arrecadado"
             "com as vendas.\n C - Quantidade de carros atendidos.\n D - "
             "Quantidade de combustível restante no tanque.\n E - Gerar "
             "arquivo para impressão (com todas as informações de A,B,C e D.\n "
             "F - Voltar ao menu anterior.\n");
      printf("\nPor favor escolha uma das opções. ");
      scanf("\n%c", &opcao2);
      break;
    case 5:
      printf("Encerrando programa.");
      break;
    default:
      printf("Opção não conhecida.");
      break;
    }
  }
  return 0;
}