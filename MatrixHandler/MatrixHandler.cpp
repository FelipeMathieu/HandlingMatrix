// MatrixHandler.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int **inicializarMatriz(int ordem)
{
	int i, j;
	int **matriz = (int **)malloc(sizeof(int *) * ordem);
	for(i = 0; i < ordem; i++)
		matriz[i] = (int *)malloc(sizeof(int) * ordem);

	for (i = 0; i < ordem; i++)
		for (j = 0; j < ordem; j++)
		{
			printf("Informe o valor da matriz na posicao (%d,%d): ", i + 1, j + 1);
#pragma warning(suppress : 4996)
			scanf("%d", &matriz[i][j]);
			printf("\n");
		}
	return matriz;
}

void desenharMatriz(int **matriz, int ordem)
{
	printf("Matriz resultado:\n");
	int i, j;
	for(i = 0; i < ordem; i++)
	{
		for (j = 0; j < ordem; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}	
}

bool matrizIdentidade(int **matriz, int ordem)
{
	int i, j;
	for (i = 0; i < ordem; i++)
		for (j = 0; j < ordem; j++)
			if ((i == j && matriz[i][j] != 1) || (i != j && matriz[i][j] != 0))
				return false;
		
	return true;
}

bool matrizZero(int **matriz, int ordem)
{
	int i, j;
	for (i = 0; i < ordem; i++)
		for (j = 0; j < ordem; j++)
			if (matriz[i][j] != 0)
				return false;
	return true;
}

void verificarMatrizResultado(int **matriz, int ordem)
{
	if (matrizIdentidade(matriz, ordem))
		printf("Matriz e identidade!\n\n");
	else if(matrizZero(matriz, ordem))
		printf("Matriz e zero!\n\n");
	else
		printf("Matriz nao e nenhuma das opcoes!\n\n");
}

int main()
{
	int ordem;
	printf("Informe a ordem da matriz:\n");
#pragma warning(suppress : 4996)
	scanf("%d", &ordem);
	if (ordem <= 0)
	{
		printf("A ordem da matrix deve ser maior que 0!\n\n");
		return 0;
	}

	int **matriz = inicializarMatriz(ordem);
	desenharMatriz(matriz, ordem);
	verificarMatrizResultado(matriz, ordem);

	return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
