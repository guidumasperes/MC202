#include<stdio.h>
#include<stdlib.h>

void ini_mat();
int ver_pos(int lin, int col, char p);
int resolve(char p, int col, int h, int q);
void imprime_sol();
void libera_mem();

char **matriz;
int n;

int main() {
    int h, q, d, i, x, y;
    char p[2];

    scanf("%d", &n);
    ini_mat(); /*Funcao para alocar o tamanho da matriz e inicializa-la*/
    scanf("%d %d", &h, &q);
    scanf("%d", &d);
    for(i = 0; i < d; i++) {
        scanf("%s", p);
        scanf("%d", &x);
        scanf("%d", &y);
        if(p[0] == 'H') {
            matriz[x][y] = 'I';
        } else {
            matriz[x][y] = 'J';
        }
    }
    resolve('Q', 0, h, q);
    imprime_sol();
    libera_mem();
    return 0;
}

void ini_mat() {
    int i, j;

    matriz = malloc(n*sizeof(char *));
    for(i = 0; i < n; i++)
        matriz[i] = malloc(n*sizeof(char));
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            matriz[i][j] = '-';
}

int ver_pos(int lin, int col, char p) {
    int i, j;

    if(p == 'Q') {
        /*for(i = 0; i < col; i++)
            if(matriz[lin][i] != '-')
                return 0;
        for(i = lin, j = col; i >= 0 && j >= 0; i--, j--)
            if(matriz[i][j] != '-')
                return 0;
        for(i = lin, j = col; j >= 0 && i < n; i++, j--)
            if(matriz[i][j] != '-')
                return 0;*/
        for(i = 0; i < n; i++)
            if(matriz[lin][i] != '-')
                return 0;
        for(i = 0; i < n; i++)
            if(matriz[i][col] != '-')
                return 0;
        for(i = lin, j = col; i < n && j < n; i++, j++)
            if(matriz[i][j] != '-')
                return 0;
        for(i = lin, j = col; i < n && j >= 0; i++, j--)
            if(matriz[i][j] != '-')
                return 0;
        for(i = lin, j = col; i >= 0 && j < n; i--, j++)
            if(matriz[i][j] != '-')
                return 0;
        for(i = lin, j = col; i >= 0 && j >= 0; i--, j--)
            if(matriz[i][j] != '-')
                return 0;
    } else {
        if((lin - 2) >= 0 && (col - 1) >= 0) {
            if(matriz[lin - 2][col - 1] != '-')
                return 0;
        } else if((lin - 2) >= 0 && (col + 1) <= n) {
            if(matriz[lin - 2][col + 1] != '-')
                return 0;
        } else if((lin - 1) >= 0 && (col - 2) >= 0) {
            if(matriz[lin - 1][col - 2] != '-')
                return 0;
        } else if((lin - 1) >= 0 && (col + 2) <= n) {
            if(matriz[lin - 1][col + 2] != '-')
                return 0;
        } else if((lin + 2) <= n && (col - 1) >= 0) {
            if(matriz[lin + 2][col - 1] != '-')
                return 0;
        } else if((lin + 2) <= n && (col + 1) <= n) {
            if(matriz[lin + 2][col + 1] != '-')
                return 0;
        } else if((lin + 1) <= n && (col - 2) >= 0) {
            if(matriz[lin + 1][col - 2] != '-')
                return 0;
        } else if((lin + 1) <= n && (col + 2) <= n) {
            if(matriz[lin + 1][col + 2] != '-')
                return 0;
        } else {

        }
    }
    return 1;
}

