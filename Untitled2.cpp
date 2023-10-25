#include <stdio.h>
#include <stdlib.h>

//declaração de estrutura de no

struct no{
	int numero;
	struct no *proximo;
};

//declaração de variaveis

struct no *cabeca = NULL;

//funcao que ensere na pilha

void push(int numero) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
}

//funcao que romove um no da pilha

int pop() {
	int retorno = -1;
	
	if (cabeca != NULL) {
		retorno = cabeca -> numero;
		struct no *ponteiro = cabeca;
		cabeca = cabeca -> proximo;
		free(ponteiro);
	}
	return retorno;
}

int main() {
	int opcao = 0;
	int numero = 0;
	
	while (opcao != 3) {
		printf("+=================+\n");
		printf("+==Menu de Opcoes=+\n");
		printf("+=================+\n");
		printf("+=  1 - Inserir  =+\n");
		printf("+=  2 - Remover  =+\n");
		printf("+=  3 - Sair     =+\n");
		printf("+=================+\n");
		printf("Digite a opcao: ");
		scanf("%d", &opcao);

	
	switch(opcao) {
		case 1:
			printf("Digite um numero: ");
			scanf("%d", &numero);
			push(numero);
			break;
		case 2:
			printf("Removi o numero %d da fila\n", pop());
			break;
	
	}
}
}
