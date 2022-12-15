#include "header.h" //file com funções.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //biblioteca de tempo e data.

int main(void) {
  int opcao = 0, atendimento = 0, fila = 0, carros = 0, abastecimento,
      atendrel = 0, opcaogas2 = 0, contfila = 0, tamanhofila = 0, i = 0,
      tamanhoatend = 1, contrel = 0;
  float preco = 0, pausa, tanque = 200, gasolina = 0, gasorel = 0,
        vendasrel = 0;
  char opcao2 = ' ', opcaogas = ' ', nomearqui[20];

  struct Tcarro *filacarro;
  struct Tcarro *atendimentos;

  preco = teste("Por favor, informe o preço da gasolina se precisar "
                "use ponto para valores não inteiros:\n" WHT);
  system("clear");
  tamanhofila = teste2("Por favor, informe a quantidade de carros máxima que a"
                       " fila terá:\n" WHT); // Validações checando se o valor
                                             // informado é negativo ou não.
  filacarro = (struct Tcarro *)calloc(tamanhofila, sizeof(struct Tcarro));
  atendimentos = (struct Tcarro *)calloc(0, sizeof(struct Tcarro));
  if (filacarro == NULL) {
    printf(RED "Memória insuficiente para o tamanho da fila inserido." WHT);
    exit(0);
  }
  system("clear");
  while (opcao != 5) {
    menu(fila, tanque, preco);
    scanf("\n%d", &opcao);
    switch (opcao) {
    case 1:
      system("clear");
      if (tanque == 0) {
        printf(RED "Não é possível adicionar carros na fila pois não há "
                   "gasolina no tanque.\n" WHT);
      } else {
        if (fila <
            tamanhofila) { // Uso de fgets e flush in para informar valores que
                           // entrarão em posições da fila de carros.
          printf(MAG "Informe a placa do carro:\n" WHT);
          flush_in();
          fgets(filacarro[fila].placa, 15, stdin);
          filacarro[fila].placa[strcspn(filacarro[fila].placa, "\n")] = 0;

          printf(MAG "Informe o modelo do carro:\n" WHT);
          fgets(filacarro[fila].modelo, 25, stdin);
          filacarro[fila].modelo[strcspn(filacarro[fila].modelo, "\n")] = 0;

          printf(MAG "Informe a cor do carro:\n" WHT);
          fgets(filacarro[fila].cor, 25, stdin);
          filacarro[fila].cor[strcspn(filacarro[fila].cor, "\n")] = 0;

          filacarro[fila].ano = teste2(MAG "Informe o ano do carro:\n" WHT);
          i++;
          fila++;
          system("clear");
        } else {
          printf(RED "Não é possível adicionar carros na fila, tamanho máximo "
                     "de fila atingido.\n" WHT);
        }
      }
      break;
    case 2:
      system("clear");
      if (fila == 0) {
        printf(
            RED
            "Não é possível abastecer pois não há nenhum carro na fila.\n" WHT);
      } else {
        if (tanque == 0) { // Validação de dispensa na fila no caso do tanque
                           // estar zerado.
          printf(RED "Não há mais gasolina disponível no tanque, a fila será "
                     "dispensada.\n");
          flush_in();
          espera();
          system("clear");
          printf(RED "                     Dispensando a fila...\n" WHT);
          free(filacarro);
          fila -= fila;
        }
        if (fila >= 1) {
          while (gasolina <= 0) {
            printf(MAG "Abastecer com quantos litros? OBS: Até 2 casas "
                       "decimais.\n" WHT);
            gasolina = teste("" WHT);
            system("clear");
          }
          if ((tanque - gasolina) >= 0) {
            vendasrel += (gasolina * preco);
            tanque -= gasolina;
            gasorel += gasolina;
            fila -= 1;
            tamanhoatend++; // Cópia do carro no vetor filacarro para o vetor de
                            // atendimentos.
            atendimentos =
                realloc(atendimentos, tamanhoatend * sizeof(struct Tcarro));
            atendimentos[atendrel] = filacarro[0];
            atendimentos[atendrel].Gvalor = (gasolina * preco);
            atendimentos[atendrel].Glitro = gasolina;
            atendrel++;
            gasolina = 0;
            printf(
                GRN
                "\n\n                     Reorganizando fila...\n" WHT); // For
                                                                         // usado
                                                                         // para
                                                                         // reogarnização
                                                                         // da
                                                                         // fila.
            for (int k = 0; k < i; k++) {
              filacarro[k] = filacarro[k + 1];
            }
            i -= 1;
          } else {
            if (tanque - gasolina <
                0) { // If usado especificamente para o caso do número informado
                     // de gasolina ser maior do que há disponível no tanque.
              while ((opcaogas != 'S') && (opcaogas != 'N')) {
                printf(MAG "Não há gasolina o suficiente no tanque para "
                           "essa quantidade,gostaria de abastecer com o que"
                           " resta no tanque? " GRN "S " MAG "ou" RED
                           " N\n" WHT);
                scanf("\n%c", &opcaogas);
              }
              opcaogas2 = 0;
              while (opcaogas2 != 1) {
                switch (opcaogas) {
                case 'S':
                  vendasrel += (tanque * preco);
                  gasorel += tanque;
                  fila -= 1;
                  opcaogas2 = 1;
                  tamanhoatend++;
                  atendimentos = realloc(atendimentos,
                                         tamanhoatend * sizeof(struct Tcarro));
                  atendimentos[atendrel] = filacarro[0];
                  atendimentos[atendrel].Gvalor = (tanque * preco);
                  atendimentos[atendrel].Glitro = tanque;
                  tanque -= tanque;
                  atendrel += 1;
                  gasolina = 0;
                  printf(
                      GRN
                      "\n\n                      Reorganizando fila...\n" WHT);
                  for (int k = 0; k < i; k++) {
                    filacarro[k] = filacarro[k + 1];
                  }
                  i -= 1;
                  system("clear");
                  break;
                case 'N':
                  printf(RED "\nPor favor se retire do posto e perdão "
                             "pela incoveniência.\n" WHT);
                  flush_in();
                  espera();
                  system("clear");
                  printf(
                      GRN
                      "\n\n                     Reorganizando fila...\n" WHT);
                  for (int k = 0; k < i; k++) {
                    filacarro[k] = filacarro[k + 1];
                  }
                  i -= 1;
                  fila -= 1;
                  gasolina = 0;
                  opcaogas2 = 1;
                  break;
                default:
                  printf(RED "\NOpção fora do escopo, voltando ao menu "
                             "principal." WHT);
                  scanf("%f", &pausa);
                  opcaogas2 = 1;
                  system("clear");
                  break;
                }
              }
            }
          }
        }
      }
      break;
    case 3: // Caso para a fila de espera.
      flush_in();
      system("clear");
      printf(MAG "                            =FILA DE ESPERA=                 "
                 "           \n\n");
      if (fila == 0) {
        printf("\n\n\n\n\nNão há nenhum carro na fila...\n");
      } else {
        for (int k = 0; k < i; k++) {
          printf("\n\nCarro %d\n\n", k + 1);
          printf("Modelo: %s\n", filacarro[k].modelo);
          printf("Placa: %s\n", filacarro[k].placa);
          printf("Cor: %s\n", filacarro[k].cor);
          printf("Ano: %d\n", filacarro[k].ano);
        }
      }
      espera();
      system("clear");
      break;
    case 4: // Caso para o menu realatório.
      system("clear");
      opcao2 = ' ';
      while (opcao2 != 'F') {
        printf(MAG "\nA - Quantidade de litros vendida.\n"
                   "B - Valor total arrecadado com as vendas.\n"
                   "C - Quantidade de carros atendidos.\n"
                   "D - Quantidade de combustível restante no "
                   "tanque.\n"
                   "E - Gerar arquivo para impressão (com todas as "
                   "informações de A,B,C e D.\n"
                   "F - Voltar ao menu anterior.\n");
        printf("\nPor favor escolha uma das opções. " WHT);
        scanf("\n%c", &opcao2);
        switch (opcao2) {
        case 'A':
          system("clear");
          printf(MAG "\nA quantidade de litros vendida é: %2.f litros.\n" WHT,
                 gasorel);
          flush_in();
          espera();
          system("clear");
          break;
        case 'B':
          system("clear");
          printf(MAG "\nValor total arrecadado: %2.f reais.\n" WHT, vendasrel);
          flush_in();
          espera();
          system("clear");
          break;
        case 'C':
          system("clear");
          if (atendrel == 1) {
            printf(MAG "A quantidade de carros atendidos é:" GRN " %d carro.\n",
                   atendrel);
          } else {
            printf(MAG "A quantidade de carros atendidos é:" GRN
                       " %d carros.\n",
                   atendrel);
          }
          printf("\nOs seguintes carros foram atendidos:\n");
          for (int k = 0; k < atendrel; k++) {
            printf("\nCarro %d\n\n", k + 1);
            printf(MAG "Modelo:" GRN " %s\n", atendimentos[k].modelo);
            printf(MAG "Placa:" GRN " %s\n", atendimentos[k].placa);
            printf(MAG "Cor:" GRN " %s\n", atendimentos[k].cor);
            printf(MAG "Ano:" GRN " %d\n", atendimentos[k].ano);
            printf(MAG "Valor gasto em reais:" GRN " %.2f\n",
                   atendimentos[k].Gvalor);
            printf(MAG "Gasolina comprada em litros:" GRN " %.2f\n",
                   atendimentos[k].Glitro);
          }
          flush_in();
          espera();
          system("clear");
          break;
        case 'D':
          case 'd':
          system("clear");
          printf(MAG "\nQuantidade de combustível restante no"
                     " tanque é: %2.f litros.\n" WHT,
                 tanque);
          flush_in();
          espera();
          system("clear");
          break;
        case 'E':
        case 'e':
          system("clear");
          contrel++;
          FILE *arquivo;
          sprintf(nomearqui, "Relatório_%d.txt", contrel);
          arquivo = fopen(nomearqui, "w");
          if (arquivo == NULL) {
            printf(RED "\n\n Erro de arquivo" WHT);
            exit(0);
          } else {
            fprintf(arquivo,
                    "\n                            RELATÓRIO %d                "
                    "            \n Arquivo para impressão: \n\n Quantidade de "
                    "litros vendida : %.2f.\n Valor total arrecadado :"
                    "%2.f.\n Quantidade de carros atendidos : %d.\n Quantidade "
                    "de combustível restante no tanque : %2.f.\n",
                    contrel, gasorel, vendasrel, atendrel, tanque);
            for (int i = 0; i < atendrel; i++) {
              fprintf(arquivo,
                      "\n -Carro: %d.\n -Placa do carro:%s.\n -Modelo do "
                      "carro: %s.\n -Cor do carro: %s.\n -Ano do carro: %d.\n "
                      "-Gasolina comprada(reais): %2.f.\n -Gasolina "
                      "comprada(litros): %2.f.\n",
                      i + 1, atendimentos[i].placa, atendimentos[i].modelo,
                      atendimentos[i].cor, atendimentos[i].ano,
                      atendimentos[i].Gvalor, atendimentos[i].Glitro);
            }
            fclose(arquivo); // Comando para encerrar a criação do arquivo.
            flush_in();
          }
          printf(GRN "Arquivo gerado!\n" WHT);
          espera();
          system("clear");
          break;
        case 'F':
          system("clear");
          printf(GRN "\nVoltando ao outro menu.\n" WHT);
          flush_in();
          espera();
          system("clear");
          break;
        default:
          system("clear");
          printf(RED "\n                   Opção fora do escopo.\n" WHT);
          break;
        }
      }
      break;
    case 5:
      system("clear");
      printf(MAG "Encerrando programa." WHT);
      exit(0);
      break;
    default:
      system("clear");
      printf(RED "                    Opção não conhecida.\n" WHT);
      break;
    }
  }
  return 0;
}
