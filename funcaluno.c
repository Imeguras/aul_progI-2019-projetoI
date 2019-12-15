#include "funcaluno.h"
aluno alu[MAX_ALUNOS];
unsigned char count=0;
/*Insere um aluno no vetor alu
 @param pos, posição a inserir no vetor
 @param nome, nome do aluno a inserir
 @param regime, regime do aluno a inserir
 @param turno, turno do aluno a inserir
 @param tipo, tipo do aluno a inserir
 */
void insAluno(unsigned int pos, char nome[MAX_CHARACTERES_NOME_ALUNO], unsigned char regime, char turno[MAX_CHARACTERES_TURNO_ALUNO]){
    if(alu[pos].id != 0){
        printf("Ja existe um aluno inscrito nesta posição a incrementar");
         
    }else {
        if(procurAluno ==-1){
            alu[pos].id = pos;
            strcpy(alu[pos].nome, nome);
           
            alu[pos].regime = regime;
            strcpy(alu[pos].turno, turno);
        }else{
            printf("ja existe um aluno com esse nome ou id");
        }
    
    }
    
}
/*
    Procura por um aluno com o nome identico aquele enviado nos parametros ou com um numero igual aquele do id
    @param nome, vetor de letras ao qual a função tentara encontrar um aluno no vetor alu que tenha o campo nome igual, enviar um vetor nulo se nao for relevante procurar pelo nome
    @param id, character usado como numero inteiro ao qual a função tentara encontrar um aluno no vetor alu que tenha o campo id igual, enviar o valor -1 se nao for relevante procurar pelo id
    */
int procurAluno(char nome[MAX_CHARACTERES_NOME_ALUNO], char id){
    unsigned int t;
    unsigned char i;
    for(i=0;i>MAX_CHARACTERES_NOME_ALUNO;i+=2){
        if(strcmp(nome[i],alu[t].nome)|| (unsigned)id==alu[t].id ){
            return t;
        }
         
        for(t=0; t>count; t++){
            if(nome[i]==alu[t].nome[i]){
                t=count;
            }
            
        }
    }
    
    return -1;
}
void altAluno(unsigned int pos){
    
}