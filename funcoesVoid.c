#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoesInt.h"
#include "funcoesVoid.h"
#include "funcoesChar.h"
#include "funcaoResolver.h"
#include "funcaoPrincipal.h"

//imprime a matriz
void imprime (char **matChar, int **matCabecalho, int **matLinha2, int linhas, int colunas, int maiorArgL, int maiorArgC){
	printf("\n");
	
	for (int i = 0; i < maiorArgC; i++){
		for (int j = 0; j < (maiorArgL + colunas + 1); j++){
			if(matCabecalho[i][j] == 0){
				printf("%-3c", ' ');
			}	
			else{		
				printf("%-3d", matCabecalho[i][j]);
			}
		}
		printf("\n");
	}
	
	for (int i = 0; i < (maiorArgL + colunas + 1); i++){
		if (i <= maiorArgL){
			printf("%-3c", ' ');
		}
		else{
			printf("%-3c", (65 + (i - (maiorArgL + 1))));
		}
	}
	printf("\n");
	
	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < (maiorArgL + colunas + 1); j++){
			if (j < maiorArgL){
				if (matLinha2[i][j] == 0){
					printf("%-3c", ' ');
				}
				else{
					printf("%-3d", matLinha2[i][j]);
				}
			}
			else if (j == maiorArgL){
				printf("%-3c", (65 + i));
			}
			else{
				printf("%-3c", matChar[i][j - (maiorArgL + 1)]);
			}
		}
		printf("\n");
	}
	printf("\n");	
}

//preenche a matriz no local selecionado
void preencher (char*** mat, int nLinha, int nColuna, char charL, char charC, int** matLinha2, int** matCabecalho, char** matChar, int maiorArgL, int maiorArgC){
	charL -= 97;
	charC -= 97;
	for (int i = 0; i < nLinha; i++){
		for (int j = 0; j < nColuna; j++){
			if (i == charL && j == charC){
				(*mat)[i][j] = 'X';
				imprime (matChar, matCabecalho, matLinha2, nLinha, nColuna, maiorArgL, maiorArgC);
				break;
			}
		}
	}
}

//preenche a matriz no local selecionado
void marcar (char*** mat, int nLinha, int nColuna, char charL, char charC, int** matLinha2, int** matCabecalho, char** matChar, int maiorArgL, int maiorArgC){
	charL -= 97;
	charC -= 97;
	
	for (int i =0; i < nLinha; i++){
		for (int j = 0; j < nColuna; j++){
			if (i == charL && j == charC){
				(*mat)[i][j] = '-';
				imprime (matChar, matCabecalho, matLinha2, nLinha, nColuna, maiorArgL, maiorArgC);				
				break;
			}
		}
	}
	printf("\n");
}

//preenche a matriz no local selecionado
void limpar (char*** mat, int nLinha, int nColuna, char charL, char charC, int** matLinha2, int** matCabecalho, char** matChar, int maiorArgL, int maiorArgC){
	charL -= 97;
	charC -= 97;
	
	for (int i =0; i < nLinha; i++){
		for (int j = 0; j < nColuna; j++){
			if (i == charL && j == charC){
				(*mat)[i][j] = '.';
				imprime (matChar, matCabecalho, matLinha2, nLinha, nColuna, maiorArgL, maiorArgC);				
				break;
			}
		}
	}
	printf("\n");
}

//salva o nonograma
void salvar (int linhas, int colunas, int* argsLinha, int* argsColuna, int** matLinha, int** matColuna, char** matChar, char* doc){
	FILE* destino = fopen (doc, "w");
	
	fprintf(destino, "%d %d", linhas, colunas);
	fprintf(destino, "\n\n");
	
	for (int i = 0; i < linhas; i++){
		fprintf(destino, "%-2d", argsLinha[i]);
		for (int j = 0; j < argsLinha[i]; j++){
			fprintf(destino, "%-2d", matLinha[i][j]);
		}
		fprintf(destino, "\n");
	}
	
	fprintf(destino, "\n");
	
	for (int i = 0; i < colunas; i++){
		fprintf(destino, "%-2d", argsColuna[i]);
		for (int j = 0; j < argsColuna[i]; j++){
			fprintf(destino, "%-2d", matColuna[i][j]);
		}
		fprintf(destino, "\n");
	}
		
	for (int i = 0; i < linhas; i++){
		fprintf(destino, "\n");
		for (int j = 0; j < colunas; j++){
			fprintf(destino, "%-2c", matChar[i][j]);
		}
	}
	
	fclose (destino);
	
	printf("Arquivo salvo com sucesso!!\n");
	getchar();
}

//copia uma matriz em outra
void copiaMat (char*** matChar, char** matChar2, int linhas, int colunas){

	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			(*matChar)[i][j] = matChar2[i][j];
		}
	}
	
}
