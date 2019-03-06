#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

no* criar_arvore(int x, no *esq, no *dir) {
	no *r = malloc(sizeof(no));
	r->dado = x;
	r->esq = esq;
	r->dir = dir;
	return r;
}

void inordem(no *arvore) {
	if(arvore) {
		inordem(arvore->esq);
		printf("%d ", arvore->dado);
		inordem(arvore->dir);
	}
}

void pos_ordem(no *arvore) {
	if(arvore) {
		pos_ordem(arvore->esq);
		pos_ordem(arvore->dir);
		printf("%d ", arvore->dado);
	}
}
/*1 = esquerdo e 2 = direito*/
no* insere_radiacao_rec(no *arvore, int rad, int lim) {
	no *novo;
	if(rad == 0) {
		return arvore;
	} else {
		if(arvore == NULL) {
			novo = malloc(sizeof(no));
			novo->esq = NULL;
			novo->dir = NULL;
			if(rad <= lim) {
				novo->dado = rad;
			} else {
				novo->dado = 0;
				novo->esq = insere_radiacao_rec(novo->esq, rad/2, lim);
				if(rad != 1 && rad % 2 == 0)
					novo->dir = insere_radiacao_rec(novo->dir, rad/2, lim);
				else
					novo->dir = insere_radiacao_rec(novo->dir, (rad/2)+1, lim);
			}
			return novo;
		} else {
			if((arvore->dado + rad) <= lim) {
				arvore->dado = arvore->dado + rad;
				return arvore; /*verificar se nao esta apontando pra si mesmo*/
			} else {
				arvore->esq = insere_radiacao_rec(arvore->esq, rad/2, lim);
				if(rad != 1 && rad % 2 == 0)
					arvore->dir = insere_radiacao_rec(arvore->dir, rad/2, lim);
				else
					arvore->dir = insere_radiacao_rec(arvore->dir, (rad/2)+1, lim);
			}
		}
	}
	return arvore;

}

void insere_radiacao(no **arvore, int rad, int lim) {
	if(((*arvore)->dado + rad) <= lim) {
		(*arvore)->dado = (*arvore)->dado + rad;
	} else {
		*arvore = insere_radiacao_rec(*arvore, rad, lim); 
	}
}

int total_radiacao(no *arvore) {
	if(arvore == NULL) {
		return 0;
	} else {
		return total_radiacao(arvore->esq) + total_radiacao(arvore->dir) + arvore->dado;
	}
}

int altura(no *arvore) {
	int h_esq = 0, h_dir = 0;
	if(arvore == NULL)
		return 0;
	h_esq = altura(arvore->esq);
	h_dir = altura(arvore->dir);
	return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

void troca(no **esq, no **dir) {
	no **aux;

	aux = esq;
	*esq = *dir;
	*dir = *aux;
}

void inverte(no **arvore) {
	if(*arvore != NULL) {
		inverte(&(*arvore)->esq);
		inverte(&(*arvore)->dir);
		troca(&(*arvore)->esq, &(*arvore)->dir);
	}
}

no* adiciona(no *a, no *b) {
	no *c, *ad, *ae, *bd, *be;
	if(a == NULL && b == NULL) {
		return NULL;
	} else {
		c = criar_arvore(0, NULL, NULL);
		if(a != NULL) {
			c->dado += a->dado;
			ad = a->dir;
			ae = a->esq;
		} else {
			ad = NULL;
			ae = NULL;
		}
		if(b != NULL) {
			c->dado += b->dado;
			bd = b->dir;
			be = b->esq;
		} else {
			bd = NULL;
			be = NULL;
		}
		c->dir = adiciona(ad, bd);
		c->esq = adiciona(ae, be);
		return c;
	}
}

void printnode1(char c, int h) {
	int i;
	for(i = 0; i < h; i++)
		printf(" ");
	printf("%c\n", c);
}

void printnode2(int c, int h) {
	int i;
	for(i = 0; i < h; i++)
		printf(" ");
	printf("%d\n", c);
}

void show(no *x, int h) {
	if(x == NULL) {
		printnode1('*', h);
		return;
	}
	show(x->dir, h+1);
	printnode2(x->dado, h);
	show(x->esq, h+1);
}

int confere_geracao(no **arvore, int g, int l) {
	int h = altura(*arvore);

	/*printf("h = %d\n", h);*/
	if(g == h - 1) {
		show(*arvore, h);
		printf("\n\n\n");
		inverte(&(*arvore)->dir); /*ou &arvore?*/
		show(*arvore, h);
		printf("\n\n\n");
		*arvore = adiciona((*arvore)->esq, (*arvore)->dir);
		show(*arvore, h);
		printf("\n\n\n");
		printf("houve uma explosao!\n");
		return 2*l;
	}
	return l;
}