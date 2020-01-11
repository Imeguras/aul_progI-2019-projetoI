#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
#include <time.h>
#include "constantes.h"

typedef struct 
{
   int id;
   char nome[MAX_CHARACTERES_NOME_ALUNO];
   int regime;
   int turno[MAX_CHARACTERES_TURNO_ALUNO];
   int treinosComp;
   int respostasTotais;
   int respostasCertas;
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
}pergunta;
typedef struct{
    int id; 
    int minutosDur;
    int prova;
    int estado;
    int numperg;
    int numdascertas;
    int numdaserradas;
    float nota; 
}treino;





#endif