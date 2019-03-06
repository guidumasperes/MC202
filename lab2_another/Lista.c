#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"

void ini_cliente_produto(int **c, no ***p, int n, int m) {
	int i;

	*p = malloc(n * sizeof(no*));
	if(*p == NULL)
		printf("Falha na alocacao de memoria\n");
	*c = malloc(m * sizeof(int));
	if(c == NULL)
		printf("Falha na alocacao de memoria\n");
}

void adc_lance(no **p, int cli, int prod, int val) {
	no *novo, *atual, *aux;

	novo = malloc(sizeof(no));
	if(novo == NULL)
		printf("Falha na alocacao de memoria\n");
	aux = *p;
	if(aux == NULL) { /*Primeiro item a ser adicionado*/
		novo->n = *p;
		novo->lance = val;
		novo->id_cli = cli;
		*p = novo;
		return;
	} else {
		for(atual = *p; atual->n != NULL; aux = atual, atual = atual->n) { /*Inserir ordenado*/
			if(atual->lance < val) { /*Adc antes*/
				novo->n = atual;
				novo->lance = val;
				novo->id_cli = cli;
				aux->n = novo;
				return;
			}
		}
	}
	if(atual == *p && val > atual->lance) { /*Insere antes*/
		if(val > atual->lance){
			*p = novo;
			novo->n = atual;
			novo->lance = val;
			novo->id_cli = cli;
			return;
		} else {
			atual->n = novo;
			novo->n = NULL;
			novo->lance = val;
			novo->id_cli = cli;
			return;
		}
	}
	if(atual->n == NULL) {
		if(atual->lance <= val) {
			aux->n = novo;
			novo->n = atual;
			novo->lance = val;
			novo->id_cli = cli;
			return;
		} else {
			atual->n = novo;
			novo->n = NULL;
			novo->lance = val;
			novo->id_cli = cli;
			return;
		}	
	}
}

int canc_lance(no **p, int cli, int prod) {
	no *atual, *ant = NULL;
        
	for(atual = *p; atual != NULL; ant = atual, atual = atual->n) { /*Achamos qual eh o maior valor e o no correspondente a esse valor*/
		if(atual->id_cli == cli) { /*Como a lista esta ordenada ja remove o primeiro*/
			if(atual == *p) {
				*p = atual->n;
				free(atual);
				return 1;
			} else {
            	ant->n = atual->n;
            	free(atual);
            	return 1;
        	}
		}
	}
	return 0;
}

int fin_prod(no **p, int *c) {
	int vencedor = -1, maior = 0;
	no *atual;

	for(atual = *p; atual != NULL; atual = atual->n) {
		if(atual->lance == maior) {
			if(c[atual->id_cli] >= c[vencedor]) {
				vencedor = atual->id_cli;
				maior = atual->lance;
			}
		} else if(atual->lance > maior) {
			if(c[atual->id_cli] >= atual->lance) {
				vencedor = atual->id_cli;
				maior = atual->lance;
			}
		} else {

		}
	}
	return vencedor;
}

void imprime_lances(no **p) {
	no *atual;

	for(atual = *p; atual != NULL; atual = atual->n) {
		printf("Cliente %d: %d\n", atual->id_cli, atual->lance);
	}
}
