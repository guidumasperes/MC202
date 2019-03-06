#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"HashLista.h"

int hash_lista(char dim[50]) {
    int i, n = 0;

    for(i = 0; i < strlen(dim); i++)
        n = (256 * n + dim[i]) % 1783;
    return n;
}

void inserir_lista(no_lista *vet_lista[1785], char dim[50], int sem) {
    int n = hash_lista(dim);
    no_lista *novo;

    novo = malloc(sizeof(no_lista));
    novo->sem = sem;
    strcpy(novo->dim, dim);
    novo->prox = vet_lista[n];
    vet_lista[n] = novo;
}

void busca_dimensao(no_lista *vet_lista[1785], char dim[50]) {
    int n = hash_lista(dim);
    no_lista *aux;

    for(aux = vet_lista[n]; aux != NULL; aux = aux->prox) {
        if(!strcmp(aux->dim, dim)) {
            printf("%d\n", aux->sem);
            break;
        }
    }
    if(aux == NULL)
        printf("chave nao encontrada!\n");
 }

int rem_dim_lista(no_lista *vet_lista[1785], char dim[50]) {
    int n = hash_lista(dim), var;
    no_lista *aux, *ant;

    for(aux = vet_lista[n]; aux != NULL; ant = aux, aux = aux->prox) {
        if(!strcmp(aux->dim, dim)) {
            var = aux->sem;
            if(aux == vet_lista[n])
                vet_lista[n] = vet_lista[n]->prox;
            else
                ant->prox = aux->prox;
            free(aux);
            break;
        }
    }
    return var;
}