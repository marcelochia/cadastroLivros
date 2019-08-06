#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define TAM 5

typedef struct {
	int		codigo;
	char	autor[100];
	char	titulo[50];
	char	editora[20];
} cadastro;

int i;
cadastro livro[TAM];

cadastro inserir(cadastro *livro) {
	printf("NOVO CADASTRO DE LIVRO\n\n");
	for(i=0; i<TAM; i++) {
		livro[i].codigo = i+1;
		printf("Código do livro: %d\n", livro[i].codigo);
		printf("Insira o(s) nome(s) do(s) autor(es): ");
		scanf("%[^\n]%*c", livro[i].autor);
		fflush(stdin);
		printf("Insira o título do livro: ");
		scanf("%[^\n]%*c", livro[i].titulo);
		fflush(stdin);
		printf("Insira o nome da editora: ");
		scanf("%[^\n]%*c", livro[i].editora);
		fflush(stdin);
		printf("\n");
	}
	return *livro;	
}

cadastro exibir(cadastro *livro) {
	if(livro[1].codigo == 0) {
		printf("Lista vazia!\n\n");
		system("pause");
	} else {
		printf("Livros cadastrados:\n\n");
			for(i=0; i<TAM; i++){
				printf("Código do livro: %d\n", livro[i].codigo);
				printf("\tAutor: %s\n", livro[i].autor);
				printf("\tTítulo: %s\n", livro[i].titulo);
				printf("\tEditora: %s\n\n", livro[i].editora);
			}
		fflush(stdin);
		system("pause");
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	unsigned int cp = 1252;
	unsigned int cpIn = GetConsoleCP();
	unsigned int cpOut = GetConsoleOutputCP();
	SetConsoleOutputCP(cp);
	SetConsoleCP(cp);

	int menu;
	
	printf("Biblioteca Plus - Sistemas de gerenciamento de bibliotecas (versão beta)\n\n");
	printf("MENU\n1 - Inserir um novo cadastro\n2 - Mostrar todos os itens cadastrados\n0 - Encerrar\n\nDigite a opção desejada: ");
	scanf("%d", &menu);
	switch(menu) {
		case 1: 
			fflush(stdin);
			system("cls");
			inserir(livro);
			system("cls");
			printf("\nSistema de cadastros lotado. Não é possível armazenar mais informações!\n\n");
			system("pause");
			system("cls");
			fflush(stdin);
			main();
		break;
		case 2:
			system("cls");
			exibir(livro);
			system("cls");
			main();
		break;
		case 0:
			exit(0);
			break;
		default:
			printf("Erro: opção inválida!\n\n");
			fflush(stdin);
			system("pause");
			system("cls");
			main();
		break;
	}
}
