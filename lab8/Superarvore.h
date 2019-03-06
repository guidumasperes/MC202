#ifndef SUPERARVORE_H
#define SUPERARVORE_H

typedef struct no_dep {
	int n_dep;
	struct no_dep *esq, *dir;
	struct no_func *r;
} no_dep;

no_dep* buscar_dep(no_dep *arvore_dep, int n_dep);

void imprime_dep(no_dep *arvore_dep);

no_dep* inserir_rec_dep(no_dep *arvore_dep, int dep);

void inserir_func_dep(no_dep **aux, no_dep **arvore_dep, int func, int sal, int dep);

void rem_func_dep(no_dep **aux, no_dep **arvore_dep, int sal, int dep);

no_dep* remover_dep_rec(no_dep *arvore_dep, int dep);

void rem_dep(no_dep **arvore_dep, int dep);

void maior_sal(no_dep *aux, no_dep *arvore_dep, int z);

void menor_sal(no_dep *aux, no_dep *arvore_dep, int z);

void soma_sal_dep(no_dep *aux, no_dep *arvore_dep);

int soma_sal_total(no_dep *arvore_dep);

void imprime_superarvore_rec(no_dep *arvore_dep);

void libera_mem(no_dep **arvore_dep);

#endif