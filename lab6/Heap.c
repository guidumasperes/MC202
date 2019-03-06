#include<stdio.h>
#include<stdlib.h>
#include"Heap.h"

void ini_m(int m) {
	vet_m = malloc(m * sizeof(med));
}

void ini_PQ(int c) {
	vet_c = malloc(c * sizeof(cao));
}

void troca(int n, int m) {
	cao aux;

	aux = vet_c[n];
	vet_c[n] = vet_c[m];
	vet_c[m] = aux;
}

void arruma_cima(int k) {

	if(k > 0 && vet_c[((k-1)/2)].p < vet_c[k].p) {
		troca(((k-1)/2), k); /*mexer na vet_ind dentro da troca*/
		arruma_cima(((k-1)/2));
	}
}

void arruma_baixo(int k) {
	int j = (2*k) + 1;

	if(j < N) {
		if(j < N - 1 && vet_c[j].p < vet_c[j+1].p)
			j++;
		if(vet_c[k].p < vet_c[j].p) {
			troca(k, j);
			arruma_baixo(j);
		}

	}
}

void adc_cao(int cachorro) {
	scanf("%d %d", &vet_c[N].r, &vet_c[N].p); /*Adiciona o cachorro no vetor de cachorro*/
	/*printf("N = %d\n", N);*/
	vet_c[N].ind = cachorro;
	vet_c[N].atend = 0;
	N++;
	arruma_cima(N-1);
}

void alt_pri(int c) {
	int i, x, y, ant;

	scanf("%d %d", &y, &x);
	for(i = 0; i < c; i++) {
		if(y == vet_c[i].ind) {
			ant = vet_c[i].p;
			vet_c[i].p = vet_c[i].p + x;
			if(ant < vet_c[i].p) { /*a prioridade aumentou*/
				arruma_cima(i);
			} else {
				arruma_baixo(i);
			}
			break;
		}
	}
}

void arruma_indice_raiz() {
	int i;

	for(i = 0; i < N; i++) {
		if((vet_c[0].ind > vet_c[i].ind) && (vet_c[0].p == vet_c[i].p))
			troca(0, i);
	}
}

void disp_m() {
	int i, n, aux;

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &aux);
		vet_m[aux].disp = 1;
	}
}

void deleta() {
	troca(0, N-1);
	N--;
	arruma_baixo(0);
}

void imprime(int m) {
	int i;

	printf("N = %d\n", N);
	for(i = 0; i < N; i++) {
		printf("vet_c[%d].r = %d\n", i, vet_c[i].r);
		printf("vet_c[%d].p = %d\n", i, vet_c[i].p);
		printf("vet_c[%d].ind = %d\n", i, vet_c[i].ind);
		printf("vet_c[%d].atend = %d\n", i, vet_c[i].atend);
	}
	for(i = 0; i < m; i++) {/*Ler especialidades e setar disponibilidade para 0*/
		printf("vet_m[%d].disp = %d, vet_m[%d].e = %d\n",i, vet_m[i].disp,i, vet_m[i].e);
	}
}