#ifndef VETOR_H
#define VETOR_H

typedef struct {
	char nome[31];
	int ra;
	char curso[31];
}aluno;

typedef struct {
	aluno *a;
	int n_elem; 
	int aloc;
}vetor;

void ini_vet(vetor **v);

void ins_bloco(vetor *v, int q);

void rem_bloco(vetor *v);

void imprime_curso(vetor *v);

void imprime_tudo(vetor *v);

int busca_bin(int ra, vetor *v);

int busca_nome(vetor *v);

#endif
