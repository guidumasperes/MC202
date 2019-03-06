#include<stdio.h>
#include"Vetor.h"

int main (void) {

int command, q;
vetor *p;

ini_vet(&p);

do {
	scanf("%d", &command);
	if(command == 1) {
		scanf("%d", &q);
		ins_bloco(p, q);
		printf("Alunos inseridos com sucesso!\n");
	} else if(command == 2) {
		rem_bloco(p);
		printf("Alunos removidos com sucesso!\n");
	} else if(command == 3) {
		q = busca_nome(p);
		if(q == -1)
			printf("Aluno nao encontrado.\n");
	  else
			printf("%s %d %s\n", p->a[q].nome, p->a[q].ra, p->a[q].curso);
	} else if(command == 4) {
			scanf("%d", &q);
			q = busca_bin(q, p);
			if(q == -1)
			printf("Aluno nao encontrado.\n");
	  else
			printf("%s %d %s\n", p->a[q].nome, p->a[q].ra, p->a[q].curso);
	} else if(command == 5) {
			imprime_curso(p);
	} else if(command == 6) {
			imprime_tudo(p);
	} else {

	}
} while(command != 9);
return 0;
}
