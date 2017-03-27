#include <stdio.h>
#include <stdlib.h>

int *gera_vetor (int tamanho);
void preenche_vetor (int *vetor, int tamanho);
void imprime_vetor (int *vetor, int tamanho);
int maior_valor (int *vetor, int tamanho);
float media_valores (int *vetor, int tamanho);
void maior_que_media (int *vetor, int tamanho, float media);

int main()
{
    int *vetor, tamanho, maior;
    float media;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = gera_vetor(tamanho);
    preenche_vetor(vetor, tamanho);
    imprime_vetor(vetor, tamanho);
    maior = maior_valor(vetor, tamanho);
    printf("\nMaior valor: [%d]", maior);
    media = media_valores(vetor, tamanho);
    printf("\nMedia dos valores: [%.2f]\n", media);
    maior_que_media(vetor, tamanho, media);

    return 0;
}

int *gera_vetor(int tamanho)
{
    int *vetor;
    if (tamanho > 0)
    {
        vetor = (int*)malloc(tamanho * sizeof(int));
    }else
    {
        return NULL;
    }

    return vetor;
}

void preenche_vetor (int *vetor, int tamanho)
{
    int i;

    if (tamanho > 0)
    {
        for(i=0; i<tamanho; i++)
        {
            printf("Informe um valor inteiro para a posicao [%d] do vetor: ", i);
            scanf("%d", &vetor[i]);
        }
    }
}

void imprime_vetor (int *vetor, int tamanho)
{
    int i;

    if (vetor != NULL)
    {
        for(i=0; i<tamanho; i++)
        {
            printf("[%d]\t", vetor[i]);
        }
    }else{
        printf("vetor vazio!!");
    }
}

int maior_valor (int *vetor, int tamanho)
{
    int i, maior = vetor[0];

    if (vetor != NULL)
    {
        for(i=0; i<tamanho; i++)
        {
            if(vetor[i] > maior)
            {
                maior = vetor[i];
            }
        }
    }else{
        printf("vetor vazio!!");
    }

    return maior;
}

float media_valores (int *vetor, int tamanho)
{
    float media = 0;
    int i;

    for(i=0; i<tamanho; i++)
    {
        media+=vetor[i];
    }
    media = media/tamanho;

    return media;
}

void maior_que_media (int *vetor, int tamanho, float media)
{
    int i;

    if (vetor != NULL)
    {
        printf("Valores maiores que a media:\n");
        for(i=0; i<tamanho; i++)
        {
            if(vetor[i] > media)
            {
                printf("[%d]\t", vetor[i]);
            }
        }
    }else{
        printf("vetor vazio!!");
    }
}
