#include<stdio.h>
#include"Arvore.h"
#include"Superarvore.h"

int main() {
	int s, z, control = 9, func = 0;
	no_dep *aux, *arvore_dep = NULL;

	while(control != 8) {
		scanf("%d", &control);
		if(control == 1) {
			scanf("%d %d", &s, &z);
			aux = buscar_dep(arvore_dep, z);
			inserir_func_dep(&aux ,&arvore_dep, func, s, z);
			func++;
		} else if(control == 2) {
			scanf("%d %d", &s, &z);
			aux = buscar_dep(arvore_dep, z);
			rem_func_dep(&aux, &arvore_dep, s, z);
		} else if(control == 3) {
		    scanf("%d", &z);
			rem_dep(&arvore_dep, z);
			if(arvore_dep != NULL)
                imprime_superarvore_rec(arvore_dep);
		} else if(control == 4) {
		    scanf("%d", &z);
		    aux = buscar_dep(arvore_dep, z);
			maior_sal(aux, arvore_dep, z);
		} else if(control == 5) {
		    scanf("%d", &z);
		    aux = buscar_dep(arvore_dep, z); 
			menor_sal(aux, arvore_dep, z);
		} else if(control == 6) {
			scanf("%d", &z);
			aux = buscar_dep(arvore_dep, z);
			soma_sal_dep(aux, arvore_dep);
		} else if(control == 7) {
			printf("%d\n", soma_sal_total(arvore_dep));
		} else {
			libera_mem(&arvore_dep);
			printf("Fim\n");
		}
	}
	return 0;
}
