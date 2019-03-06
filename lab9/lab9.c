#include<stdio.h>
#include<string.h>
#include"HashLista.h"
#include"HashAberto.h"

void inicializa_hash(no_lista *vet_lista[1785], no_vet vet_end[1785]);

int main() {
    int D, K, s, control = 1;
    char d[50], confere[5] = "nao";
    no_lista *vet_lista[1785];
    no_vet vet_end[1785];

    inicializa_hash(vet_lista, vet_end);
    scanf("%d %d", &D, &K);
    while(control != 9) {
        scanf("%d", &control);
        if(control == 1) {
            scanf("%s %d", d, &s);
            inserir_lista(vet_lista, d, s);
            inserir_end(vet_end, d, s);
        } else if(control == 2) {
            scanf("%s", d);
            busca_dimensao(vet_lista, d);
        } else if(control == 3) {
            scanf("%s", d);
            s = rem_dim_lista(vet_lista, d);
            rem_dim_end(vet_end, s);
            printf("chave removida!\n");
        } else if(control == 4) {
            scanf("%d", &s);
            strcpy(d, dim_col_sem(vet_end, s, K));
            if(strcmp(d, confere) != 0) 
                rem_dim_lista(vet_lista, d);
        } else {

        }
    }
    return 0;
}

void inicializa_hash(no_lista *vet_lista[1785], no_vet vet_end[1785]) {
    int i;

    for(i = 0; i < 1785; i++) {
            vet_lista[i] = NULL;
            vet_end[i].vazio = 1;
            vet_end[i].excl = 0;
    }
}