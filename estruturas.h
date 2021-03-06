#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
#include <time.h>
#include "constantes.h"

typedef struct 
{
   int id;
   char nome[MAX_CHARACTERES_NOME_ALUNO];
   int regime;
   char turno[MAX_CHARACTERES_TURNO_ALUNO];
   int treinosComp;
   int respostasTotais;
   int respostasCertas;
   float ultimaNota;
}aluno;
typedef struct{
    int id;
    char strresposta[MAX_CHARACTERES_RESPOSTA_RESPOSTA];
}resposta;
typedef struct{
    int id;
    char strpergunta[MAX_CHARACTERES_PERGUNTA_PERGUNTA]; 
    resposta mulrespostas[NUMERO_RESPOSTAS_PERGUNTA];
    int respostacerta;
    int materia;  
    int exame;
    float tempoMedio;
}pergunta;
typedef struct{
    int estado;
    int id;
    int IDaluno; 
    int minutosDur;
    int prova;
    int numperg;
    int numdaserradas;
    pergunta per[10];
    struct tm data;
    int respostasDadas[10];
    float nota; 
}treino;





#endif