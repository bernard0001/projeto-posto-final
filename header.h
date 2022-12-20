#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RED "\e[0;31m"
#define WHT "\e[0;37m"
#define GRN "\e[0;32m"
#define MAG "\e[0;35m"
#define BLK "\e[0;30m"
#define BLU "\e[0;34m"
#define YEL "\e[0;33m"

struct Tcarro {
  char placa[15];
  char cor[25];
  char modelo[25];
  int ano;
  float Gvalor;
  float Glitro;
};
// Função de espera para pausas.
void espera() {
  printf(GRN "\nAperte enter para continuar...\n" WHT);
  getchar();
}
// Função de validação de variável float com texto.
float teste(char *gol) {
  float opc;
  float teste1 = 0;
  char tmp[20];
  while (teste1 <= 0) {
    printf("%s%s", MAG, gol);
    if (!fgets(tmp, sizeof tmp, stdin))
      ;
    if (sscanf(tmp, "%f", &opc) != 1)
      ;
    teste1 = sscanf(tmp, "%f", &opc);
    if (teste1 == EOF) {
      teste1 = 0;
    }
  }
  return (opc);
}
// Função de validação de variável int com texto.
int teste2(char *gol) {
  int opc;
  int teste1 = 0;
  char tmp[20];
  while (teste1 <= 0) {
    printf("%s%s", MAG, gol);
    if (!fgets(tmp, sizeof tmp, stdin))
      ;
    if (sscanf(tmp, "%d", &opc) != 1)
      ;
    teste1 = sscanf(tmp, "%d", &opc);
    if (teste1 == EOF) {
      teste1 = 0;
    }
  }
  return (opc);
}
// Função de menu.
void menu(int fila, float tanque, float preco) {
  printf(
      MAG
      "\n                            =MENU=                           \n\n\n");
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  printf(MAG "Data:" GRN " %d/%d/%d " MAG "Hora:" GRN " %d:%d:%d\n" MAG,
         tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour - 3,
         tm.tm_min, tm.tm_sec);
  printf("\nPreço da gasolina:" GRN " %.2f\n\n" MAG, preco);
  printf("Carros na fila:" GRN " %d\n\n" MAG, fila);
  if (tanque > 100) {
    printf("Gasolina disponível no tanque:" GRN " %.2f\n\n" MAG, tanque);
  } else if (tanque > 50) {
    printf("Gasolina disponível no tanque:" YEL " %.2f\n\n" MAG, tanque);
  } else {
    printf("Gasolina disponível no tanque:" RED " %.2f\n\n" MAG, tanque);
  }
  printf("(" GRN "1" MAG ") Adicionar um carro a fila\n"
         "(" GRN "2" MAG ") Abastecimento\n"
         "(" GRN "3" MAG ") Exibir carros na fila de espera\n"
         "(" GRN "4" MAG ") Relatórios\n"
         "(" GRN "5" MAG ") Repor gasolina\n"
          "(" GRN "6" MAG ") Encerrar\n");
          printf("\nPor favor, escolha uma das opções.\n" WHT);
}
// Função de flush.
void flush_in() {
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
}
//