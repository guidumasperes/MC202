#ifndef HASH_ABERTO
#define HASH_ABERTO

typedef struct no_vet{
    int sem, vazio, excl;
    char dim[50];
}no_vet;

int hash_aberto(int sem);

void inserir_end(no_vet vet_end[1785], char dim[50], int sem);

void rem_dim_end(no_vet vet_end[1785], int sem);

char* dim_col_sem(no_vet vet_end[1785], int sem, int k);

#endif