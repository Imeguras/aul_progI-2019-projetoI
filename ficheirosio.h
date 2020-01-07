#ifndef FICHEIROSIO_H_IMPLEMENTATION
#define FICHEIROSIO_H_IMPLEMENTATION
#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"
#include "funcaluno.h"
void guardaTreino(treino *treGrav, int size);
void loadTreino(treino *trevGrav);
void loadAluno(aluno *trePer);
void guardaAluno(aluno *trePer, int size);
void guardaPergunta(pergunta *trePer, int size);
void loadPergunta(pergunta *trePer);
void criaFichBinarioPergunta();
void criaFichBinarioTreino();
void criaFichBinarioAluno();
void forcaContaPerguntas();
#endif