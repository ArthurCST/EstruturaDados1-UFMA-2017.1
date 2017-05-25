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

void main()
{

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
                printf("%d  ",(int*)node->number);
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
    if(listA !=NULL && listB !=NULL)
    {
        LIST* listC = (LIST*)malloc(sizeof(LIST));
        listC = create_list();

        //insert_head(listC, number);


    }
}
LIST* intersection(LIST *listA, LIST *listB)
{

}
LIST* difference(LIST *listA, LIST *listB)
{

}
LIST* complement(LIST *listA, LIST *listB)
{

}
