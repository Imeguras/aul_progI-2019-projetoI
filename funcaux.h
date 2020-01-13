#ifndef FUNCAUX_H_INCLUDED
#define FUNCAUX_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constantes.h"
#include "time.h"
int lerInteiro(char mensagem[FUNCAUX_MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[FUNCAUX_MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[FUNCAUX_MAX_STRING], char vetorCaracteres[FUNCAUX_MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);
int numeroAle(int offset, int alcance);
#endif