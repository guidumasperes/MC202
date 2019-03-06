#ifndef PILHA_H
#define PILHA_H

typedef struct{
	int *vet;
	int topo;
}pilha;

pilha *vet_pilha;
int **matriz;

void carrega(int i, int j, int ind);

int descarrega(int i, int j);

void aloca_vet_pilha(int lar, int h);

void resolve_pilha(int portos, int porto_atual, int tipo_car, int lar, int h);

void imprime_sit(int lar, int h);

void aloca_matriz(int lar_h);

void le_matriz(int n_portos);

void aloca_vet(int **vet, int n_portos);

void le_vet(int **vet, int n_portos);

void imprime_mat(int n);

#endif