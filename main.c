#include <stdio.h>

int main(void) {
  int opcao = 0;
  float preco;
  int fila;
  int carros;
  char opcao2 =' ' ;
  float pausa;
  
  carros = 0;
  printf("Seja bem vindo ao programa do programador Bernard Moreno, o mesmo "
         "possui a intenção de agilizar e melhorar a gestão de postos de "
         "gasolina através de diversos comandos e funcionalidades utéis.\n\n");
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
     while(opcao2!='F'){ 
       printf("\n A - Quantidade de litros vendida.\n B - Valor total arrecadado"
             "com as vendas.\n C - Quantidade de carros atendidos.\n D - "
             "Quantidade de combustível restante no tanque.\n E - Gerar "
             "arquivo para impressão (com todas as informações de A,B,C e D.\n "
             "F - Voltar ao menu anterior.\n");
      printf("\nPor favor escolha uma das opções. ");
      scanf("\n%c", &opcao2);
      switch (opcao2){
        case 'A':
          printf("\nA quantidade de litros vendida é: XX\n");
          break;
          case 'B':
            printf("\nValor total arrecadado: XX\n");
          break;
            case 'C':
              printf("\nQuantidade de carros atendida é: XX\n");
            break;
              case 'D':
                printf("\nQuantidade de combustível restante no tanque é: XX\n");
              break;
                case 'E':
                  printf("\nArquivo para impressão:\n A - XX.\n B - XX.\n C - XX\n D - XX.\n");
                break;
                  case 'F':
                    printf("\nVoltando ao outro menu.\n");
                  break;  
        default:
          printf("\nOpção fora do escopo.\n");
        break;
        }
       } 
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