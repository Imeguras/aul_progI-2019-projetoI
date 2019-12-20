#ifndef FUNCALUNO_H_INCLUDED
#define FUNCALUNO_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"
void insAluno(unsigned int pos, char nome[MAX_CHARACTERES_NOME_ALUNO], unsigned char regime, char turno[MAX_CHARACTERES_TURNO_ALUNO]);
int procurAluno(char nome[MAX_CHARACTERES_NOME_ALUNO], char id);
#endif