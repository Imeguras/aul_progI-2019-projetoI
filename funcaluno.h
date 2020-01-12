#ifndef FUNCALUNO_H_INCLUDED
#define FUNCALUNO_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"
void insPergunta(int *tamanhoLista,int id, char enunciado[MAX_CHARACTERES_PERGUNTA_PERGUNTA], resposta respostas[NUMERO_RESPOSTAS_PERGUNTA], int IDrespostacerta,int materia,int exame, pergunta *listaPergunta);
void printaPerguntas(int size, pergunta *listaPerguntas);

void insAluno(int pos, int id,char nome[MAX_CHARACTERES_NOME_ALUNO], int regime, char turno[MAX_CHARACTERES_TURNO_ALUNO],aluno *listaAluno, int w);
int procurAluno(char nome[MAX_CHARACTERES_NOME_ALUNO], int id, int size, aluno *listaAluno);
void printaAlunos(int size, aluno *listaAluno);
#endif