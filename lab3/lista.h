#ifndef LISTA_H_
#define LISTA_H_

typedef struct node{
	char str[31];
	struct node *prox;
	struct node *ant;
}no;

void ini_lista(no **lista, no **m, no **ini, no **fim);

void ins_mus(no **m, no **ini, no **fim, char mus[31]);

void rem_mus(no **m, no **ini, no **fim, int n);

void esc_prox(no **m, no **ini, no **fim, char proxima[31]);

void avancar(no **m, int n);

void retroceder(no **m, int n);

void destroi_lista(no **lista, no **ini, no **fim);

void auxilio(no **m, no **ini, no **fim);

#endif
