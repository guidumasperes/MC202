#ifndef DEQUE_H
#define DEQUE_H

typedef struct {
	int ini_turno;
	int qnt_turno;
	int urgencia;
}pedido;

typedef struct queue {
	struct queue *prox;
	struct queue *ant;
	int turno_rest;
	int id_ped;
}fila;

typedef struct machine{
	fila *ptr;
	fila *ini;
	fila *fim;
}maq;

void aloca_vet(pedido **p, int ovos);

void cria_vet_maq(maq **p_vet_maq, int maquinas);

void insere_pedido(int qnt_turno, int indice, int urg, int n_ped, maq **vet_maq);

int troca_elem(int k, int i, maq **vet_maq);

void decrementa_turnos(int maquinas, maq **vet_maq);

void checa_prod(maq **vet_maq, int indice);

/*void auxilio(int maquinas, maq *vet_maq);*/

int verifica_n_elem(fila *ptr);

#endif