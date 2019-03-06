#include<stdio.h>
#include"Lista.h"

int main(void) {
	int *c, ind = 1, n, m, cli, prod, val, i, controle, cnt;
	no **p;
	
	scanf("%d %d", &n, &m);
	cnt = n;
	ini_cliente_produto(&c, &p, n, m); /*Inicializar o vetor e seu conteudo*/
	for(i = 0; i < n; i++)
		p[i] = NULL;
	for(i = 0; i < m; i++)
		scanf("%d", &c[i]);
	while(cnt != 0) {
		scanf("%d", &ind);
		if(ind == 1) {
			scanf("%d %d %d", &cli, &prod, &val);
			adc_lance(&p[prod], cli, prod, val);
			printf("Lance feito com sucesso!\n");
		} else if(ind == 2) {
			scanf("%d %d", &cli, &prod);
			if(canc_lance(&p[prod], cli, prod))
				printf("Lance cancelado com sucesso!\n");
			else
				printf("Lance inexistente!");
		} else if(ind == 3) {
			scanf("%d %d", &cli, &val);
			c[cli] = c[cli] + val;
			printf("Cliente %d com fundos %d.\n", cli, c[cli]);
		} else if(ind == 4) {
			scanf("%d", &prod);
			controle = fin_prod(&p[prod], c);
			if(controle == -1) {
				printf("Sem vencedor.\n");
			} else {
				printf("Vencedor: cliente %d.\n", controle);
			}
			cnt--;
		} else if(ind == 5) {
			scanf("%d", &prod);
			imprime_lances(&p[prod]);
		} else {
			
		}
	}
	return 0;
}
