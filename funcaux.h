#ifndef FUNCAUX_DECLARED
#define FUNCAUX_DECLARED
#include <stdio.h>
#include <string.h>
#include "constantes.h"
int lerInteiro(char mensagem[FUNCAUX_MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[FUNCAUX_MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[FUNCAUX_MAX_STRING], char vetorCaracteres[FUNCAUX_MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);
#endif