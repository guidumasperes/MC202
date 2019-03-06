#include<stdio.h>
#include<stdlib.h>
#include"Arvore.h"
#include"Superarvore.h"

no_dep* buscar_dep(no_dep *arvore_dep, int n_dep) {
	if(arvore_dep == NULL || n_dep == arvore_dep->n_dep)
		return arvore_dep;
	if(n_dep < arvore_dep->n_dep)
		return buscar_dep(arvore_dep->esq, n_dep);
	else
		return buscar_dep(arvore_dep->dir, n_dep);
}

void imprime_dep(no_dep *arvore_dep) {
    printf("%d: ", arvore_dep->n_dep);
    imprime_dep_rec(arvore_dep->r);
    printf("\n");
}

no_dep* inserir_rec_dep(no_dep *arvore_dep, int dep) {
	no_dep *novo;

	if(arvore_dep == NULL) {
		novo = malloc(sizeof(no_dep));
		novo->esq = novo->dir = NULL;
		novo->r = NULL;
		novo->n_dep = dep;
		return novo;
	}
	if(dep < arvore_dep->n_dep)
		arvore_dep->esq = inserir_rec_dep(arvore_dep->esq, dep);
	else
		arvore_dep->dir = inserir_rec_dep(arvore_dep->dir, dep);
	return arvore_dep;
}

void inserir_func_dep(no_dep **aux, no_dep **arvore_dep, int func, int sal, int dep) {
	if(*aux == NULL) {
		*arvore_dep = inserir_rec_dep(*arvore_dep, dep);
		*aux = buscar_dep(*arvore_dep, dep);
	}
    (*aux)->r = inserir_rec_func((*aux)->r, func, sal);
    imprime_dep(*aux);
}

void rem_func_dep(no_dep **aux, no_dep **arvore_dep, int sal, int dep) {
	if(*aux != NULL) {
        (*aux)->r = remover_func_rec((*aux)->r, sal);
        if((*aux)->r != NULL)
            imprime_dep(*aux);
        else
            *arvore_dep = remover_dep_rec(*arvore_dep, dep);
	}
}

no_dep* remover_dep_rec(no_dep *arvore_dep, int dep) {
    no_dep *pai = arvore_dep, *t, *aux;

	if(arvore_dep == NULL)
		return NULL;
	if(dep < arvore_dep->n_dep) {
		arvore_dep->esq = remover_dep_rec(arvore_dep->esq, dep);
		return arvore_dep;
	} else if(dep > arvore_dep->n_dep) {
		arvore_dep->dir = remover_dep_rec(arvore_dep->dir, dep);
		return arvore_dep;
	} else if(arvore_dep->esq == NULL) {
	    destroi_func(arvore_dep->r);
	    aux = arvore_dep->dir;
	    free(arvore_dep);
		return aux;
	} else if(arvore_dep->dir == NULL) {
	    destroi_func(arvore_dep->r);
	    aux = arvore_dep->esq;
	    free(arvore_dep);
		return aux;
	} else {
		t = arvore_dep->dir;
		while(t->esq != NULL) {
			pai = t;
			t = t->esq;
		}
		if(pai->esq == t)
			pai->esq = t->dir;
		else
			pai->dir = t->dir;
        destroi_func(arvore_dep->r);
		arvore_dep->n_dep = t->n_dep;
		arvore_dep->r = t->r;
		free(t);
		return arvore_dep;
	}
}

void rem_dep(no_dep **arvore_dep, int dep) {
    	*arvore_dep = remover_dep_rec(*arvore_dep, dep);
}

void maior_sal(no_dep *aux, no_dep *arvore_dep, int z) {
    no_func *aux1;

	if(aux != NULL) {
        aux1 = maior_sal_func(aux->r);
        printf("%d %d\n", aux1->id_func, aux1->sal);
	}
}

void menor_sal(no_dep *aux, no_dep *arvore_dep, int z) {
    no_func *aux1;

	if(aux != NULL) {
        aux1 = menor_sal_func(aux->r);
        printf("%d %d\n", aux1->id_func, aux1->sal);
	}
}

void soma_sal_dep(no_dep *aux, no_dep *arvore_dep) {
	if(aux != NULL) {
        printf("%d\n", soma_sal_dep_rec(aux->r));
	}
}

int soma_sal_total(no_dep *arvore_dep) {
	if(arvore_dep == NULL) {
		return 0;
	} else {
		return soma_sal_total(arvore_dep->esq) + soma_sal_total(arvore_dep->dir) + soma_sal_dep_rec(arvore_dep->r);
	}
}

void imprime_superarvore_rec(no_dep *arvore_dep) {
    if(arvore_dep == NULL)
        return;
    imprime_superarvore_rec(arvore_dep->esq);
    printf("%d: ", arvore_dep->n_dep);
    imprime_dep_rec(arvore_dep->r);
    printf("\n");
    imprime_superarvore_rec(arvore_dep->dir);
}

void libera_mem(no_dep **arvore_dep) {
    if(*arvore_dep == NULL)
        return;
    libera_mem(&(*arvore_dep)->esq);
    libera_mem(&(*arvore_dep)->dir);
    destroi_func((*arvore_dep)->r);
    free(*arvore_dep);
}