#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"lista.h"

void ini_lista(no **lista, no **m, no **ini, no **fim) {

	*lista = malloc(sizeof(no));
	strcpy((*lista)->str, "ChitaoEXororo-Evidencias");
	(*lista)->prox = *lista;
	(*lista)->ant = *lista;
	*m = *lista;
	*ini = *lista;
	*fim = *ini;
}

void ins_mus(no **m, no **ini, no **fim, char mus[31]) {
	no *novo;

	novo = malloc(sizeof(no));
	strcpy(novo->str, mus);
	if(*m == *ini && *m == *fim && *ini == *fim) { /*Um elemento na lista apenas*/
		(*m)->prox = novo;
		(*m)->ant = novo;
		*fim = novo;
		novo->ant = *m;
		novo->prox = *m;
	} else if(*m == *ini && *m != *fim) {
		novo->ant = *m;
		novo->prox = (*m)->prox;
		(*m)->prox->ant = novo;
		(*m)->prox = novo;
		(*m)->ant = *fim;
	} else if(*m == *fim && *m != *ini) {
		novo->ant = *m;
		novo->prox = *ini;
		(*m)->prox = novo;
		(*ini)->ant = novo;
		*fim = novo;
	} else {
		novo->ant = *m;
		novo->prox = (*m)->prox;
		(*m)->prox->ant = novo;
		(*m)->prox = novo;
	}
}

void rem_mus(no **m, no **ini, no **fim, int n) {
	no *aux;

	while(n != 0) {
		aux = (*m)->prox;
		if(*m == *ini && aux == *fim) {
			(*m)->prox = *ini;
			(*m)->ant = *ini;
			*fim = *ini;
		} else if(*m == *fim && aux == *ini) {
			*ini = aux->prox;
			(*m)->prox = aux->prox;
			aux->prox->ant = *m;
		} else {
			(*m)->prox = aux->prox;
			aux->prox->ant = *m;
			if(aux == *fim)
				*fim = *m;
			if(aux == *ini)
				*ini = *m;
		}
		aux->ant = NULL;
		aux->prox = NULL;
		free(aux);
		n--;
	}
}

void esc_prox(no **m, no **ini, no **fim, char proxima[31]) {
	no *atual;

	atual = *ini;
	while(strcmp(atual->str, proxima) != 0)
		atual = atual->prox;

	if(atual == *ini) { /*Isso se a musica estiver no comeco*/
		(*m)->prox->ant = atual;
		atual->prox->ant = *fim;
		*ini = atual->prox;
		atual->prox = (*m)->prox;
		(*m)->prox = atual;
		atual->ant = *m;
		(*fim)->prox = *ini;
	} else if(atual == *fim) {
		*fim = atual->ant;
		atual->ant->prox = *ini;
		(*ini)->ant = *fim;
		(*m)->prox->ant = atual;
		atual->prox = (*m)->prox;
		atual->ant = *m;
		(*m)->prox = atual;
	} else {
		atual->prox->ant = atual->ant;
		atual->ant->prox = atual->prox;
		atual->prox = (*m)->prox;
		atual->ant = *m;
		(*m)->prox->ant = atual;
		(*m)->prox = atual;
		if(*m == *fim) {
			*fim = (*fim)->prox;
		}
	}
}

void avancar(no **m, int n) {

	while(n != 0) {
		*m = (*m)->prox;
		n--;
	}

}

void retroceder(no **m, int n) {

	while(n != 0) {
		*m = (*m)->ant;
		n--;
	}
}

void destroi_lista(no **lista, no **ini, no **fim) {
	no *atual;

	for(atual = *ini; atual != *fim ; atual = atual->prox)
		free(atual);
}

/*void auxilio(no **m, no **ini, no **fim) {
	no *atual;

	atual = *ini;
	printf("Imprimindo a lista do comeco\n");
	while(atual != *fim) {
		printf("%s\n", atual->str);
		if(*m == atual)
			printf("*m aponta para: %s\n", atual->str);
		atual = atual->prox;
	}
	printf("%s\n", atual->str);
	if(*m == atual)
			printf("*m aponta para: %s\n", atual->str);
	printf("Terminou de imprimir a lista\n");
	printf("ini = %s, fim = %s\n", (*ini)->str, (*fim)->str);
}*/
