#include <stdio.h>
#include <stdlib.h>

typedef struct _PILHA_                              /*Estrutura da Pilha*/
{
    int max, size, beg, end;                        /*Caracteristicas*/
    int* vet;                                       /*Armazenamento de dados*/

}PILHA;

PILHA* criar_pilha(int max);                        /*Cria e retorna Pilha*/
void inserir_pilha(PILHA* pilha, int num);          /*Empilha elemento (push)*/
void remover_pilha(PILHA* pilha);                   /*Desempilha elemento (pop)*/
void destruir_pilha(PILHA* pilha);
int mostrar_pilha(PILHA* pilha, int num);           /*Retorna elemento da posição num sem dar pop (stackpop)*/


int main()
{
    PILHA *p;
    int a, i;

    p = criar_pilha(3);
    inserir_pilha(p, 1);
    inserir_pilha(p, 2);
    inserir_pilha(p, 3);
    remover_pilha(p);
    inserir_pilha(p, 4);
    for(i = p->size-1; i >=0 ; i--)
    {
        a = mostrar_pilha(p, i);
        printf("%d\n", a);
    }

    return 0;
}

PILHA* criar_pilha(int max)
{
    if(max > 0)                                                 /*Testa se o espaco maximo de armazenamento eh vaildo*/
    {
        PILHA* pilha = (PILHA*)malloc(sizeof(PILHA));           /*Aloca memoria para armazenar a estrutuda PILHA*/

        pilha->max = max;                                       /*Atributo max da pilha recebe o valor informado*/
        pilha->vet = (int*)malloc(sizeof(int)* pilha->max);     /*Vetor de armazenamento aloca o espaco max para pilha*/
        pilha->beg = 0;                                         /*Inicializa topo da pilha*/
        pilha->size = 0;                                        /*Inicializa espaco ocupado da pilha*/
        pilha->end = pilha->max;                                /*Atributo end recebe o limite de empilhamento da pilha*/

        return pilha;                                           /*Retorna pilha criada e inicializada*/
    }

    return NULL;                                                /*Retorna NULL para falha na criação*/
}

void inserir_pilha(PILHA* pilha, int num)
{
    if((pilha != NULL) && (pilha->vet != NULL) && (pilha->size < pilha->max))   /*Verifica se a pilha e o vetor foram alocados e se a quantidade de elementos eh melhor q o tamnaho maximo*/
    {
        pilha->vet[pilha->size] = num;                                          /*insere elemento no topo da pilha*/
        pilha->size++;                                                          /*almenta o tamnho da pilha*/

        if(pilha->end < pilha->size -1)
        {
            pilha->end++;
        }
        else
        {
            pilha->end = 0;
        }
    }
}

void remover_pilha(PILHA* pilha)
{
    if((pilha != NULL) && (pilha->vet != NULL) && (pilha->size >= 0))   /*Verifica se a pilha e o vetor foram alocados e se ha elementos na pilha*/
    {
        pilha->size--;                                                  /*Decrementa tamnho pilha*/

        if(pilha->beg < pilha->size -1)
        {
            pilha->beg++;
        }
        else
        {
            pilha->beg = 0;
        }
    }
}

void destruir_pilha(PILHA* pilha)
{
    if(pilha != NULL && pilha->size < 0)    /*Verifica se a pilha existe e se ha elemento sa pilha*/
    {
        free(pilha->vet);                   /*Desaloca vetor de elementos*/
        free(pilha);                        /*Desaloca pilha*/
    }
}

int mostrar_pilha(PILHA* pilha, int num)
{
    if(pilha != NULL && pilha->vet != NULL && pilha->size >= num)   /*Verifica se a pilha e o vetor existem e se a posicao solicitada eh valida*/
    {
        return pilha->vet[num];                                     /*Retorna elemento da pilha*/
    }
    return 0;
}
