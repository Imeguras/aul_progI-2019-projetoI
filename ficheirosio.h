#ifndef FICHEIROSIO_H_IMPLEMENTATION
#define FICHEIROSIO_H_IMPLEMENTATION
#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"
#include "funcaluno.h"
void guardaTreino(treino *treGrav, int size);
int loadTreino(treino *trevGrav);
int loadAluno(aluno *trePer);
void guardaAluno(aluno *trePer, int size);
void guardaPergunta(pergunta *trePer, int size);
int loadPergunta(pergunta *trePer);
void criaFichBinarioPergunta();
void criaFichBinarioTreino();
void criaFichBinarioAluno();
void forcaContaPerguntas();
#endif