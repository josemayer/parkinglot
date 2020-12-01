#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

int main(){
    int i, j;
    int capacidade;
    item * entrada;
    pilha * garagem;
    pilha * manobra;
    item * saida;
    char * op = malloc(2 * sizeof(char));

    printf("Digite a capacidade máxima de seu estacionamento: ");
    scanf("%d", &capacidade);

    entrada = malloc(capacidade * sizeof(item));
    saida = malloc(capacidade * sizeof(item));
    garagem = criaPilha(capacidade);
    manobra = criaPilha(capacidade);

    printf("==== Operações ====\n");

    /* Se for lida uma string de tamanho maior que 2, então dá Seg. Fault */
    scanf("%s", op);

    while(op[0] != '$'){
        if(op[0] == '+'){
            printf("Chegou %c.\n", op[1]);
        } else if (op[0] == '-') {
            printf("Manda %c para a saída.\n", op[1]);
        } else if (op[0] == '#') {
            printf("Estaciona o primeiro do vetor entrada.\n");
        }
        scanf("%s", op);
    }

    return 0;

    free(op);
    free(entrada);
    free(saida);
    destroiPilha(garagem);
    destroiPilha(manobra);
}