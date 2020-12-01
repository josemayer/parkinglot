#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

pilha * criaPilha(int tam){
    pilha * p = malloc(sizeof(pilha));
    p->tam = tam;
    p->topo = 0;
    p->v = malloc(tam * sizeof(item));
    if (p->v == NULL)
        return NULL;
    return p;
}

void destroiPilha(pilha * p){
    free(p->v);
    free(p);
}

void empilha(pilha * p, item x){
    if (p->topo == p->tam)
        p = aumentaPilha(p);
    p->v[p->topo] = x;
    p->topo = p->topo + 1;
}

item desempilha(pilha * p){
    if (!pilhaVazia(p)){
        p->topo = p->topo - 1;
        return (p->v[p->topo]);
    }
}

int pilhaVazia(pilha * p){
    return (p->topo == 0);
}

item topoDaPilha(pilha * p){
    if (!pilhaVazia(p))
        return (p->v[p->topo - 1]);
}

/* Dobra o tamanho da pilha */
pilha * aumentaPilha (pilha * p){
  item * w = malloc(2 * p->tam * sizeof(item)); 
  int i; 
  for (i = 0; i < p->tam; i++)
    w[i] = p->v[i]; 
  p->tam = 2 * p->tam; 
  free(p->v);
  p->v = w;
  return (p); 
} 