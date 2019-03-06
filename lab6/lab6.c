#include<stdio.h>
#include"Heap.h"

int main() {
	int m, c, i, j, cnt, control, cachorro = 0;

	N = 0;
	scanf("%d %d", &m, &c);
	cnt = c;
	ini_m(m);
	ini_PQ(c);
	for(i = 0; i < m; i++) {/*Ler especialidades e setar disponibilidade para 0*/
		scanf("%d", &vet_m[i].e);
		vet_m[i].disp = 1;
	}
	do {
		scanf("%d", &control);
		if(control == 1) {
			adc_cao(cachorro); /*Adiciona no vetor e arruma o heap*/
			/*printf("cachorro: %d\n", cachorro);*/
			cachorro++;
		} else if(control == 2) {
			disp_m();
		} else {
			alt_pri(c);
		}
		for(i = 0; i < m; i++) {
			/*printf("i = %d\n", i);*/
			arruma_indice_raiz();
			if(vet_m[i].disp == 1) {
				for(j = i; j < m; j++) {
					/*printf("**vet_m[%d].e = %d ,vet_c[0].r = %d\n", j, vet_m[j].e, vet_c[0].r);*/
					if(vet_m[j].disp == 1 && vet_m[j].e == vet_c[0].r && vet_c[0].atend != 1) {
						printf("%d %d\n", j, vet_c[0].ind);
						cnt--;
						vet_c[0].atend = 1;
						vet_m[j].disp = 0;
						i--;
						deleta();
						break;
					}
				}
				if(j == m && vet_c[0].atend != 1) {
					printf("%d %d\n", i, vet_c[0].ind);
					cnt--;
					vet_c[0].atend = 1;
					vet_m[i].disp = 0;
					deleta();
				}
			}
			/*imprime(m);*/
		}
	}while(cnt); /*Enquanto houver cachorros para serem atendidos*/
	return 0;
}