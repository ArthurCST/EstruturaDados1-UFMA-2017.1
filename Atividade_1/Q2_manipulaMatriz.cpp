#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **aloca_matriz(int l, int c);
void preenche_matriz(int** aux, int l, int c);
void imprime_matriz(int** aux, int l, int c);
void multiplica_matriz(int** aux1, int** aux2, int** aux3, int l1, int l2, int c1, int c2);
void transposta_matriz(int **aux, int l, int c);
void diagonal_principal_matriz(int** aux, int l, int c);
void teto_matriz(int** aux, int l, int c);
void piso_matriz(int** aux, int l, int c);


int **aloca_matriz(int l, int c)
{
    int i, **aux;
    aux = (int**)malloc(l*sizeof(int*));
    if(aux != NULL)
    {
        for(i=0; i<l; i++)
        {
            aux[i] = (int*)malloc(c*sizeof(int));
        }
    }

    return aux;
}

void preenche_matriz(int** aux, int l, int c)
{
    int i, j;

    if(aux != NULL)
    {
        for(i=0; i<l; i++)
        {
            for(j=0; j<c; j++)
            {
                if(aux[i] != NULL)
                {
                    printf("[%d][%d] -> ", i+1, i+j);
                    scanf("%d", &aux[i][j]);
                }
            }
        }
    }
}

void imprime_matriz(int** aux, int l, int c)
{
    int i, j;

    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("\t%d", aux[i][j]);
        }
        printf("\n");
    }

    printf("\n");

}

void multiplica_matriz(int** aux1, int** aux2, int** aux3, int l1, int l2, int c1, int c2)
{
    int i, j, k;

    if(c1 == l2)
    {
        for(i=0; i<l1; i++)
        {
            for(j=0; j<c2; j++)
            {
                for(k=0; k<l2; k++)
                {
                    aux3[i][j] += aux1[i][k]*aux2[k][j];
                }
            }
        }
    }
}

void transposta_matriz(int **aux, int l, int c)
{
    int i, j;

    printf("----- Transposta da Matriz B -----\n");
    for(i=0; i<c; i++)
    {
        for(j=0; j<l; j++)
        {
            printf(" %d", aux[j][i]);
        }
        printf("\n");
    }
}

void diagonal_principal_matriz(int** aux, int l, int c)
{
    int i, j;

    printf("----- Elementos da Diagonal Principal da Matriz A ------\n");
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            if(i == j)
            {
                printf("\t%d", aux[i][j]);
            }
            else
            {
                printf("\t ");
            }
        }
        printf("\n");
    }
}

void teto_matriz(int** aux, int l, int c)
{
    int i, j, x;

    x = l;
    x = ceil(x/2);

    printf("----- Elementos da Linha ceil(n/2) da Matriz A ------\n");
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            if((i+1) == x)
            {
                printf(" %d", aux[i][j]);
            }
        }
        printf("\n");
    }
}

void piso_matriz(int** aux, int l, int c)
{
    int i, j, y;

    y = c;
    y = floor(y/2);

    printf("----- Elementos da Coluna floor(f/2) da Matriz B ------\n");
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            if((j+1) == y)
            {
                printf(" %d", aux[i][j]);
            }
        }
        printf("\n");
    }
}


int main()
{
    int n, m, p, f, **a, **b, **c;

    printf("Linha da matriz A: ");
    scanf("%d", &n);
    printf("Coluna da matriz A: ");
    scanf("%d", &m);
    printf("Linha da matriz B: ");
    scanf("%d", &p);
    printf("Coluna da matriz B: ");
    scanf("%d", &f);

    //Aloca e Preenche a matriz A
    a = aloca_matriz(n, m);
    preenche_matriz(a, n, m);

    //Aloca e Preenche a matriz B
    b = aloca_matriz(p, f);
    preenche_matriz(b, p, f);

    //Mostra as Matrizes A e B
    imprime_matriz(a, n, m);
    imprime_matriz(b, p, f);

    //Aloca a Matriz C
    c = aloca_matriz(n, f);

    //Multiplicação das matrizes A e B
    multiplica_matriz(a, b, c, n, p, m, f);

    //Mostra a Matriz C
    imprime_matriz(c, n, f);

    //Imprime a Transposta da Matriz B
    transposta_matriz(b, p, f);

    //Imprime a Diagonal principal da Matriz A
    diagonal_principal_matriz(a, n, m);

    //Mostra a Linha da Matriz A de numero igual a função ceil(linha_da_matriz/2)
    teto_matriz(a, n, m);

    //Mostra a Coluna da Matriz B de numero igual a função floor(coluna_da_matriz/2)
    piso_matriz(b, p, f);

    return 0;
}

