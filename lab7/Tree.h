#ifndef TREE_H
#define TREE_H

typedef struct No{
	int dado;
	struct No *esq, *dir;
}no;

no* criar_arvore(int x, no *esq, no *dir);

void inordem(no *arvore);

void pos_ordem(no *arvore);

no* insere_radiacao_rec(no *arvore, int rad, int lim);

void insere_radiacao(no **arvore, int rad, int lim);

int total_radiacao(no *arvore);

int altura(no *arvore);

void troca(no **esq, no **dir);

void inverte(no **arvore);

no* adiciona(no *a, no *b);

int confere_geracao(no **arvore, int g, int l);

#endif