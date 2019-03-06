#ifndef ARVORE_H
#define ARVORE_H

typedef struct no_func {
	int id_func, sal;
	struct no_func *esq, *dir;
}no_func;

no_func* inserir_rec_func(no_func *arvore_func, int func, int sal);

no_func* remover_func_rec(no_func *arvore_func, int sal);

void destroi_func(no_func *arvore_func);

no_func* maior_sal_func(no_func *arvore_func);

no_func* menor_sal_func(no_func *arvore_func);

int soma_sal_dep_rec(no_func *arvore_func);

void imprime_dep_rec(no_func *arvore_func);

#endif