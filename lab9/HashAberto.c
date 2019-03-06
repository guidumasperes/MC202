#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"HashAberto.h"
#include"HashLista.h"

int hash_aberto(int sem) {
    return sem % 1783;
}

void inserir_end(no_vet vet_end[1785], char dim[50], int sem) {
    int i, n = hash_aberto(sem);

    if(vet_end[n].vazio == 1) {
        vet_end[n].sem = sem;
        strcpy(vet_end[n].dim, dim);
        vet_end[n].vazio = 0;
    } else {
        for(i = n+1; i <= 1785; i++) {
            if(i == 1785)
                i = -1;
            if(vet_end[i].vazio == 1 || vet_end[i].excl == 1) {
                vet_end[i].sem = sem;
                strcpy(vet_end[i].dim, dim);
                vet_end[i].vazio = 0;
                break;
            }
        }
    }
}

void rem_dim_end(no_vet vet_end[1785], int sem) {
    int i, n = hash_aberto(sem);

    if(vet_end[n].sem == sem) {
        vet_end[n].excl = 1;
    } else {
        for(i = n+1; i <= 1785; i++) {
            if(i == 1785)
                i = -1;
            if(vet_end[i].vazio == 0 && vet_end[i].excl == 0 && vet_end[i].sem == sem) {
                vet_end[i].excl = 1;
                break;
            }
        }
    }
}

char* dim_col_sem(no_vet vet_end[1785], int sem, int k) {
    int i, n = hash_aberto(sem);
    char *str;

    str = malloc(50*sizeof(char));
    str[0] = 'n';
    str[1] = 'a';
    str[2] = 'o';
    str[3] = '\0';
    if(vet_end[n].vazio == 0 && vet_end[n].excl == 0 && vet_end[n].sem == sem) {
        printf("coletando %d sementes na dimensao %s\n", vet_end[n].sem, vet_end[n].dim);
        vet_end[n].excl = 1;
        strcpy(str, vet_end[n].dim);
        return str;
    } else {
        for(i = sem+1; i <= sem+k; i++) {
            n = hash_aberto(i);
            if(i == 1785)
                i = -1;
            if(vet_end[n].vazio == 0 && vet_end[n].excl == 0 && vet_end[n].sem <= sem+k) {
                if(vet_end[n].sem >= sem) {
                    printf("coletando %d sementes na dimensao %s\n", vet_end[n].sem, vet_end[n].dim);            
                    vet_end[n].excl = 1;
                    strcpy(str, vet_end[n].dim);
                    return str;
                }
            }
        }
        if(i == 1785 || i > sem+k)
            printf("wubba lubba dub dub!\n");
    }
    return str;
}