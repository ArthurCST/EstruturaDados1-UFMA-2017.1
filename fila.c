#include <stdio.h>
#include <stdlib.h>
#define TRUE 1;
#define FALSE 0;

typedef struct _Fila_{
    int max, size, beg, end;
    void** vet;
}Fila;

Fila* criar_fila(int max);
int destruir_fila(Fila *f);
int inserir_fila(Fila *f, void* x);
int remove_fila(Fila *f);

int main()
{
    return 0;
}

Fila* criar_fila(int max)
{
    if(max > 0)
    {
        Fila *f;
        f = (Fila*)malloc(sizeof(Fila));

        f->max = max;
        f->vet = (void**)malloc(f->max * sizeof(void*));

        f->size = 0;
        f->beg = 0;
        f->end = 0;

        return f;
    }
    return NULL;
}

int destruir_fila(Fila *f)
{
    if(f != NULL && f->size < 1)
    {
        free(f->vet);
        free(f);
        return TRUE;
    }
    return FALSE
}

int inserir_fila(Fila *f, void* x)
{
    if(f != NULL && f->vet != NULL && f->size < f->max -1)
    {
        f->vet = x;
        f->size++;

        if(f->end < f->size -1)
            f->end++;
        else
            f->end = 0;

        return TRUE;
    }

    return FALSE;
}

int remove_fila(Fila *f)
{
    int i;

    if(f != NULL && f->vet != NULL && f->size >= 0)
    {

        for(i=0; i<f->size-1; i++)
        {
            f->vet[i] = f->vet[i+1];
        }

        f->size--;

        if(f->beg < f->size -1)
            f->beg++;
        else
            f->beg = 0;

        return TRUE;
    }

    return FALSE;
}
