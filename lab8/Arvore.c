#include<stdio.h>
#include<stdlib.h>
#include"Arvore.h"
#include"Superarvore.h"

no_func* inserir_rec_func(no_func *arvore_func, int func, int sal) {
	no_func *novo;

	if(arvore_func == NULL) {
		novo = malloc(sizeof(no_func));
		novo->esq = novo->dir = NULL;
		novo->id_func = func;
		novo->sal = sal;
		return novo;
	}
	if(sal < arvore_func->sal)
		arvore_func->esq = inserir_rec_func(arvore_func->esq, func, sal);
	else
		arvore_func->dir = inserir_rec_func(arvore_func->dir, func, sal);
	return arvore_func;
}

no_func* remover_func_rec(no_func *arvore_func, int sal) {
    no_func *pai = arvore_func, *t, *aux;

	if(arvore_func == NULL)
		return NULL;
	if(sal < arvore_func->sal) {
		arvore_func->esq = remover_func_rec(arvore_func->esq, sal);
		return arvore_func;
	} else if(sal > arvore_func->sal) {
		arvore_func->dir = remover_func_rec(arvore_func->dir, sal);
		return arvore_func;
	} else if(arvore_func->esq == NULL) {
	    aux = arvore_func->dir;
	    free(arvore_func);
		return aux;
	} else if(arvore_func->dir == NULL) {
	    aux = arvore_func->esq;
	    free(arvore_func);
		return aux;
	} else {
		t = arvore_func->dir;
		while (t->esq != NULL) {
			pai = t;
			t = t->esq;
		}
		if(pai->esq == t)
			pai->esq = t->dir;
		else
			pai->dir = t->dir;
        arvore_func->id_func = t->id_func;
		arvore_func->sal = t->sal;
		free(t);
		return arvore_func;
	}
}

void destroi_func(no_func *arvore_func) {
    if(arvore_func == NULL)
        return;
    destroi_func(arvore_func->esq);
    destroi_func(arvore_func->dir);
    free(arvore_func);
}

no_func* maior_sal_func(no_func *arvore_func) {
    if(arvore_func == NULL || arvore_func->dir == NULL)
        return arvore_func;
    return maior_sal_func(arvore_func->dir);
}

no_func* menor_sal_func(no_func *arvore_func) {
    if(arvore_func == NULL || arvore_func->esq == NULL)
        return arvore_func;
    return menor_sal_func(arvore_func->esq);
}

int soma_sal_dep_rec(no_func *arvore_func) {
	if(arvore_func == NULL) {
		return 0;
	} else {
		return soma_sal_dep_rec(arvore_func->esq) + soma_sal_dep_rec(arvore_func->dir) + arvore_func->sal;
	}
}

void imprime_dep_rec(no_func *arvore_func) {
    if(arvore_func == NULL)
        return;
    imprime_dep_rec(arvore_func->esq);
    printf("%d %d, ", arvore_func->id_func, arvore_func->sal);
    imprime_dep_rec(arvore_func->dir);
}