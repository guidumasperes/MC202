#include<stdio.h>
#include"Pilha.h"

int main (void) {
	int *vet_tipo_car, n_portos, lar, h, i;

	scanf("%d %d %d", &n_portos, &lar, &h);
	aloca_matriz(n_portos);
	le_matriz(n_portos);
	aloca_vet(&vet_tipo_car, n_portos);
	le_vet(&vet_tipo_car, n_portos);
	for(i = 0; i < n_portos - 1; i++)
		printf("%d\n", vet_tipo_car[i]);
	aloca_vet_pilha(lar, h);
	for(i = 0; i < lar; i++)
		printf("%d\n", vet_pilha[i].topo);
	for(i = 0; i < n_portos - 1; i++) {
		resolve_pilha(n_portos, i, vet_tipo_car[i], lar, h);
		printf("Porto %d:\n", i);
		imprime_sit(lar, h);
	}
	return 0;
}