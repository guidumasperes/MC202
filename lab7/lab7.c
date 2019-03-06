#include<stdio.h>
#include"Tree.h"

int main() {
	no *arvore;
	int control = 0, l, g, r;

	scanf("%d %d %d", &l, &g, &r);
	arvore = criar_arvore(r, NULL, NULL);
	while(control != 9) {
		scanf("%d", &control);
		if(control == 1) {
			scanf("%d", &control);
			if(control == 0) {
				printf("in-ordem: ");
				inordem(arvore);
				printf("\n");
			} else {
				printf("pos-ordem: ");
				pos_ordem(arvore);
				printf("\n");
			}	
		}else if(control == 2) {
			scanf("%d", &r);
			insere_radiacao(&arvore, r, l); /*Dentro dela chama outra funao*/
		} else if(control == 3) {
			printf("total de radiacao: %d\n", total_radiacao(arvore));
		} else {

		}
		show(arvore, altura(arvore));
		l = confere_geracao(&arvore, g, l);
	}
	return 0;
}