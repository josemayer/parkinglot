#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

int main(){
    int i, j;
    int capacidade;
    int indEntrada, indSaida;
    item * entrada;
    pilha * garagem;
    pilha * manobra;
    item * saida;
    char * op = malloc(2 * sizeof(char));
    item aux, elemento;

    printf("Digite a capacidade máxima de seu estacionamento: ");
    scanf("%d", &capacidade);

    entrada = malloc(capacidade * sizeof(item));
    saida = malloc(capacidade * sizeof(item));
    garagem = criaPilha(capacidade);
    manobra = criaPilha(capacidade);
    indEntrada = indSaida = 0;

    printf("==== Operações ==== ||| ==== Saídas ====\n");

    /* Se for lida uma string de tamanho maior que 2, então dá Seg. Fault */
    scanf("%s", op);

    while(op[0] != '$'){
        if(op[0] == '+'){
            if(indEntrada < capacidade){
                entrada[indEntrada] = op[1];
                indEntrada++;
            } else {
                printf("A capacidade de entrada se excedeu.\n");
            }
        } else if (op[0] == '-') {
            if(posicaoNaPilha(garagem, op[1]) != -1){
                aux = topoDaPilha(garagem);
                while(aux != op[1]){
                    elemento = desempilha(garagem);
                    empilha(manobra, elemento);
                    aux = topoDaPilha(garagem);
                    printf("\t\t\t%c:g>m\n", elemento);
                }

                /* Saiu do laço: o topo da pilha é o elemento */
                /* Pega ele e leva para a saída */
                elemento = desempilha(garagem);
                saida[indSaida] = elemento;
                indSaida++;
                printf("\t\t\t%c:g>s\n", elemento);

                /* Retorna todos os elementos da manobra para a pilha novamente */
                while(!pilhaVazia(manobra)){
                    elemento = desempilha(manobra);
                    empilha(garagem, elemento);
                    printf("\t\t\t%c:m>g\n", elemento);
                }
            } else {
                printf("O elemento %c não está estacionado.\n", op[1]);
            }
        } else if (op[0] == '#') {
            if(indEntrada > 0){
                empilha(garagem, entrada[0]);

                /* Imprime a ação */
                printf("\t\t\t%c:e>g\n", entrada[0]);

                /* Move todos os elementos de entrada para a esquerda e decrementa o indEntrada */
                for(i = 0; i < capacidade - 1; i++){
                    entrada[i] = entrada[i + 1];
                }
                indEntrada--;
            } else {
                printf("Não há nenhum elemento em entrada.\n");
            }
        }
        scanf("%s", op);
    }

    /* Saiu do loop -> indica que o op_code usado foi o cifrão e, então, escreve as saídas no arquivo garagem.txt */
    FILE * arq = fopen("garagem.txt", "w+");
    item * garFinal = garagemFinal(garagem);

    fprintf(arq, "Entrada (por ordem de chegada): %s\n", entrada);
    fprintf(arq, "Garagem (fundo -> topo): %s\n", garFinal);
    fprintf(arq, "Saída (por ordem de saída): %s\n", saida);

    fclose(arq);

    free(op);
    free(entrada);
    free(saida);
    destroiPilha(garagem);
    destroiPilha(manobra);
    free(garFinal);

    return 0;
}