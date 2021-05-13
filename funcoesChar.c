#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoesInt.h"
#include "funcoesVoid.h"
#include "funcoesChar.h"
#include "funcaoResolver.h"
#include "funcaoPrincipal.h"

//le a linha digitada
char lerLinha (){
	char charLinha;

	do{
		scanf ("%c", &charLinha);

	}while (charLinha == ' ' || charLinha == '\n');

	return charLinha;

}

//le a coluna digitada
char lerColuna (){
	char charColuna;

	do{
		scanf ("%c", &charColuna);
	}while (charColuna == ' ' || charColuna == '\n');

	return charColuna;

}

//converte o char digitado
char converteChar (char c){
	if (c >= 65 && c <= 90){
		return (c + 32);
	}
	return c;
}
