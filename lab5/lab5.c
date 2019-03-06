#include<stdio.h>
#include<stdlib.h>
#include"Deque.h"

/*Otimizar o codigo*/

int main(void) {
	int cnt, ovos, maquinas, turno = 0, i, j = 0, indicador = 0, k, controlador = 0;
	pedido *vet_ped;
	maq *vet_maq;

	scanf("%d %d", &ovos, &maquinas);
	/*printf("%d %d\n", ovos, maquinas);*/
	cnt = ovos;
	aloca_vet(&vet_ped, ovos);
	for(i = 0; i < ovos; i++) {
		scanf("%d %d %d", &vet_ped[i].ini_turno, &vet_ped[i].qnt_turno, &vet_ped[i].urgencia);
	}
	cria_vet_maq(&vet_maq, maquinas);
	/*for(i = 0; i < ovos; i++)
		printf("%d %d %d\n", vet_ped[i].ini_turno, vet_ped[i].qnt_turno, vet_ped[i].urgencia);*/
	while(cnt) {
		/*printf("turno = %d\n", turno);
		printf("cnt = %d\n", cnt);*/
		if(turno != 0) {
			for(i = 0; i < maquinas; i++) {
				/*printf("i = %d\n", i);*/
				if(vet_maq[i].ptr != NULL) {
					if(vet_maq[i].ptr->turno_rest == 0) {
						cnt--;
						/*auxilio(maquinas);*/
						/*printf("indicador = %d, vet_maq[%d].ptr->id_ped = %d\n", indicador, i, vet_maq[i].ptr->id_ped);*/
						if(indicador == 0) {
							printf("Turno %d: ", turno);
							checa_prod(&vet_maq, i);
							indicador = 1;
						} else {
							printf(", ");
							checa_prod(&vet_maq, i);
						}
					}
				}
			}
			if(indicador == 1) {
				printf("\n");
				indicador = 0;
			}
		}
		/*Vai no vetor pedido e procura todos os turnos que combinam com o turno atual e vai inserindo nas maquinas de acordo com a prioridade*/
		for(i = 0; i < ovos; i++) {
			if(vet_ped[i].ini_turno == turno) {
				/*printf("vet_ped[%d].ini_turno = %d\n", i, vet_ped[i].ini_turno);*/
				if(vet_ped[i].urgencia == 0){
					/*Adiciona no final da fila*/
					/*printf("check1\n");*/
					insere_pedido(vet_ped[i].qnt_turno, j, 0, i, &vet_maq);
				} else {				
					/*Adiciona no comeco da fila*/
					/*Se não for com urgencia entra no 1 if se for entra nesse e verifica se esse tambem e com urgencia se for coloca no inicio, duvida: deve colocar na frente ou atras do pedido que ja e urgente ? */
					/*printf("check2\n");*/
					insere_pedido(vet_ped[i].qnt_turno, j, 1, i, &vet_maq);
				}
				j++;
				if(j == maquinas)
					j = 0;
			}
		}
		/*Verifica se alguma maquina esta vazia*/
		for(i = 0; i < maquinas; i++) {
			/*printf("vet_maq[%d].ptr = %d\n", i, vet_maq[i].ptr);*/
			if(vet_maq[i].ptr == NULL) { /*Se estiver vazia faz outro contador para procurar alguma que possa ter mais de um ovo*/
				/*printf("i = %d\n", i);*/
				for(k = 0; k < maquinas; k++) {
					controlador = troca_elem(k, i, &vet_maq);
					if(controlador == 1)
						break;
				}
			}
		}
		/*printf("turno = %d\n", turno);
		auxilio(maquinas, vet_maq);*/
		decrementa_turnos(maquinas, &vet_maq);
		turno++;
	}
	free(vet_maq);
	free(vet_ped);
	return 0; /*o programa termina quando todas as filas estão vazias*/
}
