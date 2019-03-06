#ifndef HASH_LISTA
#define HASH_LISTA

typedef struct no_lista{
    char dim[50];
    int sem;
    struct no_lista *prox;
}no_lista;

int hash_lista(char dim[50]);

void inserir_lista(no_lista *vet_lista[1785], char dim[50], int sem);

void busca_dimensao(no_lista *vet_lista[1785], char dim[50]);

int rem_dim_lista(no_lista *vet_lista[1785], char dim[50]);

#endif