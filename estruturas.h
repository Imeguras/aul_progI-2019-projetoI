#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
#include <time.h>
#include "constantes.h"

typedef struct 
{
   unsigned char id;
   char nome[MAX_CHARACTERES_NOME_ALUNO];
   unsigned char regime;
   unsigned char turno[MAX_CHARACTERES_TURNO_ALUNO];
   unsigned short treinosComp;
   unsigned int respostasTotais;
   unsigned int respostasCertas;
}aluno;
typedef struct{
    unsigned char id;
    char strresposta[MAX_CHARACTERES_RESPOSTA_RESPOSTA];
}resposta;
typedef struct{
    unsigned char id;
    char strpergunta[MAX_CHARACTERES_PERGUNTA_PERGUNTA]; 
    resposta mulrespostas[NUMERO_RESPOSTAS_PERGUNTA];
    unsigned char respostacerta;
    unsigned char materia;  
    unsigned char exame;
    unsigned char tipo;   
}pergunta;
typedef struct{
    unsigned int id;
    struct tm tempoDeInicio;
    struct tm tempoDeFim; 
    unsigned char minutosDur;
    unsigned char prova;
    unsigned char estado;
    unsigned char numperg;
    unsigned char numdascertas;
    unsigned char numdaserradas;
    float nota; 
}treino;





#endif