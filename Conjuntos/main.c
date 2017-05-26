#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

Lista* uniao(Lista*, Lista*);
Lista* intersecao(Lista*, Lista*);
Lista* diferenca(Lista*, Lista*);
Lista* complemento(Lista*, Lista*);
int contido(Lista*, Lista*);

int imprimir(Lista*);

int main(void) {
	Lista* listaA = criarLista();
	Lista* listaB = criarLista();
	Lista* listaC = NULL;

	int* valor;
    int opcao = 1;

    printf("Lista A\n");

    do {
        system("cls");
        printf("\n======Conjunto A======\n");
        valor = (int*)malloc(sizeof(int));

        printf("Entre com o valor: ");
        scanf("%d", valor);

        inserirNoFim(listaA, (void*)valor);

        printf("Continuar? 1 / 0: ");
        scanf("%d", &opcao);
    } while(opcao != 0);

    printf("Lista B\n");

	do {
        system("cls");
        printf("\n======Conjunto B======\n");
        valor = (int*)malloc(sizeof(int));

        printf("Entre com o valor: ");
        scanf("%d", valor);

        inserirNoFim(listaB, (void*)valor);

        printf("Continuar? 1 / 0: ");
        scanf("%d", &opcao);
    } while(opcao != 0);

    system("cls");
    printf("\n==================\n");
    printf("A: ");
    imprimir(listaA);
    printf("\n\n");

    printf("B: ");
    imprimir(listaB);
    printf("\n");

    printf("\n====OPERACOES=====\n");

    printf("A U B: ");
    listaC = uniao(listaA, listaB);
    imprimir(listaC);
    printf("\n");

	printf("A n B: ");
    listaC = intersecao(listaA, listaB);
    imprimir(listaC);
    printf("\n");

    printf("A - B: ");
    listaC = diferenca(listaA, listaB);
    imprimir(listaC);
    printf("\n");

    printf("A / B: ");
    listaC = complemento(listaA, listaB);
    imprimir(listaC);
    printf("\n");

    if(contido(listaA, listaB)==1)
    {
        printf("A C B: TRUE", );
    }else
    {
        printf("A C B: FALSE", );
    }


    printf("\n==============\n");

    destruirLista(listaA);
    destruirLista(listaB);
    destruirLista(listaC);

	return 0;
}


int imprimir(Lista* lista) {
	if(lista != NULL) {
		if(!isEmpty(lista)) {
			void* valor = getPrimeiro(lista);

			while(valor != NULL) {
				printf("%d ", *((int*)valor));

				valor = getProximo(lista);
			}

            return 1;
		}
	}

	printf("Conjnto vazio");
}

Lista* uniao(Lista* listaA, Lista* listaB) {
	if(listaA != NULL && listaB != NULL) {
		if(!isEmpty(listaA) && !isEmpty(listaB)) {
			Lista* listaC = criarLista();
			int encontrado = 0;


			void* tmp = NULL;

			tmp = getPrimeiro(listaA);

			while(tmp != NULL) {
				encontrado = consultar(listaC, tmp);

				if(encontrado == 0) {
					inserirNoFim(listaC, tmp);
				}

				tmp = getProximo(listaA);
			}

			tmp = getPrimeiro(listaB);

			while(tmp != NULL) {
				encontrado = consultar(listaC, tmp);

				if(encontrado == 0) {
					inserirNoFim(listaC, tmp);
				}

				tmp = getProximo(listaB);
			}

			return listaC;
		}
	}

	return NULL;
}

Lista* intersecao(Lista* listaA, Lista* listaB) {
	if(listaA != NULL && listaB != NULL) {
		if(!isEmpty(listaA) && !isEmpty(listaB)) {
			Lista* listaC = criarLista();

			void* tmp = getPrimeiro(listaA);

			while(tmp != NULL) {
				if(consultar(listaB, tmp) == 1 && consultar(listaC, tmp) == 0) {
					inserirNoFim(listaC, tmp);
				}

				tmp = getProximo(listaA);
			}

			return listaC;
		}
	}
	return NULL;
}

Lista* diferenca(Lista* listaA, Lista* listaB) {
	if(listaA != NULL && listaB != NULL) {
		if(!isEmpty(listaA) && !isEmpty(listaB)) {
			Lista* listaC = criarLista();

			void* tmp = getPrimeiro(listaA);

			while(tmp != NULL) {
				if(consultar(listaB, tmp) == 0 && consultar(listaC, tmp) == 0) {
					inserirNoFim(listaC, tmp);
				}

				tmp = getProximo(listaA);
			}

			return listaC;
		}
	}
	return NULL;
}

Lista* complemento(Lista* listaA, Lista* listaB) {
	if(listaA != NULL && listaB != NULL) {
		if(!isEmpty(listaA) && !isEmpty(listaB)) {
			Lista* listaC = criarLista();

			void* tmp = getPrimeiro(listaB);

			while(tmp != NULL) {
				if(consultar(listaA, tmp) == 0 && consultar(listaC, tmp) == 0) {
					inserirNoFim(listaC, tmp);
				}

				tmp = getProximo(listaB);
			}

			return listaC;
		}
	}
	return NULL;
}

int contido(Lista* listaA, Lista* listaB) {
    if(listaA != NULL && listaB != NULL) {
            if(!isEmpty(listaA) && !isEmpty(listaB)) {
                    void* tmp = getPrimeiro(listaA);

                    while(tmp != NULL) {
                        if(consultar(listaB, tmp) == 0) {
                            return 0;
                        }

                        tmp = getProximo(listaA);
                    }
                    return 1;
            }
    }
	return 0;
}
