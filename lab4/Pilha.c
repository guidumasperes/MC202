#include<stdlib.h>
#include<stdio.h>
#include"Pilha.h"

/*O lab sera feito usando o vetor como pilha*/

void aloca_matriz(int lar_h) {
	int i;

	matriz = malloc(lar_h * sizeof(int*));
	for(i = 0; i < lar_h; i++)
		matriz[i] = malloc(lar_h * sizeof(int));
}

void le_matriz(int n_portos) {
	int i, j;

	for(i = 0; i < n_portos; i++) {
		for(j = 0; j < n_portos; j++) {
			scanf("%d", &matriz[i][j]);
		}
	}
}

void aloca_vet(int **vet, int n_portos) {

	*vet = malloc(n_portos * sizeof(int));
}

void le_vet(int **vet, int n_portos) {
	int i;

	for(i = 0; i < n_portos - 1; i++)
		scanf("%d", &(*vet)[i]);
}

void aloca_vet_pilha(int lar, int h) {
	int i, j;

	/*Primeiramente aloca um vetor de pilhas*/
	vet_pilha = malloc(lar * sizeof(pilha));
	for(i = 0; i < lar; i++) {
		/*Para cada pilha alocar o tamonho de h inteiros*/
		vet_pilha[i].vet = malloc(h * sizeof(int)); 
		vet_pilha[i].topo = -1;
	}
	/*Preencher o vetor com 0's*/
	for(i = 0; i < lar; i++) {
		for(j = 0; j < h; j++) {
			vet_pilha[i].vet[j] = 0;
		}
	}
}

void carrega(int i, int j, int ind) {

	vet_pilha[i].vet[j] = ind;
	vet_pilha[i].topo = vet_pilha[i].topo + 1;
}

int descarrega(int i, int j) {
	int val;

	val = vet_pilha[i].vet[j];
	vet_pilha[i].vet[j] = 0;
	vet_pilha[i].topo = vet_pilha[i].topo - 1;
	return val;
}

