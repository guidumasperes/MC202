#ifndef LISTA_H
#define LISTA_H

typedef struct {
	struct no *n;
	int id_cli;
	int lance;
}no;

void ini_cliente_produto(int **c, no ***p, int n, int m);

void adc_lance(no **p, int cli, int prod, int val);

int canc_lance(no **p, int cli, int prod);

int fin_prod(no **p, int *c, int *maior);

void imprime_lances(no **p);

#endif
