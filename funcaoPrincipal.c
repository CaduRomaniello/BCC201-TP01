#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoesInt.h"
#include "funcoesVoid.h"
#include "funcoesChar.h"
#include "funcaoResolver.h"
#include "funcaoPrincipal.h"
#define TAM 100

void principal (char* arquivo)
{
	//declarando variaveis
	int linhas, colunas;
	int maiorArgL = 0, maiorArgC = 0;
	int **matLinha, **matColuna;
	int **matLinha2, **matColuna2;
	int *argsLinha, *argsColuna;
	int auxMaiorArgL, auxMaiorArgC;
	int **matCabecalho;
	int verificadorString, selecionador;
	int verificadorCaso = 0, verificadorResolucao;
	char **matChar, caracterTeste;
	char **matChar2;
	char comando[TAM], nomeDoc[TAM]; 
	char charL, charC;
	
	FILE* argv = fopen (arquivo, "r");
	
	//lendo o numero de linhas e colunas
	fscanf (argv, "%d %d", &linhas, &colunas);
	
	if (linhas > 26 || colunas > 26){
		printf("Tamanho de nonograma nao suportado.\nReinicie o programa com um nonograma com numeros de linhas e colunas menores ou iguais a 26!!\n");
		exit(0);
	}

	//alocando o vetor de argumentos de cada linha por alocacao dinamica
	argsLinha = malloc (linhas * sizeof(int));
	
	//alocando o vetor de argumentos de cada coluna por alocacao dinamica
	argsColuna = malloc (colunas * sizeof(int));
	
	//estabelecendo uma matriz por alocacao dinamica e armazenando os valores correspondentes de cada linha
	matLinha = malloc (linhas * sizeof(int*));
	for (int i = 0; i < linhas; i++){
		fscanf (argv, "%d", &argsLinha[i]);
		matLinha[i] = malloc (argsLinha[i] * sizeof(int));
		for (int j = 0; j < argsLinha[i]; j++){
			fscanf (argv, "%d", &matLinha[i][j]);
		}	
		if (argsLinha[i] > maiorArgL){
			maiorArgL = argsLinha[i];
		}	
	}
	
	//estabelecendo uma matriz por alocacao dinamica e armazenando os valores correspondentes de cada coluna
	matColuna = malloc (colunas * sizeof(int*));
	for (int i = 0; i < colunas; i++){
		fscanf (argv, "%d", &argsColuna[i]);
		matColuna[i] = malloc (argsColuna[i] * sizeof(int));		
		for (int j = 0; j < argsColuna[i]; j++){
			fscanf (argv, "%d", &matColuna[i][j]);
		}		
		if (argsColuna[i] > maiorArgC){
			maiorArgC = argsColuna[i];
		}
	}
	
	//alocando a matriz de char
	matChar = malloc (linhas * sizeof(char*));
	for (int i = 0; i < linhas; i++){
		matChar[i] = malloc (colunas * sizeof(char));
	}
	
	//lendo a matriz de char do arquivo
	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			fscanf (argv, "%c", &caracterTeste);
			while (caracterTeste == ' ' || caracterTeste == '\n' || caracterTeste == '\r'){
				fscanf (argv, "%c", &caracterTeste);
			}
			matChar[i][j] = caracterTeste;
		}
	}
	
	fclose(argv);
	
	FILE* arqv = fopen (arquivo, "r");
	
	fscanf (arqv, "%d %d", &linhas, &colunas);
	
	//estabelecendo uma matriz quadrada para os argumentos de cada linha ocupando os espacos em branco com 0
	matLinha2 = malloc (linhas * sizeof(int*));
	for (int i = 0; i < linhas; i++){
		fscanf (arqv, "%d", &argsLinha[i]);
		matLinha2[i] = malloc (maiorArgL * sizeof(int));	
		auxMaiorArgL = maiorArgL;	
		for (int j = 0; j < maiorArgL; j++){
			if (auxMaiorArgL > argsLinha[i]){
				matLinha2[i][j] = 0;
				auxMaiorArgL--;
			}
			else{
				fscanf (arqv, "%d", &matLinha2[i][j]);
			}
		}
	}
	
	//estabelecendo uma matriz quadrada para os argumentos de cada coluna ocupando os espacos em branco com 0
	matColuna2 = malloc (colunas * sizeof(int*));
	for (int i = 0; i < colunas; i++){
		fscanf (arqv, "%d", &argsColuna[i]);
		matColuna2[i] = malloc (maiorArgC * sizeof(int));	
		auxMaiorArgC = maiorArgC;	
		for (int j = 0; j < maiorArgC; j++){
			if (auxMaiorArgC > argsColuna[i]){
				matColuna2[i][j] = 0;
				auxMaiorArgC--;
			}
			else{
				fscanf (arqv, "%d", &matColuna2[i][j]);
			}
		}
	}
	
	//alocando a matriz de char2
	matChar2 = malloc (linhas * sizeof(char*));
	for (int i = 0; i < linhas; i++){
		matChar2[i] = malloc (colunas * sizeof(char));
	}
	
	//lendo a matriz de char do arquivo
	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			fscanf (argv, "%c", &caracterTeste);
			while (caracterTeste == ' ' || caracterTeste == '\n' || caracterTeste == '\r'){
				fscanf (argv, "%c", &caracterTeste);
			}
			matChar2[i][j] = caracterTeste;
		}
	}
	
	//formando a matriz do cabecalho
	matCabecalho = malloc (maiorArgC * sizeof(int*));
	for (int i = 0; i < maiorArgC; i++){
		matCabecalho[i] = malloc ((maiorArgL + colunas + 1) * sizeof(int));
		for (int j = 0; j < (maiorArgL + colunas + 1); j++){
			if (j <= maiorArgL){
				matCabecalho[i][j] = 0;
			}
			else{
				matCabecalho[i][j] = matColuna2[j-maiorArgL-1][i];
			}
		}
	}
	
	//inicio do programa
	printf("Bem-vindo ao nonograma!!!\n\n");
	printf("Comandos:\n");
	printf("========================================================================\n");
	printf("[x]        -> preenche uma celula com o caracter 'x'                   |\n");
	printf("[-]        -> preenche uma celula com o caracter '-'                   |\n");
	printf("[.]        -> limpa uma celula preenchendo-a com o caracter '.'        |\n");
	printf("[resolver] -> Resolve o nonograma                                      |\n");
	printf("[salvar]   -> salva o nonograma tal como esta no momento em um arquivo |\n");
	printf("[sair]     -> encerra o programa (sem salvar as ultimas alteracoes)    |\n");
	printf("========================================================================\n");
	
	//printando a matriz pro usuario
	imprime (matChar, matCabecalho, matLinha2, linhas, colunas, maiorArgL, maiorArgC);
	
	//pedindo para o usuario digitar um comando e executando o mesmo
	do{
		do{
			if (verificadorString == 1 && (strlen(comando) == 1)){
				getchar();
				getchar();
			}
			
			printf("Digite um comando: ");
			scanf ("%s", comando);
			
			verificadorString = verificaString (comando);
			
			selecionador = indicadorComando (comando);
			
			if (selecionador <= 3 && selecionador >= 1){
				verificadorCaso = verificaCaso (selecionador, &charL, &charC, linhas, colunas);
				
				if (verificadorString != 0 || verificadorCaso != 0){
					printf("Comando invalido!!!\n");
				}
				
			}
		
			if (verificadorString != 0){
				printf("Comando invalido!!!\n");
				getchar();
			}
			
		}while (verificadorString != 0 && verificadorCaso != 0);
		
		switch (selecionador){
			case 1:
				preencher (&matChar, linhas, colunas, charL, charC, matLinha2, matCabecalho, matChar, maiorArgL, maiorArgC);
				getchar();
				break;
			case 2:
				marcar (&matChar, linhas, colunas, charL, charC, matLinha2, matCabecalho, matChar, maiorArgL, maiorArgC);
				getchar();
				break;
			case 3:
				limpar (&matChar, linhas, colunas, charL, charC, matLinha2, matCabecalho, matChar, maiorArgL, maiorArgC);
				getchar();
				break;
			case 4:
				resolver(&matChar2, linhas, colunas, argsLinha, argsColuna, matLinha, matColuna);
				copiaMat (&matChar, matChar2, linhas, colunas); 
				imprime (matChar, matCabecalho, matLinha2, linhas, colunas, maiorArgL, maiorArgC);
				break;
			case 5:
				scanf("%s", nomeDoc);
				salvar (linhas, colunas, argsLinha, argsColuna, matLinha, matColuna, matChar, nomeDoc);
				break;
			case 6:
				free(argsLinha);
				free(argsColuna);
				
				for (int i = 0; i < linhas; i++){
					if (argsLinha[i] != 0){
						free(matLinha[i]);
					}
				}
				free(matLinha);
				
				for (int i = 0; i < colunas; i++){
					if (argsColuna[i] != 0){
						free(matColuna[i]);
					}
				}
				free(matColuna);
				
				for (int i = 0; i < linhas; i++){
					free(matChar[i]);
				}
				free(matChar);
				
				for (int i = 0; i < linhas; i++){
					if (argsLinha[i] != 0){
						free(matLinha2[i]);
					}
				}
				free(matLinha2);
				
				for (int i = 0; i < maiorArgC; i++){
					if (argsColuna[i] != 0){
						free(matColuna2[i]);
					}
				}
				free(matCabecalho);
				
				exit (0);
				break;
		}
		
		verificadorResolucao = verificaResolucao(matLinha, matColuna, matChar, argsLinha, argsColuna, linhas, colunas);
		
	}while (verificadorResolucao != 0);
	
	
	
	
	
	
	
	//liberando as memorias aocadas dinamicamente
	free(argsLinha);
	free(argsColuna);
	
	for (int i = 0; i < linhas; i++){
		if (argsLinha[i] != 0){
			free(matLinha[i]);
		}
	}
	free(matLinha);
	
	for (int i = 0; i < colunas; i++){
		if (argsColuna[i] != 0){
			free(matColuna[i]);
		}
	}
	free(matColuna);
	
	for (int i = 0; i < linhas; i++){
		free(matChar[i]);
	}
	free(matChar);
	
	for (int i = 0; i < linhas; i++){
		if (argsLinha[i] != 0){
			free(matLinha2[i]);
		}
	}
	free(matLinha2);
	
	for (int i = 0; i < colunas; i++){
		if (argsColuna[i] != 0){
			free(matColuna2[i]);
		}
	}
	free(matColuna2);
	
	for (int i = 0; i < maiorArgC; i++){
		free(matCabecalho[i]);
	}
	free(matCabecalho);
	
}