void imprime_mat(int n) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void resolve_pilha(int portos, int porto_atual, int tipo_car, int lar, int h) {
	int i, j, k, val, chegou = 1;

	/*Ao chegar no porto primeiro tem que descarregar o que esta no navio*/
	/*Procurar pelo que descarregar nas pilhas*/
	printf("portos = %d, porto_atual  = %d, tipo_car =%d, lar = %d, h = %d\n", portos, porto_atual, tipo_car, lar, h);
	for(i = 0; i < lar; i++) {
		/*Se o topo == 0 entao nao tem nenhum elemento e nao faz nada porque nao tem o que tirar do contrario vai verificar a pilha*/
		if(vet_pilha[i].topo == -1) {
			printf("aqui1\n");
		} else {
			for(j = vet_pilha[i].topo; j >= 0; j--) {
				/*Se for o que eu quero entrar no if para descarregar*/
				if(porto_atual == vet_pilha[i].vet[j]) {
				/*Se for o que eu quero descarregar deve verificar se e topo, se for, tira ,se nao, verifica se em cima e 0, se for, tira, se nao deve tirar o que esta em cima*/
					if(j == vet_pilha[i].topo) {
						val = descarrega(i, j);
						printf("descarregando\n");
						imprime_sit(lar, h);
					} else {
						if(vet_pilha[i].vet[j+1] == 0) {
							val = descarrega(i, j);
							printf("descarregando\n");
							imprime_sit(lar, h);
						} else {
							/*descarrega o de cima e adiciona na matriz de transporte e depois o de baixo*/
							/*vai descarregando os de cima até chegar ao topo*/
							for(k = j; k < (h - 1) && vet_pilha[i].vet[k+1] != 0; k++) {
								val = descarrega(i, k+1);				
								printf("descarrega o de cima\n");
								imprime_sit(lar, h);
								matriz[porto_atual][val] = matriz[porto_atual][val] + 1;
								printf("Verificando se adc na matriz\n");
								imprime_mat(portos);
							}
							printf("descarrega o de de baixo\n");
							val = descarrega(i, j);
							imprime_sit(lar, h);
						}
					}
				}
			}
		}
	}
	/*Depois ver o tipo de carregamento que deve fazer, os portos mais a frente devem ser carregados primeiro entao comeca do final*/
	for(i = portos - 1; i >= 0 && i != porto_atual; i--) {
		printf("i = %d\n", i);
		if(tipo_car == 1) {
			for(val = matriz[porto_atual][i], j = 0; j < lar && val > 0; j++) {
				if(vet_pilha[j].topo == h - 1) {
				/*Vai para a próxima pilha e vai conferindo até achar uma que nao esteja totalmente cheia*/
				} else {
				/*Eventualmente vai achar uma que nao esta totalmente cheia e vai enche-la ate o topo e depois vai pra proxima pilha*/
					for(k = vet_pilha[j].topo; k < h - 1 && val > 0; k++, val--)
						carrega(j, k + 1, i);
				}
			}
		} else if(tipo_car == 2) {
			for(val = matriz[porto_atual][i], j = lar - 1; j >= 0 && val > 0; j--) {
				/*printf("val = %d, j = %d\n", val, j);*/
				if(vet_pilha[j].topo == h - 1) {
					/*printf("entrou1\n");*/
				} else {
					/*printf("entrou2\n");*/
					for(k = vet_pilha[j].topo; k < h - 1 && val > 0; k++, val--) {
						/*printf("k = %d, val = %d\n", k, val);*/
						carrega(j, k + 1, i);
						/*imprime_sit(lar, h);*/
					}
				}
			}
		} else if(tipo_car == 3) {
			if(chegou == 1)
				j = 0;
			for(val = matriz[porto_atual][i]; val > 0; j++) {
				if(j == lar - 1) { /*Se j chegar ao final fazer ele voltar para o comeco*/
					if(vet_pilha[j].topo == h - 1) {
						j = -1;
						/*Ver se precisa adc o chegou*/
					} else {
						carrega(j, vet_pilha[j].topo + 1, i);
						val--;
						j = -1;
						chegou = 1;
					}
				} else { 
					if(vet_pilha[j].topo == h - 1) {

					} else {
						carrega(j, vet_pilha[j].topo + 1, i);
						val--;
						chegou = 0;
					}
				}
			}
		} else {
			if(chegou == 1)
				j = lar - 1;
			for(val = matriz[porto_atual][i]; val > 0; j--) {
				printf("val = %d, j = %d\n", val, j);
				if(j == 0) {/*Se j chegar ao final fazer ele voltar para o comeco*/
					if(vet_pilha[j].topo == h - 1) {
						j = lar;
						/*Ver se precisa adc o chegou*/
					} else {	
						carrega(j, vet_pilha[j].topo + 1, i);
						printf("carregando\n");
						imprime_sit(lar, h);
						val--;
						j = lar;
						chegou = 1;
					}
				} else {
					if(vet_pilha[j].topo == h - 1) {

					} else {
						carrega(j, vet_pilha[j].topo + 1, i);
						printf("carregando\n");
						imprime_sit(lar, h);
						val--;
						chegou = 0;
					}
				}
			}
		}
	}
}

void imprime_sit(int lar, int h) {
	int i, j;

	for(i = 0, j = h - 1; ; i++) {
		/*printf("i = %d, j = %d\n", i, j);*/
		if(vet_pilha[i].vet[j] == 0) {
			if(i == lar - 1) {
				printf("-\n");
				if(i == lar - 1 && j == 0)
					break;
				j--;
				i = -1;
			} else {
				printf("- ");
			}
		} else {
			if(i == lar - 1) {
				printf("%d\n", vet_pilha[i].vet[j]);
				if(i == lar - 1 && j == 0)
					break;
				j--;
				i = -1;
			} else {
				printf("%d ", vet_pilha[i].vet[j]);
			}
		}
	}
}