int ver_pos1(int lin, int col, char p) {
    int i, j;

    if(p == 'Q') {
        /*for(i = 0; i < col; i++)
            if(matriz[lin][i] == 'Q' || matriz[lin][i] == 'J')
                return 0;
        for(i = lin, j = col; i >= 0 && j >= 0; i--, j--)
            if(matriz[i][j] == 'Q' || matriz[i][j] == 'J')
                return 0;
        for(i = lin, j = col; j >= 0 && i < n; i++, j--)
            if(matriz[i][j] == 'Q' || matriz[i][j] == 'J')
                return 0;*/
        for(i = 0; i < n; i++)
            if(matriz[lin][i] == 'Q' || matriz[lin][i] == 'J')
                return 0;
        for(i = 0; i < n; i++)
            if(matriz[i][col] == 'Q' || matriz[i][col] == 'J')
                return 0;
        for(i = lin, j = col; i < n && j < n; i++, j++)
            if(matriz[i][j] == 'Q' || matriz[i][j] == 'J')
                return 0;
        for(i = lin, j = col; i < n && j >= 0; i++, j--)
            if(matriz[i][j] == 'Q' || matriz[i][j] == 'J')
                return 0;
        for(i = lin, j = col; i >= 0 && j < n; i--, j++)
            if(matriz[i][j] == 'Q' || matriz[i][j] == 'J')
                return 0;
        for(i = lin, j = col; i >= 0 && j >= 0; i--, j--)
            if(matriz[i][j] == 'Q' || matriz[i][j] == 'J')
                return 0;
    } else {
        if((lin - 2) >= 0 && (col - 1) >= 0) {
            if(matriz[lin - 2][col - 1] == 'H' || matriz[lin - 2][col - 1] == 'I')
                return 0;
        } else if((lin - 2) >= 0 && (col + 1) <= n) {
            if(matriz[lin - 2][col + 1] == 'H' || matriz[lin - 2][col + 1] == 'I')
                return 0;
        } else if((lin - 1) >= 0 && (col - 2) >= 0) {
            if(matriz[lin - 1][col - 2] == 'H' || matriz[lin - 1][col - 2] != 'I')
                return 0;
        } else if((lin - 1) >= 0 && (col + 2) <= n) {
            if(matriz[lin - 1][col + 2] == 'H' || matriz[lin - 1][col + 2] == 'I')
                return 0;
        } else if((lin + 2) <= n && (col - 1) >= 0) {
            if(matriz[lin + 2][col - 1] == 'H' || matriz[lin + 2][col - 1] == 'I')
                return 0;
        } else if((lin + 2) <= n && (col + 1) <= n) {
            if(matriz[lin + 2][col + 1] == 'H' || matriz[lin + 2][col + 1] == 'I')
                return 0;
        } else if((lin + 1) <= n && (col - 2) >= 0) {
            if(matriz[lin + 1][col - 2] == 'H' || matriz[lin + 1][col - 2] == 'I')
                return 0;
        } else if((lin + 1) <= n && (col + 2) <= n) {
            if(matriz[lin + 1][col + 2] == 'H' || matriz[lin + 1][col + 2] == 'I')
                return 0;
        } else {

        }
    }
    return 1;
}

int resolve(char p, int col, int h, int q) {
    int i;

    scanf("%*d");
    printf("h = %d e q = %d\n", h, q);
    imprime_sol();
    if(h == 0 && q == 0){
        return 1;
    } else {
        for(i = 0; i < n; i++) {
            if(matriz[i][col] == '-') {
                printf("i = %d e col = %d\n", i, col);
                if(i+1 < n && col-2 >= 0)
                    printf("matriz[%d][%d] = %c\n", i, col, matriz[i+1][col-2]);
                if(ver_pos(i , col, 'Q') && ver_pos1(i , col, 'H') && ver_pos1(i , col, 'Q')) { /*Verifica se pode colocar a rainha*/
                    if(q > 0) {
                        matriz[i][col] = 'Q';
                        q--;
                        p = 'Q';
                        if(resolve('Q', col + 1, h, q))
                            return 1;
                        matriz[i][col] = '-';
                        q++;
                    } else {
                        11
                    }
                } else if(ver_pos(i, col, 'H') && ver_pos1(i , col, 'Q') && ver_pos1(i , col, 'H')) { /*Se nao puder verifica se pode colocar o cavalo*/
                    if(h > 0) {
                        matriz[i][col] = 'H';
                        h--;
                        p = 'H';
                        if(resolve('H', col + 1, h, q))
                            return 1;
                        matriz[i][col] = '-';
                        h++;
                    } else {
                        
                    }
                } else { /*Se nao der pra colocar nenhum dos dois so segue com a recursao*/

                }
            } else {
                return resolve(p, col + 1, h, q);
            }
        }
        return 0;
    }
}

void imprime_sol() {
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(matriz[i][j] == 'I') {
                matriz[i][j] = 'H';
            } else if(matriz[i][j] == 'J') {
                matriz[i][j] = 'Q';
            } else {

            }
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void libera_mem() {
    int i;

    for(i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}