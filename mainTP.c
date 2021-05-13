#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoesInt.h"
#include "funcoesVoid.h"
#include "funcoesChar.h"
#include "funcaoResolver.h"
#include "funcaoPrincipal.h"
#define TAM 100

int main (int argC, char *argV[])
{
	char nomeDoc[TAM];
	
	if (argC == 1){
		printf("Digite o nome do arquivo que devera ser aberto: ");
		scanf("%s", nomeDoc);
		printf("\n");
		principal (nomeDoc);
	}
	
	else{
		principal (argV[1]);
	}
	
	return 0;
}
