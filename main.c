#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  while (true) {
    // escolhe uma palavra aleatoria
    char *respostas[] = {"tijolo",     "urso",   "arvore",   "animal",
                         "baleia",     "batman", "cachorro", "celular",
                         "computador", "camisa", "porta",    "esporte",
                         "luva",       "flor",   "academia", "espada",
                         "cama",       "batata", "cenoura",  "bebedouro"};

    srand(time(0));
    int randResposta = rand() % (sizeof(respostas) / sizeof(char *));
    char *resposta = respostas[randResposta];

    // o texto que aparece na tela
    char texto[40];
    int i;
    for (i = 0; resposta[i] != '\0'; i++) {
      texto[i] = '_';
    }
    texto[i] = '\0';

    // variaveis
    int tentativas = 6;
    bool acerto;

    // jogo da forca
    while (true) {
      // a interface do jogo
      system("clear");
      printf("====================\n");
      printf("   JOGO DA FORCA   \n");
      printf("====================\n");
      printf("Tentativas: %i\n", tentativas);
      printf("%s\n\n", texto);

      char letra;
      printf("escolha uma letra: ");
      scanf("%c", &letra);
      getchar();

      acerto = false;

      // verifica se a letra escolhida faz parte da palavra
      for (int i = 0; resposta[i] != '\0'; i++) {
        if (letra == resposta[i]) {
          texto[i] = resposta[i];
          acerto = true;
        }
      }

      // se a letra escolhida não faz parte da palavra, você perde uma tentativa
      if (acerto == false) {
        tentativas--;
      }

      // se todas tentativas acabarem, você perde
      if (tentativas <= 0) {
        printf("você errou, a resposta era %s\n", resposta);
        break;
      }

      // se você descobrir todas as letras, você ganha
      else if (!strcmp(texto, resposta)) {
        printf("parabéns, você acertou! a reposta era %s \n", resposta);
        break;
      }
    }
    // continuar?
    char opt;
    printf("quer jogar mais uma vez? [s/n]: ");
    scanf("%c", &opt);
    getchar();

    if (tolower(opt) == 's') {
      continue;
    } else {
      break;
    }
  }

  return 0;
}
