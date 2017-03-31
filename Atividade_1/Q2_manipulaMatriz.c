#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** alocar_matriz(int, int);
void preencher_matriz(int**, int, int);
void mostrar(int**, int, int);
int** multiplicar_matriz(int**, int**, int, int, int, int);
int** transposta(int**, int, int);
void diagonal(int**, int, int);
void imprimir_linha(int**, int, int);
void imprimir_coluna(int**, int, int);

int main(void) {
	unsigned int l1, c1, l2, c2;

	printf("Entre com o numero de linhas: ");
	scanf("%d", &l1);

	printf("Entre com o numero de colunas: ");
	scanf("%d", &c1);

	int** matrizA;

	matrizA = alocar_matriz(l1, c1);

	preencher_matriz(matrizA, l1, c1);

	printf("Entre com o numero de linhas: ");
	scanf("%d", &l2);

	printf("Entre com o numero de colunas: ");
	scanf("%d", &c2);

	int** matrizB;

	matrizB = alocar_matriz(l2, c2);

	preencher_matriz(matrizB, l2, c2);

    puts("\n\nMatriz produto");
	mostrar(multiplicar_matriz(matrizA, matrizB, l1, c1, l2, c2), l1, c2);
	puts("\n\nMatriz B transposta");
	mostrar(transposta(matrizB, l2, c2), c2, l2);
	puts("\n\nDiagonal principal da matriz A");
	diagonal(matrizA, l1, c1);
	puts("\n\nTeto linha");
	imprimir_linha(matrizA, l1, c1);
	puts("\n\nPiso coluna");
	imprimir_coluna(matrizB, l2, c2);

	return 0;
}

int** alocar_matriz(int linha, int coluna) {
	int** matriz;

	matriz = (int**)malloc(linha * sizeof(int*));

	unsigned int i;

	for(i = 0; i < linha; i ++) {
		matriz[i] = (int*)malloc(coluna * sizeof(int));
	}

	return matriz;
}

void preencher_matriz(int** matriz, int linha, int coluna) {
	unsigned int i, j;

	for(i = 0; i < linha; i ++) {
		for(j = 0; j < coluna; j ++) {
            printf("Entre com o valor da posicao [%d][%d]", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
}

void mostrar(int** matriz, int linha, int coluna) {
	unsigned int i, j;

	for(i = 0; i < linha; i ++) {
		for(j = 0; j < coluna; j ++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
}

int** multiplicar_matriz(int** matrizA, int** matrizB, int l1, int c1, int l2, int c2) {
	if(c1 == l2) {
		int** matrizC;

		matrizC = alocar_matriz(l1, c2);

		unsigned int i, j, k;

		for(i = 0; i < l1; i ++) {
			for(j = 0; j < c2; j ++) {
				matrizC[i][j] = 0;

				for(k = 0; k < l2; k ++) {
					matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
				}
			}
		}

		return matrizC;
	}

	return NULL;
}

int** transposta(int** matriz, int l, int c) {
	int** tmp;

	tmp = alocar_matriz(c, l);

	unsigned int i, j;

	for(i = 0; i < c; i ++) {
		for(j = 0; j < l; j++) {
			tmp[i][j] = matriz[j][i];
		}
	}

	return tmp;
}

void diagonal(int** matriz, int num_linhas, int num_colunas) {
	unsigned int i, j;

	for(i = 0; i < num_linhas; i ++) {
		for(j = 0; j < num_colunas; j ++) {
			if(i == j) {
				printf("%d ", matriz[i][j]);
			}
		}
	}
}

void imprimir_linha(int** matriz, int num_linhas, int num_colunas) {
	float x;

	x = num_linhas;
	x = ceil(x/2);

	unsigned int i, j;

    for(i = 0; i < num_linhas; i ++) {
		for(j = 0; j < num_colunas; j ++) {
		    if((i + 1) == x) {
		        printf("%d ", matriz[i][j]);
		    }
		}
	}
}

void imprimir_coluna(int** matriz, int num_linhas, int num_colunas) {
	float y = num_colunas;
        y = floor(y / 2);

        unsigned int i, j;
        for(i = 0; i < num_linhas; i ++) {
        	for(j = 0; j < num_colunas; j ++) {
	            if((j + 1) == y) {
	                printf("%d ", matriz[i][j]);
	            }
	        }
        }
}

