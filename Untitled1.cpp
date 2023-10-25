#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *proximo;
};

struct  no *cabeca = NULL;

//funcao que insere no na fila

void inserir(int numero) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
}

//funcao remove no da fila

int remover() {
	int retorno = -1;
	if (cabeca != NULL) {
		if (cabeca -> proximo == NULL) {
			//fila tem  1  bo
			retorno = cabeca -> numero;
			free(cabeca);
			cabeca = NULL;
		}else {
			//fila tem mais de um no
			struct no *ponteiroAnterior = cabeca;
			//procura o penultimo no  da fila
			while (ponteiroAnterior -> proximo -> proximo != NULL) {
				ponteiroAnterior = ponteiroAnterior -> proximo;
			}
			//remocao do ultimo no da fila
			retorno = ponteiroAnterior -> proximo -> numero;
			free(ponteiroAnterior -> proximo);
			ponteiroAnterior -> proximo = NULL; 
			
		}
	}
	return retorno;
}

void imprimir() {
	struct no *ponteiro = cabeca;
	printf("=========FILA=========");
	printf("\n");
	while (ponteiro != NULL) {
		printf("%d\t", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
	printf("\n");
}

int main() {
	int opcao = 0;
	int numero = 0;
	
	while (opcao != 4) {
		printf("+=================+\n");
		printf("+==Menu de Opcoes=+\n");
		printf("+=================+\n");
		printf("+=  1 - Inserir  =+\n");
		printf("+=  2 - Remover  =+\n");
		printf("+=  3 - Imprimir =+\n");
		printf("+=  4 - Sair     =+\n");
		printf("+=================+\n");
		printf("Digite a opcao: ");
		scanf("%d", &opcao);

	
	switch(opcao) {
		case 1:
			printf("Digite um numero: ");
			scanf("%d", &numero);
			inserir(numero);
			break;
		case 2:
			printf("Removi o numero %d da fila\n", remover());
			break;
		case 3:
			imprimir();
			break;
	}
}
}
