#include "agenda.h"
#include "listase.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
  agenda *ag = criar_agenda();
  int i;

  do {
    scanf("%d", &i);
    switch (i) {

    case 1:
      agendar_evento(ag, ler_dado());
      break;

    case 2:
      printf("%d\n", quantificar_evento(ag));
      break;

    case 3:
      imprimir_dado(proximo_evento(ag));
      break;

    case 4:
      alterar_evento(ag, ler_data(), ler_dado());
      break;

    case 5:
      imprimir_dado(cancelar_evento(ag, ler_data()));
      break;

    case 6:
      concluir_evento(ag);
    }
  } while (i != -1);
}