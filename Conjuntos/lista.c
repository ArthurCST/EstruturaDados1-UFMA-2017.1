
#include <stdlib.h>

#include "lista.h"


Lista* criarLista(void) {
	Lista* lista = NULL;

	lista = (Lista*)malloc(sizeof(Lista));

	if(lista != NULL) {
		lista->primeiro = NULL;
		lista->ultimo = NULL;

		return lista;
	}
	return NULL;
}

int destruirLista(Lista* lista) {
	if(lista != NULL) {
		free(lista);

		return 1;
	}
	return 0;
}

int inserirNoComeco(Lista* lista, void* valor) {
	if(lista != NULL) {
		No* no = NULL;

		no = (No*)malloc(sizeof(No));

		if(no != NULL) {
			no->valor = valor;
			no->proximo = lista->primeiro;

			if(lista->primeiro == NULL) {
				lista->ultimo = no;
			}

			lista->primeiro = no;

			return 1;
		}
	}
	return 0;
}

int inserirNoFim(Lista* lista, void* valor) {
	if(lista != NULL) {
		No* no = NULL;

		no = (No*)malloc(sizeof(No));

		if(no != NULL) {
			no->valor = valor;
			no->proximo = NULL;

			if(lista->primeiro == NULL) {
				lista->primeiro = no;
				lista->ultimo = no;
			} else {
				No* tmp = NULL;

				tmp = lista->ultimo;
				tmp->proximo = no;
				lista->ultimo = no;
			}
			return 1;
		}
	}
	return 0;
}

void* removerNoComeco(Lista* lista) {
	if(lista != NULL) {
		if(lista->primeiro != NULL) {
			void* valor = lista->primeiro->valor;

			No* primeiro = lista->primeiro;
			lista->primeiro = primeiro->proximo;

			if(primeiro == lista->ultimo) {
				lista->ultimo = NULL;
			}

			free(primeiro);
			return valor;

		}
	}
	return NULL;
}

void* removerNoFim(Lista* lista) {
	if(lista != NULL) {
		if(lista->primeiro != NULL) {
			No* anterior = NULL;
			No* aux = lista->primeiro;

			while(aux->proximo != NULL) {
				anterior = aux;
				aux = aux->proximo;
			}

			void* valor = aux->valor;

			if(anterior != NULL) {
				anterior->proximo = aux->proximo;
			} else {
				lista->primeiro = aux->proximo;
			}

			free(aux);

			return valor;
		}
	}
	return NULL;
}

int cmp(void* a, void* b) {
	int* pA = a;
	int* pB = b;

	if(*pA == *pB) {
		return 1;
	} else {
		return 0;
	}
}

void* removerX(Lista* lista, void* chave, int(*cmp)(void*, void*)) {
	if(lista != NULL) {
		if(!isEmpty(lista)) {
			No* anterior = NULL;
			No* aux = lista->primeiro;

			int encontrada = cmp(chave, aux->valor);

			while(aux->proximo != NULL && encontrada != 1) {
				anterior = aux;
				aux = aux->proximo;
				encontrada = cmp(chave, aux->valor);
			}

			if(encontrada == 1) {
				void* valor = aux->valor;

				if(anterior != NULL) {
					anterior->proximo = aux->proximo;
				} else {
					lista->primeiro = aux->proximo;
				}

				free(aux);

				return valor;
			}
		}
	}
	return NULL;
}

int substituirX(Lista* lista, void* valor, void* chave, int(*cmp)(void*, void*)) {
	if(lista != NULL) {
		if(lista->primeiro != NULL) {
			No* aux = lista->primeiro;

			int encontrada = cmp(chave, aux->valor);

			while(aux->proximo != NULL && encontrada != 1) {
				aux = aux->proximo;
				encontrada = cmp(chave, aux->valor);

			}

			if(encontrada == 1) {
				aux->valor = valor;
				return 1;
			}
		}
	}
	return 0;
}

