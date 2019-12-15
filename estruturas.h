#ifndef ESTRUTURAS_DECLARED
#define ESTRUTURAS_DECLARED
#include <time.h>
#include "constantes.h"

typedef struct 
{
   unsigned char id;
   char nome[MAX_CHARACTERES_NOME_ALUNO];
   
   unsigned char regime;
   unsigned char turno[MAX_CHARACTERES_TURNO_ALUNO];
   unsigned int treinosComp;
   unsigned int respostasTotais;
   unsigned int respostasCertas;
}aluno;
typedef struct{
    char resposta[MAX_CHARACTERES_RESPOSTA_RESPOSTA];

}resposta;
typedef struct{
    unsigned char designacao; 
    resposta resposta[NUMERO_RESPOSTAS_PERGUNTA];
    unsigned char respostacerta;
    unsigned char materia;  
    unsigned char exame;
    unsigned char tipo;   
}pergunta;
typedef struct{
    unsigned int designacao;
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