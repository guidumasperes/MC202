#include<stdio.h>
#include"lista.h"

int main (void) {
	no *lista, *m, *ini, *fim;
	int ind = 0, n;
	char mus[31];

	ini_lista(&lista, &m, &ini ,&fim);
	while(ind != 6) {
		scanf("%d", &ind);
		if(ind == 1) {
			scanf("%s", mus);
			ins_mus(&m, &ini, &fim, mus);
		} else if(ind == 2) {
			scanf("%d", &n);
			rem_mus(&m, &ini, &fim, n);	
		} else if(ind == 3) {
			scanf("%s", mus);
			esc_prox(&m, &ini, &fim, mus);
		} else if(ind == 4) {
			scanf("%d", &n);
			avancar(&m, n);
			printf("%s\n", m->str);
		} else if(ind == 5) {
			scanf("%d", &n);
			retroceder(&m, n);
			printf("%s\n", m->str);
		} else {

		}
		lista = m;
	}
	destroi_lista(&lista, &ini, &fim);
	return 0;
}
