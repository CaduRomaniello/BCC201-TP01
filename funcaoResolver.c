#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoesInt.h"
#include "funcoesVoid.h"
#include "funcoesChar.h"
#include "funcaoResolver.h"
#include "funcaoPrincipal.h"

//resolve o nonograma
void resolver(char*** mat, int nLinha, int nColuna, int* argLinha, int* argColuna, int** matLinha, int** matColuna){
	int* somaL = malloc (nLinha * sizeof(int));
	int* somaC = malloc (nColuna * sizeof(int));
	int aux, aux2, aux3, verificador, k;
	double div;
	
	for (int i = 0; i < nLinha; i++){
		somaL[i] = 0;
		for (int j = 0; j < argLinha[i]; j++){
			somaL[i] += matLinha[i][j];
		}
	}
	
	for (int i = 0; i < nColuna; i++){
		somaC[i] = 0;
		for (int j = 0; j < argColuna[i]; j++){
			somaC[i] += matColuna[i][j];
		}
	}

	for (int i = 0; i < nLinha; i++){
		if (argLinha[i] == 1){
			if (matLinha[i][0] == nColuna){
				for (int j = 0; j < nColuna; j++){
					(*mat)[i][j] = 'X';
				}
			}
			else{
				div = (double)matLinha[i][0] / (double)nColuna;
				if (div > 0.5){
					for (int j = 0; j < argLinha[i]; j++){
						for (int k = (nColuna - matLinha[i][j]); k < matLinha[i][j]; k++){
							(*mat)[i][k] = 'X';
						}
					}
				}
			}
		}
	}
	
	for (int i = 0; i < nColuna; i++){
		if (argColuna[i] == 1){
			if (matColuna[i][0] == nLinha){
				for (int j = 0; j < nLinha; j++){
					(*mat)[j][i] = 'X';
				}
			}
			else{
				div = (double)matColuna[i][0] / (double)nLinha;
				if (div > 0.5){
					for (int j = 0; j < argColuna[i]; j++){
						for (int k = (nLinha - matColuna[i][j]); k < matColuna[i][j]; k++){
							(*mat)[k][i] = 'X';
						}
					}
				}
			}
		}
	}
	
	for (int i = 0; i < nLinha; i++){
		k = 0;
		aux = 0;
		if ((somaL[i] + (argLinha[i] - 1)) == nColuna){
			for (int j = 0; j < nColuna; j++){
				if (aux < matLinha[i][k]){
					(*mat)[i][j] = 'X';
					aux++;
				}
				else if (aux == matLinha[i][k]){
					(*mat)[i][j] = '-';
					aux = 0;
					k++;
				}
			}
		}
	}
	
	for (int i = 0; i < nColuna; i++){
		k = 0;
		aux = 0;
		if ((somaC[i] + (argColuna[i] - 1)) == nLinha){
			for (int j = 0; j < nLinha; j++){
				if (aux < matColuna[i][k]){
					(*mat)[j][i] = 'X';
					aux++;
				}
				else if (aux == matColuna[i][k]){
					(*mat)[j][i] = '-';
					aux = 0;
					k++;
				}
			}
		}
	}
	
	for (int i = 0; i < nLinha; i++){
		aux = 0;
		for (int j = 0; j < nColuna; j++){
			if ((*mat)[i][j] == 'x' || (*mat)[i][j] == 'X'){
				aux++;
			}
		}
		if (somaL[i] == aux){
			for (int j = 0; j < nColuna; j++){
				if ((*mat)[i][j] != 'x' && (*mat)[i][j] != 'X'){
					(*mat)[i][j] = '-';
				}
			}
		}
	}
	
	for (int i = 0; i < nColuna; i++){
		aux = 0;
		for (int j = 0; j < nLinha; j++){
			if ((*mat)[j][i] == 'x' || (*mat)[j][i] == 'X'){
				aux++;
			}
		}
		if (somaC[i] == aux){
			for (int j = 0; j < nLinha; j++){
				if ((*mat)[j][i] != 'x' && (*mat)[j][i] != 'X'){
					(*mat)[j][i] = '-';
				}
			}
		}
	}
	
	for (int i = 0; i < nLinha; i++){
		aux = 0;
		aux2 = 0;
		for (int j = 0; j < nColuna; j++){
			if ((*mat)[i][j] == '.'){
				aux++;
			}
			
			if ((*mat)[i][j] == 'x' || (*mat)[i][j] == 'X'){
				aux2++;
			}
		}
		if (somaL[i] == (aux + aux2)){
			for (int j = 0; j < nColuna; j++){
				if ((*mat)[i][j] == '.'){
					(*mat)[i][j] = 'X';
				}
			}
		}
	}
	
	for (int i = 0; i < nColuna; i++){
		aux = 0;
		aux2 = 0;
		for (int j = 0; j < nLinha; j++){
			if ((*mat)[j][i] == '.'){
				aux++;
			}
			
			if ((*mat)[j][i] == 'x' || (*mat)[j][i] == 'X'){
				aux2++;
			}
		}
		if (somaC[i] == (aux + aux2)){
			for (int j = 0; j < nLinha; j++){
				if ((*mat)[j][i] == '.'){
					(*mat)[j][i] = 'X';
				}
			}
		}
	}
	
	verificador = verificaResolucao2 (matLinha, matColuna, *mat, argLinha, argColuna, nLinha, nColuna);
	
	if (verificador == 0){
		return;
	}
	
	for (int i = 0; i < nLinha; i++){
		if (argLinha[i] == 1){
			aux = 0;
			for (int j = 0; j < nColuna; j++){
				if ((*mat)[i][j] == 'x' || (*mat) [i][j] == 'X'){
					aux++;
				}
			}
			if (aux >1){
				aux = 0;
				aux2 = 0;
				aux3 = 0;
				for (int j = 0; j < nLinha; j++){
					if ((*mat)[i][j] == 'x' || (*mat) [i][j] == 'X'){
						if (aux3 ==0){
							aux= j;
							aux3++;
						}
						else{
							aux2 = j;
						}
					}
				}
			}
			if ((aux2 - aux + 1) <= somaL[i]){
				for (int j = aux; j <= aux2; j++){
					(*mat)[i][j] = 'X';
				}
			}
		}
	}
	
	for (int i = 0; i < nColuna; i++){
		if (argColuna[i] == 1){
			aux = 0;
			for (int j = 0; j < nLinha; j++){
				if ((*mat)[j][i] == 'x' || (*mat) [j][i] == 'X'){
					aux++;
				}
			}
			if (aux >1){
				aux = 0;
				aux2 = 0;
				aux3 = 0;
				for (int j = 0; j < nColuna; j++){
					if ((*mat)[j][i] == 'x' || (*mat) [j][i] == 'X'){
						if (aux3 ==0){
							aux= j;
							aux3++;
						}
						else{
							aux2 = j;
						}
					}
				}
			}
			if ((aux2 - aux + 1) <= somaC[i]){
				for (int j = aux; j <= aux2; j++){
					(*mat)[j][i] = 'X';
				}
			}
		}
	}
	
	for (int i = 0; i < nLinha; i++){
		aux = 0;
		for (int j = 0; j < nColuna; j++){
			if ((*mat)[i][j] == 'x' || (*mat)[i][j] == 'X'){
				aux++;
			}
		}
		if (somaL[i] == aux){
			for (int j = 0; j < nColuna; j++){
				if ((*mat)[i][j] != 'x' && (*mat)[i][j] != 'X'){
					(*mat)[i][j] = '-';
				}
			}
		}
	}
	
	for (int i = 0; i < nColuna; i++){
		aux = 0;
		for (int j = 0; j < nLinha; j++){
			if ((*mat)[j][i] == 'x' || (*mat)[j][i] == 'X'){
				aux++;
			}
		}
		if (somaC[i] == aux){
			for (int j = 0; j < nLinha; j++){
				if ((*mat)[j][i] != 'x' && (*mat)[j][i] != 'X'){
					(*mat)[j][i] = '-';
				}
			}
		}
	}
	
	for (int i = 0; i < nLinha; i++){
		aux = 0;
		aux2 = 0;
		for (int j = 0; j < nColuna; j++){
			if ((*mat)[i][j] == '.'){
				aux++;
			}
			
			if ((*mat)[i][j] == 'x' || (*mat)[i][j] == 'X'){
				aux2++;
			}
		}
		if (somaL[i] == (aux + aux2)){
			for (int j = 0; j < nColuna; j++){
				if ((*mat)[i][j] == '.'){
					(*mat)[i][j] = 'X';
				}
			}
		}
	}
	
	for (int i = 0; i < nColuna; i++){
		aux = 0;
		aux2 = 0;
		for (int j = 0; j < nLinha; j++){
			if ((*mat)[j][i] == '.'){
				aux++;
			}
			
			if ((*mat)[j][i] == 'x' || (*mat)[j][i] == 'X'){
				aux2++;
			}
		}
		if (somaC[i] == (aux + aux2)){
			for (int j = 0; j < nLinha; j++){
				if ((*mat)[j][i] == '.'){
					(*mat)[j][i] = 'X';
				}
			}
		}
	}

}
