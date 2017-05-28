#ifdef LISTA_H
#endif // LISTA_H
typedef struct No {
	void* valor;
	struct No* proximo;
	struct No* anterior;
}No;

typedef struct Lista {
	No* primeiro;
	No* ultimo;
	No* atual;
}Lista;

Lista* criarLista(void);
int destruirLista(Lista*);
int inserirNoComeco(Lista*, void*);
int inserirNoFim(Lista*, void*);
void* removerNoComeco(Lista*);
void* removerNoFim(Lista*);
void* removerX(Lista*, void*, int(*cmp)(void*, void*));
int substituirX(Lista*, void*, void*, int(*cmp)(void*, void*));
int inserirDepoisDeX(Lista*, void*, void*, int(*cmp)(void*, void*));
int inserirAntesDeX(Lista*, void*, void*, int(*cmp)(void*, void*));
int isEmpty(Lista*);
int inserirDepoisDeN(Lista*, void*, int);
void* removerN(Lista*, int);
void* getPrimeiro(Lista*);
void* getProximo(Lista*);
int contarNos(Lista*);
int consultar(Lista*, void*);

int cmp(void*, void*);


