#ifndef HEAP_H
#define	HEAP_H

typedef struct {
	int disp;
	int e;
}med;

typedef struct {
	int r;
	int p;
	int ind;
	int atend;
}cao;

med *vet_m; /*campo disponivel e especialidade*/
cao *vet_c; /*campo raca e prioridade*/
int N;

void ini_m(int m);

void arruma_indice_raiz();

void ini_PQ(int c);

void troca(int n, int m);

void arruma_cima(int k);

void arruma_baixo(int k);

void adc_cao(int cachorro);

void alt_pri(int c);

void disp_m();

void deleta();

#endif