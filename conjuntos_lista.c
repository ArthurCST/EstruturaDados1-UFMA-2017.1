#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE_
{
    void* number;
    struct _NODE_* next;
}NODE;

typedef struct _LIST_
{
    struct _NODE_* head;
}LIST;

/*==== Funcoes de lista ====*/
LIST* create_list();
bool destroy_list(LIST *list);
void insert_head(LIST *list, void* number);
bool query_list(LIST *list, void* number);
bool remove_node(LIST *list, void* number);
void* get_first(LIST *list);
void* get_next(LIST *list);
int get_size_list(LIST *list);
void print_list(LIST* list);

/*==== Funcoes de conjuntos ====*/
LIST* unity(LIST *listA, LIST *listB);
LIST* intersection(LIST *listA, LIST *listB);
LIST* difference(LIST *listA, LIST *listB);
LIST* complement(LIST *listA, LIST *listB);
bool contained (LIST *listA, LIST *listB);

void menu();

void main()
{
    int i, tamA, tamB, num;
    LIST *listA, *listB, *listC;


    //ENTRADA DO TAMANHO DO VETOR A E CRIA플O DAO VETOR A
    printf("Tamanho de elementos do conjunto A: ");
    scanf("%d", &tamA);

    //ENTRADA DO TAMANHO DO VETOR B E CRIA플O DO VETOR B
    printf("Tamanho de elementos do conjunto B: ");
    scanf("%d", &tamB);

    //CRIA플O E INSER플O DE ELEMENTOS NA LISTA A
    listA = create_list();
    for(i=0; i<tamA; i++)
    {
        scanf("%d", &num);
        insert_head(listA, (void*)&num);
    }

    //CRIA플O E INSER플O DE ELEMENTOS NA LISTA B
    listB = create_list();
    for(i=0; i<tamB; i++)
    {
        scanf("%d", &num);
        insert_head(listA, (void*)&num);
    }

    listC = create_list();
    system("cls");

    printf("A = ");
    print_list(listA);
    printf("\nB = ");
    print_list(listB);

    int op;
    menu();
    switch (op)
    {
    case 1:
        system("cls");
        listC = unity(listA, listB);
        print_list(listC);
        break;
    case 2:
        system("cls");
        listC = intersection(listA, listB);
        print_list(listC);
        break;
    case 3:
        system("cls");
        listC = difference(listA, listB);
        print_list(listC);
        break;
    case 4:
        system("cls");
        listC = complement(listA, listB);
        print_list(listC);
        break;
    case 5:
        system("cls");
        if(contained(listA, listB)==true)
        {
            printf("\nConjunto A esta contido em B\n");
        }else{
            printf("\nConjunto A nao esta contido no conjunto B\n");
        }
        break;
    case 6:
        system("cls");
        if(destroy_list(listA)== true && destroy_list(listB)== true && destroy_list(listC)== true)
        {
            printf("Todos os dados foram apagados");
        }else{
            printf("erro na destruicao dos dados");
        }

        break;
    }

}

LIST* create_list()
{
    LIST *list = (LIST*)malloc(sizeof(LIST));
    if(list!=NULL)
    {
        list->head = NULL;
        return list;
    }
    return NULL;
}

bool destroy_list(LIST *list)
{
    if(list!=NULL && list->head != NULL)
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        NODE* node_prev = (NODE*)malloc(sizeof(NODE));
        node = list->head;
        node_prev = NULL;
        while(list->head != NULL)
        {
            list->head = node->next;
            node_prev = node;
            node = node->next;
            free(node_prev);
        }
        free(list);
        return true;
    }
    return false;
}
void insert_head(LIST *list, void* number)
{
    if(list != NULL)
    {
        NODE* new_node = (NODE*)malloc(sizeof(NODE));
        new_node->number = number;
        new_node->next = list->head;
        list->head = new_node;
    }
}
bool query_list(LIST *list, void* number)
{
    if(list != NULL && list->head != NULL)
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        node = list->head;
        while(node != NULL)
        {
            if(node->number == number)
            {
                return true;
            }
            node = node->next;
        }

    }
    return false;
}
bool remove_node(LIST *list, void* number)
{
    if(list != NULL && list->head != NULL && query_list(list, number) == true)
    {
        int i=1;
        NODE* node = (NODE*)malloc(sizeof(NODE));
        NODE* node_prev = (NODE*)malloc(sizeof(NODE));
        node = list->head;
        node_prev = NULL;
        while(node != NULL)
        {
            if(node->number == number && i==1)
            {
                list->head = node->next;
                free(node);
                return true;
            }else if(node->number == number)
            {
                node_prev->next = node->next;
                free(node);
                return true;
            }
            i++;
            node_prev = node;
            node = node->next;
        }
    }
    return false;
}
void* get_first(LIST *list)
{
    if(list != NULL && list->head != NULL)
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        node = list->head;
        return node->number;
    }
    return NULL;
}
void* get_next(LIST *list)
{
    if(list != NULL && list->head != NULL)
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        node = list->head;
        if(node->next!=NULL)
        {
            return node->next;
        }
    }
    return NULL;
}
int get_size_list(LIST *list)
{
    if(list!=NULL)
    {
        int i=0;
        NODE* node = (NODE*)malloc(sizeof(NODE));
        node = list->head;
        while(node != NULL)
        {
            node = node->next;
            i++;
        }
        return i;
    }
    return -1;
}
void print_list(LIST* list)
{
    if(list!=NULL)
    {
        if(get_size_list(list) > 0)
        {
            NODE* node = (NODE*)malloc(sizeof(NODE));
            node = list->head;
            while(node != NULL)
            {
                printf("%d\t",(int*)node->number);
                node = node->next;
            }
        }else{
            printf("\nLista vazia");
        }
    }
    printf("\n\nLista nao existe!!!");
}

