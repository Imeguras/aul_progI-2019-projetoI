#include "funcaluno.h"
unsigned char count=0;
#pragma region respostas

#pragma endregion
#pragma region Perguntas
void insPergunta(int *tamanhoLista,int id, char enunciado[MAX_CHARACTERES_PERGUNTA_PERGUNTA], resposta respostas[NUMERO_RESPOSTAS_PERGUNTA], int IDrespostacerta,int materia,int exame, pergunta *listaPergunta){
        printf("works");
        if(*tamanhoLista==MAX_PERGUNTAS){
            printf("Lista cheia");
        }else{
            int i,t;
            *tamanhoLista+=1;
            t=*tamanhoLista;     
            listaPergunta[t].id = id;
            strcpy(listaPergunta[*tamanhoLista].strpergunta, enunciado);
            for(i=0; i<NUMERO_RESPOSTAS_PERGUNTA; i++){
               listaPergunta[*tamanhoLista].mulrespostas[i]=respostas[i];
            }
            listaPergunta[*tamanhoLista].materia= materia;
            
            listaPergunta[*tamanhoLista].exame= exame;
        }
}
void printaPerguntas(int size, pergunta *listaPerguntas){
    for(int i=1;i<=size;i++){
        
        printf("\nID: %d", listaPerguntas[i].id);
        printf("\n\tEnunciado: %s", listaPerguntas[i].strpergunta);
        printf("\n\tRespostas:");
        for(int j=0; j<NUMERO_RESPOSTAS_PERGUNTA; j++){
            printf("\n\t\tID da resposta %d: %d",j, listaPerguntas[i].mulrespostas[j].id);
            printf("\n\t\tFrase da resposta %d: %s",j, listaPerguntas[i].mulrespostas[j].strresposta);
        }
        printf("\n\tResposta Certa: %d",listaPerguntas[i].respostacerta);
        printf("\n\tMateria: %d",listaPerguntas[i].materia);
        printf("\n\tExame: %d",listaPerguntas[i].exame);
        
    }
}
#pragma endregion 
#pragma region Aluno
/*Insere um aluno no vetor alu
 @param pos, posição a inserir no vetor
 @param nome, nome do aluno a inserir
 @param regime, regime do aluno a inserir
 @param turno, turno do aluno a inserir
 @param tipo, tipo do aluno a inserir
 */
void insAluno(unsigned int pos, char nome[MAX_CHARACTERES_NOME_ALUNO], unsigned char regime, char turno[MAX_CHARACTERES_TURNO_ALUNO], aluno *listaAluno){
     if(procurAluno(nome,-1,listaAluno) ==-1){
            if(listaAluno[pos].id != 0){
                printf("Ja existe um aluno inscrito nesta posição a incrementar");
            }else {
                listaAluno[pos].id = pos;
                strcpy(listaAluno[pos].nome, nome);
            
                listaAluno[pos].regime = regime;
                strcpy(listaAluno[pos].turno, turno);
            }
        }else{
            printf("ja existe um aluno com esse nome ou id");
        }
   
    
}
/*
    Procura por um aluno com o nome identico aquele enviado nos parametros ou com um numero igual aquele do id
    @param nome, vetor de letras ao qual a função tentara encontrar um aluno no vetor alu que tenha o campo nome igual, enviar um vetor nulo se nao for relevante procurar pelo nome
    @param id, character usado como numero inteiro ao qual a função tentara encontrar um aluno no vetor alu que tenha o campo id igual, enviar o valor -1 se nao for relevante procurar pelo id
    */
int procurAluno(char nome[MAX_CHARACTERES_NOME_ALUNO], char id, aluno *listaAluno){
    unsigned int t;
    unsigned char i;
    for(i=0;i>MAX_CHARACTERES_NOME_ALUNO;i+=2){
        if(strcmp(nome[i],listaAluno[t].nome)|| (unsigned)id==listaAluno[t].id ){
            return t;
        }
         
        for(t=0; t>count; t++){
            if(nome[i]==listaAluno[t].nome[i]){
                t=count;
            }
            
        }
    }
    
    return -1;
}
void altAluno(unsigned int pos){
    
}
#pragma endregion