#ifndef FUNCALUNO_H_INCLUDED
#define FUNCALUNO_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"
void insPergunta(int *tamanhoLista,int id, char enunciado[MAX_CHARACTERES_PERGUNTA_PERGUNTA], resposta respostas[NUMERO_RESPOSTAS_PERGUNTA], int IDrespostacerta,int materia,int exame,int tipo, pergunta *listaPergunta);

void insAluno(unsigned int pos, char nome[MAX_CHARACTERES_NOME_ALUNO], unsigned char regime, char turno[MAX_CHARACTERES_TURNO_ALUNO],aluno *listaAluno);
int procurAluno(char nome[MAX_CHARACTERES_NOME_ALUNO], char id, aluno *listaAluno);
#endif