LIST* unity(LIST *listA, LIST *listB)
{
    if(listA !=NULL && listB !=NULL && listA->head != NULL && listB->head != NULL)
    {
        LIST* listC = (LIST*)malloc(sizeof(LIST));
        listC = create_list();

        int xa, xb;
        int x=0, flag =0;
        NODE *n, *aux, *auxA, *auxB;

        n = (NODE*)malloc(sizeof(NODE));

        if(listC != NULL )
        {
            auxA = listA->head;
            while(auxA != NULL)
            {
                xa = (int)auxA->number;
                auxB = listB->head;
                while(auxB!= NULL)
                {
                    xb = (int)auxB->number;
                    if(xa == xb)
                    {
                        flag = 1;
                        break;
                    }
                    auxB = auxB->next;

                }
                if(flag != 1)
                    {
                        insert_head(listC, auxA->number);
                    }
                auxA = auxA->next;
                flag=0;
            }
            if(xa != xb)
            {
                insert_head(listC, auxA->number);
            }
            return listC;
        }
    }
    return NULL;
}
LIST* intersection(LIST *listA, LIST *listB)
{
    if(listA !=NULL && listB !=NULL && listA->head != NULL && listB->head != NULL)
    {
        LIST* listC = (LIST*)malloc(sizeof(LIST));
        listC = create_list();

        int xa, xb;
        int x=0, flag =0;
        NODE *n, *aux, *auxA, *auxB;

        n = (NODE*)malloc(sizeof(NODE));

        if(listC != NULL )
        {
            auxA = listA->head;
            while(auxA != NULL)
            {
                xa = (int)auxA->number;
                auxB = listB->head;
                while(auxB!= NULL)
                {
                    xb = (int)auxB->number;
                    if(xa == xb)
                    {
                        insert_head(listC, auxA->number);
                        break;
                    }
                    auxB = auxB->next;

                }
                auxA = auxA->next;
                flag=0;
            }
            if(xa == xb)
            {
                insert_head(listC, auxA->number);
            }
            return listC;
        }
    }
    return NULL;
}
LIST* difference(LIST *listA, LIST *listB)
{
    if(listA !=NULL && listB !=NULL && listA->head != NULL && listB->head != NULL)
    {
        LIST* listC = (LIST*)malloc(sizeof(LIST));
        listC = create_list();

        int xa, xb;
        int x=0, flag =0;
        NODE *n, *aux, *auxA, *auxB;

        n = (NODE*)malloc(sizeof(NODE));

        if(listC != NULL )
        {
            auxA = listA->head;
            while(auxA != NULL)
            {
                xa = (int)auxA->number;
                auxB = listB->head;
                while(auxB!= NULL)
                {
                    xb = (int)auxB->number;
                    if(xa == xb)
                    {
                        flag = 1;
                    }
                    auxB = auxB->next;
                }
                if(flag != 1)
                {
                    insert_head(listC, auxA->number);
                }
                auxA = auxA->next;
                flag=0;
            }
            return listC;
        }
    }
    return NULL;
}
LIST* complement(LIST *listA, LIST *listB)
{
    if(listA !=NULL && listB !=NULL && listA->head != NULL && listB->head != NULL)
    {
        LIST* listC = (LIST*)malloc(sizeof(LIST));
        listC = create_list();

        int xa, xb;
        int x=0, flag =0;
        NODE *n, *aux, *auxA, *auxB;

        n = (NODE*)malloc(sizeof(NODE));

        if(listC != NULL )
        {
            auxA = listB->head;
            while(auxA != NULL)
            {
                xa = (int)auxA->number;
                auxB = listA->head;
                while(auxB!= NULL)
                {
                    xb = (int)auxB->number;
                    if(xa == xb)
                    {
                        flag = 1;
                    }
                    auxB = auxB->next;
                }
                if(flag != 1)
                {
                    insert_head(listC, auxA->number);
                }
                auxA = auxA->next;
                flag=0;
            }
            return listC;
        }
    }
    return NULL;
}
bool contained (LIST *listA, LIST *listB)
{
    if(listA !=NULL && listB !=NULL && listA->head != NULL && listB->head != NULL)
    {
        LIST* listC = (LIST*)malloc(sizeof(LIST));
        listC = create_list();

        int cont=0;
        NODE *auxA;

        auxA = (NODE*)malloc(sizeof(NODE));

        if(listC != NULL )
        {
            auxA = listA->head;
            while(auxA != NULL)
            {
                if(query_list(listB, auxA->number)==true)
                {
                    cont++;
                }
                auxA = auxA->next;
            }
            if(get_size_list(listA)==cont)
            {
                return true;
            }
        }
    }
    return false;
}

void menu()
{
    printf("===== OPCOES =====\n");
    printf("(1) - A U B\n");
    printf("(2) - A n B\n");
    printf("(3) - A - B\n");
    printf("(4) - A \ B\n");
    printf("(5) - A C B\n");
    printf("(6) - Limpar todos os dados da memoria\n");
    printf("==================\n");
}
