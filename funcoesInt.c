#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoesInt.h"
#include "funcoesVoid.h"
#include "funcoesChar.h"
#include "funcaoResolver.h"
#include "funcaoPrincipal.h"

//implementando as funcoes
int verificaString (char* str){
	int tam;
	
	tam = strlen(str);
	
	for (int i = 0; i < tam; i++){
		str[i] = converteChar (str[i]);
	}
	
	if (strcmp (str, "x") == 0){
		return 0;
	}
	else if (strcmp (str, "-") == 0){
		return 0;
	}
	else if (strcmp (str, ".") == 0){
		return 0;
	}
	else if (strcmp (str, "resolver") == 0){
		return 0;
	}
	else if (strcmp (str, "salvar") == 0){
		return 0;
	}
	else if (strcmp (str, "sair") == 0){
		return 0;
	}
	else {
		return 1;
	}
}

//verifica a linha que o usuario digitou
int verificaLinha (char linha, int nLinha){
	char caracter;
	
	caracter = converteChar (linha);
	
	if ((caracter >= 97 && caracter <= 122) && ((caracter - 97) < nLinha)){
	    return 0;
	}
	
	return 1;
}

//verifica a coluna que o usuario digitou
int verificaColuna (char coluna, int nColuna){
    char caracter;
    
	caracter = converteChar (coluna);
	
	if ((caracter >= 97 && caracter <= 122) && ((caracter - 97) < nColuna)){
	    return 0;
	}
	
	return 1;
}

//verifica se o que foi digitado eh valido
int verificaCaso(int selecionador, char* charL, char* charC, int nLinha, int nColuna){
	int verificadorLinha, verificadorColuna;
	switch (selecionador){
			case 1:

			    *charL = lerLinha ();
			    *charL = converteChar (*charL);
			    *charC = lerColuna ();
			    *charC = converteChar (*charC);

				verificadorLinha = verificaLinha (*charL, nLinha);
					
				if (verificadorLinha != 0){
					return 1;
				}
	
				verificadorColuna = verificaColuna (*charC, nColuna);
				
				if (verificadorColuna != 0){
						return 1;
				}
	
				return 0;
				
				break;
			case 2:
				*charL = lerLinha ();
			    *charL = converteChar (*charL);
			    *charC = lerColuna ();
			    *charC = converteChar (*charC);
	
				verificadorLinha = verificaLinha (*charL, nLinha);
					
				if (verificadorLinha != 0){
					return 1;
				}
	
				verificadorColuna = verificaColuna (*charC, nColuna);
				
				if (verificadorColuna != 0){
						return 1;
				}
	
				return 0;
				
				break;
			case 3:
				*charL = lerLinha ();
			    *charL = converteChar (*charL);
			    *charC = lerColuna ();
			    *charC = converteChar (*charC);
	
				verificadorLinha = verificaLinha (*charL, nLinha);
					
				if (verificadorLinha != 0){
					return 1;
				}
	
				verificadorColuna = verificaColuna (*charC, nColuna);
				
				if (verificadorColuna != 0){
						return 1;
				}
	
				return 0;
				
				break;
	}
	
	return 1;
	
}

int verificaResolucao (int** matLinha, int** matColuna, char **matChar, int* argsLinha, int* argsColuna, int linhas, int colunas){
	int contadorLinha, somaLinha, contadorColuna, somaColuna;
	for (int i = 0; i < linhas; i++){
		somaLinha = 0;
		contadorLinha = 0;
		somaColuna = 0;
		contadorColuna = 0;
		
		for (int j = 0; j < argsLinha[i]; j++){
			somaLinha += matLinha[i][j];
		}
		
		for (int j = 0; j < colunas; j++){
			if (matChar[i][j] == 'x' || matChar[i][j] == 'X'){
				contadorLinha++;
			}
		}
		if (somaLinha - contadorLinha != 0){
			return 1;
		}
		
		for (int j = 0; j < argsColuna[i]; j++){
			somaColuna += matColuna[i][j];
		}
		for (int j = 0; j < linhas; j++){
			if (matChar[j][i] == 'x' || matChar[j][i] == 'X'){
				contadorColuna++;
			}
		}
		if (somaColuna - contadorColuna != 0){
			return 1;
		}
	}
	
	printf("Parabens, voce completou o nonograma!!!\n");
	
	return 0;
}

//verifica a reolucao para o comando resolver
int verificaResolucao2 (int** matLinha, int** matColuna, char **matChar, int* argsLinha, int* argsColuna, int linhas, int colunas){
	int contadorLinha, somaLinha, contadorColuna, somaColuna;
	for (int i = 0; i < linhas; i++){
		somaLinha = 0;
		contadorLinha = 0;
		somaColuna = 0;
		contadorColuna = 0;
		
		for (int j = 0; j < argsLinha[i]; j++){
			somaLinha += matLinha[i][j];
		}
		
		for (int j = 0; j < colunas; j++){
			if (matChar[i][j] == 'x' || matChar[i][j] == 'X'){
				contadorLinha++;
			}
		}
		if (somaLinha - contadorLinha != 0){
			return 1;
		}
		
		for (int j = 0; j < argsColuna[i]; j++){
			somaColuna += matColuna[i][j];
		}
		for (int j = 0; j < linhas; j++){
			if (matChar[j][i] == 'x' || matChar[j][i] == 'X'){
				contadorColuna++;
			}
		}
		if (somaColuna - contadorColuna != 0){
			return 1;
		}
	}
		
	return 0;
}


//seleciona o comando 
int indicadorComando (char* str){
	int tam;
	
	tam = strlen(str);
	
	for (int i = 0; i < tam; i++){
		str[i] = converteChar (str[i]);
	}
	
	if (strcmp (str, "x") == 0){
		return 1;
	}
	else if (strcmp (str, "-") == 0){
		return 2;
	}
	else if (strcmp (str, ".") == 0){
		return 3;
	}
	else if (strcmp (str, "resolver") == 0){
		return 4;
	}
	else if (strcmp (str, "salvar") == 0){
		return 5;
	}
	else if (strcmp (str, "sair") == 0){
		return 6;
	}
	else {
		return 7;
	}
}
