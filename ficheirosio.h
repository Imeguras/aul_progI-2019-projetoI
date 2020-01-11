#ifndef FICHEIROSIO_H_IMPLEMENTATION
#define FICHEIROSIO_H_IMPLEMENTATION
#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"
#include "funcaluno.h"
void guardaTreino(treino *treGrav, int size, int count);
treino *loadTreino(treino *trevGrav, int *size,int *count);
aluno *loadAluno(aluno *trePer, int *size );
void guardaAluno(aluno *trePer, int size);
void guardaPergunta(pergunta *trePer, int size, int count);
pergunta *loadPergunta(pergunta *trePer, int *size ,int *count);
void criaFichBinarioPergunta();
void criaFichBinarioTreino();
void criaFichBinarioAluno();
#endif