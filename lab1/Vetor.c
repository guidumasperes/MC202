#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Vetor.h"

void ini_vet(vetor **v) {
	*v = malloc(sizeof(vetor));
	(*v)->a = malloc(sizeof(aluno));
	(*v)->n_elem = 0;
	(*v)->aloc = 1;
}

void ins_bloco(vetor *v, int q) {
	int i, num, ant_tam, novo_tam, flag;
	aluno cpy;	
	aluno *aux;

	ant_tam = v->n_elem;
	novo_tam = q + v->n_elem; /*O novo_tam deve ser potencia de 2*/
	printf("%d\n", novo_tam);
	v->n_elem = novo_tam;
	if(novo_tam >= v->aloc) {
		do {
			num = novo_tam;
			do {
				num = num / 2;
				printf("%d", num);
			} while(num > 1 || (num % 2 == 0));
			printf("saiu do loop\n");
			if(num == 1) {
				flag = 1;
			} else {
				flag = 0;
				novo_tam++;
				printf("%d\n", novo_tam);
			}
		} while(flag);
		printf("%d\n", novo_tam);
		aux = malloc(v->n_elem * sizeof(aluno));
		aux = v->a;
		if(v->n_elem < 0.25 * novo_tam) { /*Nao pode ficar menos que 0.25 cheio*/
			v->a = malloc(0.5 * novo_tam * sizeof(aluno));
			v->aloc = 0.5 * novo_tam;
		} else {
			v->a = malloc(novo_tam * sizeof(aluno));
			v->aloc = novo_tam;
		}
		for(i = 0; i < ant_tam; i++)
			v->a[i] = aux[i];
		free(aux);
	}
	num = 1;
	printf("Alocado com sucesso!!\n");
	do {
		scanf("%s %d %s", cpy.nome, cpy.ra, cpy.curso);
		for(i = ant_tam - 1; i >= 0 && v->a[i].ra > v->a[v->n_elem+1].ra; i--)
			v->a[i+1] = v->a[i];
		v->a[i+1] = cpy;
		num++;
	}while(num <= q);
}

void rem_bloco(vetor *v) {
	int ra, i;

	scanf("%d", &ra); /*Achar a pessoa que tem esse ra no vetor*/
	i = busca_bin(ra, v);
	for(; i < v->n_elem - 1; i++)
		v->a[i] = v->a[i+1];
	(v->n_elem)--;
}

int busca_bin(int ra, vetor *v) {
	int inf = 0, sup = v->n_elem - 1, meio;

	while(inf <= sup) {
  	meio = (inf + sup)/2;
  	if(ra == v->a[meio].ra) {
    	return meio;
    } else if(ra < v->a[meio].ra) {
    	sup = meio-1;
    } else {
      inf = meio+1;
    }
	}
	return -1;
}

int busca_nome(vetor *v) {
	int i;
	char str[31];

	scanf("%s", str);
	for(i = 0; i < v->n_elem; i++) {
		if(strcmp(str, v->a[i].nome))
			return i;
	}
	return -1;
}

void imprime_curso(vetor *v) {
	int i;
	char str[31];

	scanf("%s", str);
	for(i = 0; i < v->n_elem; i++) {
		if(strcmp(str, v->a[i].curso))
			printf("%s %d %s\n", v->a[i].nome, v->a[i].ra, v->a[i].curso);
	}
}

void imprime_tudo(vetor *v) {
	int i;

	printf("Quantidade de alunos: %d\n", v->n_elem);
	printf("Tamanho do vetor: %d\n", v->aloc);
	for(i = 0; i < v->n_elem; i++)
		printf("%s %d %s", v->a[i].nome, v->a[i].ra, v->a[i].curso);		
}
