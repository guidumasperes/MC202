#include<stdlib.h>
#include<stdio.h>
#include"Deque.h"

void aloca_vet(pedido **p, int ovos) {

	*p = malloc(ovos * sizeof(pedido));

}

void cria_vet_maq(maq **vet_maq, int maquinas) {
	int i;

	*vet_maq = malloc(maquinas * sizeof(maq));
	for(i = 0; i < maquinas; i++) {
		(*vet_maq)[i].ptr = NULL;
		(*vet_maq)[i].ini = NULL;
		(*vet_maq)[i].fim = NULL;
	}
}

void insere_pedido(int qnt_turno, int indice, int urg, int n_ped, maq **vet_maq) {
	fila *novo;

	novo = malloc(sizeof(fila));
	novo->turno_rest = qnt_turno;
	novo->id_ped = n_ped;
	if((*vet_maq)[indice].ptr == NULL) { /*Se isso ocorre a lista esta vazia*/
		(*vet_maq)[indice].ptr = novo;
		novo->ant = NULL;
		novo->prox = NULL;
		(*vet_maq)[indice].ini = novo;
		(*vet_maq)[indice].fim = novo;
	} else {
		if(urg == 0) {
			(*vet_maq)[indice].fim->prox = novo;
			novo->ant = (*vet_maq)[indice].fim;
			novo->prox = NULL;
			(*vet_maq)[indice].fim = novo;
		} else {
			novo->prox = (*vet_maq)[indice].ini;
			novo->ant = NULL;
			(*vet_maq)[indice].ptr = novo;
			(*vet_maq)[indice].ini = novo;
			novo->prox->ant = novo;
		}
	}
}

int troca_elem(int k, int i, maq **vet_maq) {
	int cnt = 0;
	fila *atual;

	/*printf("entrou troca_elem\n");*/
	atual = (*vet_maq)[k].ptr;
	/*printf("atual = %d", atual);*/
	/*Verificar se no indice k tem mais de 1 elemento*/
	while(atual != NULL && cnt != 2) {
		cnt++;
		atual = atual->prox;
	}
	/*printf("cnt = %d\n", cnt);*/
	if(cnt == 2) {
		(*vet_maq)[i].ini = (*vet_maq)[k].fim;
		(*vet_maq)[i].fim = (*vet_maq)[k].fim;
		(*vet_maq)[i].ptr = (*vet_maq)[k].fim;
		(*vet_maq)[k].fim = (*vet_maq)[k].fim->ant;
		(*vet_maq)[k].fim->prox = NULL;
		(*vet_maq)[i].ini->ant = NULL;
		return 1;
	}
	return 0; 
}

void decrementa_turnos(int maquinas, maq **vet_maq) {
	int i;

	for(i = 0; i < maquinas; i++) {
		if((*vet_maq)[i].ptr != NULL) { /*Se for != de NULL, pega os que estao na primeira posicao e decrementa 1*/
			(*vet_maq)[i].ptr->turno_rest = (*vet_maq)[i].ptr->turno_rest - 1;
		}
	}
}

void checa_prod(maq **vet_maq, int indice) {
	fila *aux;

	aux = (*vet_maq)[indice].ini;
	if(verifica_n_elem((*vet_maq)[indice].ptr)) {
		(*vet_maq)[indice].ptr = (*vet_maq)[indice].ini->prox;
		(*vet_maq)[indice].ptr->ant = NULL;
		(*vet_maq)[indice].ini = (*vet_maq)[indice].ptr;
	} else {
		(*vet_maq)[indice].ptr = NULL;
		(*vet_maq)[indice].ini = NULL;
		(*vet_maq)[indice].fim = NULL;
	}
	printf("(%d, %d)", indice, aux->id_ped);
	free(aux);
}

int verifica_n_elem(fila *ptr) {
	int cnt = 0;
	fila *atual;

	atual = ptr;
	while(atual != NULL && cnt != 2) {
		cnt++;
		atual = atual->prox;
	}
	if(cnt == 2)
		return 1;
	else
		return 0;
}

/*void auxilio(int maquinas, maq *vet_maq) {
	int i;
	fila *atual;

	for(i = 0; i < maquinas; i++) {
		printf("maquina %d\n", i);
		atual = vet_maq[i].ptr;
		printf("Imprimindo a lista do comeco\n");
		while(atual != NULL) {
			printf("atual->turno_rest = %d\n", atual->turno_rest);
			printf("(Ovo)atual->id_ped = %d\n", atual->id_ped);
			atual = atual->prox;
		}
		printf("Terminou de imprimir a lista\n");
	}
}*/