int inserirDepoisDeX(Lista* lista, void* valor, void* chave, int(*cmp)(void*, void*)) {
	if(lista != NULL) {
		if(lista->primeiro != NULL) {
			No* aux = lista->primeiro;

			int encontrada = cmp(chave, aux->valor);

			while(aux->proximo != NULL && encontrada != 1) {
				aux = aux->proximo;
				encontrada = cmp(chave, aux->valor);
			}

			if(encontrada == 1) {
				No* no = (No*)malloc(sizeof(No));

				no->valor = valor;

				if(aux->proximo == NULL) {
					no->proximo = NULL;
					lista->ultimo = no;
				} else {
					no->proximo = aux->proximo;
				}

				aux->proximo = no;

				return 1;
			}
		}
	}
	return 0;
}

int inserirAntesDeX(Lista* lista, void* valor, void* chave, int(*cmp)(void*, void*)) {
	if(lista != NULL) {
		if(lista->primeiro != NULL) {
			No* anterior = NULL;
			No* aux = lista->primeiro;

			int encontrado = cmp(chave, aux->valor);

			while(aux->proximo != NULL && encontrado != 1) {
				anterior = aux;
				aux = aux->proximo;

				encontrado = cmp(chave, aux->valor);
			}

			if(encontrado == 1) {
				No* no = (No*)malloc(sizeof(No));

				no->valor = valor;
				no->proximo = aux;

				if(anterior == NULL) {
					lista->primeiro = no;
				} else {
					anterior->proximo = no;
				}

				return 1;
			}
		}
	}
	return 0;
}

int isEmpty(Lista* lista) {
	return lista->primeiro == NULL;
}

int inserirDepoisDeN(Lista* lista, void* valor, int n) {
	if(n > 0) {
		if(lista != NULL) {
			No* no = (No*)malloc(sizeof(No));
			no->valor = valor;

			if(no != NULL) {
				if(n == 1) {
					no->proximo = lista->primeiro;
					lista->primeiro = no;
				} else {
					int i;
					No* tmp = lista->primeiro;

					for(i = 1; i <= n && tmp != NULL; i++) {
						tmp = tmp->proximo;
					}

					if(tmp != NULL && i <= n) {
						no->proximo = tmp->proximo;
						tmp->proximo = no;
					}
				}
				return 1;
			}
		}
	}
	return 0;
}

void* removerN(Lista* lista, int n) {
	if(n > 0) {
		if(!isEmpty(lista)) {
			No* anterior = NULL;
			No* aux = lista->primeiro;

			int i;

			for(i = 1; i < n && aux != NULL; i++) {
				anterior = aux;
				aux = aux->proximo;
			}

			if(i < n && aux != NULL) {
				void* valor = aux->valor;

				if(lista->primeiro == aux) {
					lista->primeiro = aux->proximo;

				} else {
					anterior->proximo = aux->proximo;

				}

				free(aux);

				return valor;
			}
		}
	}
}

void* getPrimeiro(Lista* lista) {
	if(lista != NULL) {
		if(!isEmpty(lista)) {
			lista->atual = lista->primeiro;

			return lista->atual->valor;
		}
	}
	return NULL;
}

void* getProximo(Lista* lista) {
	if(lista != NULL) {
		if(!isEmpty(lista)) {
			lista->atual = lista->atual->proximo;

			if(lista->atual != NULL) {
				return lista->atual->valor;
			}
		}
	}
	return NULL;
}

int contarNos(Lista* lista) {
	int num_nos = 0;

	if(lista != NULL) {
		if(!isEmpty(lista)) {
			void* valor = getPrimeiro(lista);

			while(valor != NULL) {
				num_nos++;

				valor = getProximo(lista);
			}
		}
	}
	return num_nos;
}

int consultar(Lista* lista, void* valor) {
	if(lista != NULL) {
		if(!isEmpty(lista)) {
			No* tmp = lista->primeiro;

			int encontrado = cmp(tmp->valor, valor);

			while(tmp->proximo != NULL && encontrado != 1) {
				tmp = tmp->proximo;

				encontrado = cmp(tmp->valor, valor);
			}

			if(encontrado == 1) {
				return 1;
			}
		}
	}
	return 0;
}
