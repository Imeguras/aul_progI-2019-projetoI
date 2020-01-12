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
void insAluno(int pos, int id,char nome[MAX_CHARACTERES_NOME_ALUNO], int regime, char turno[MAX_CHARACTERES_TURNO_ALUNO], aluno *listaAluno){
     if(procurAluno(nome,-1,pos,listaAluno) ==-1){
            if(listaAluno[pos].id != 0){
                printf("\nJa existe um aluno inscrito nesta posição\n");
            }else {
                listaAluno[pos].id = id;
                strcpy(listaAluno[pos].nome, nome);
                listaAluno[pos].regime = regime;
                strcpy(listaAluno[pos].turno, turno);
                listaAluno[pos].respostasCertas=0;
                listaAluno[pos].respostasTotais=0;
                listaAluno[pos].treinosComp=0; 
            }
        }else{
            printf("ja existe um aluno com esse nome ou id");
        }
   
    
}

//ATENÇÃO TEM MULTIPLOS RETURNS 
/*
    Procura por um aluno com o nome identico aquele enviado nos parametros ou com um numero igual aquele do id
        @param nome, vetor de letras ao qual a função tentara encontrar um aluno no vetor listaAluno que tenha o campo nome igual, enviar um vetor vazio se nao for relevante procurar pelo nome
        @param id, character usado como numero inteiro ao qual a função tentara encontrar um aluno no vetor alu que tenha o campo id igual, enviar o valor -1 se nao for relevante procurar pelo id
        @param size, tamanho do vetor listaAluno
        @param listaAluno vetor dinamico com os alunos
    */
int procurAluno(char nome[MAX_CHARACTERES_NOME_ALUNO], int id, int size, aluno *listaAluno){
    unsigned int t;
    unsigned char i,k;
    
    if(id==-1){

        for(t=0;t<=size;t++){
            for(i=0;i<MAX_CHARACTERES_NOME_ALUNO;i+=2){
                if(strcmp(nome,listaAluno[t].nome)){
                    return t;
                }
                
                for(k=0; k<count; k++){
                    if(nome[i]==listaAluno[k].nome[i]){
                        k=count;
                    }
                    
                }
            }
        }
    }else{
        for(t=0;t<=size;t++){
            printf("%d", listaAluno[t].id);
            if(listaAluno[t].id == id){
                return t; 
            }
        }
    }
    
    return -1;
}
void printaAlunos(int size, aluno *listaAluno){
    if(size!=1){
        for(int i=0;i<size;i++){
            printf("\nID: %d", listaAluno[i].id);
            printf("\n\tNome: %s", listaAluno[i].nome);
            printf("\n\tRegime: %d",listaAluno[i].regime);
            printf("\n\tTurno: %s",listaAluno[i].turno);
            printf("\n\tQuantidade de resposta Certas: %d",listaAluno[i].respostasCertas);
            printf("\n\tQuantidade de resposta Totais: %d",listaAluno[i].respostasTotais);
            printf("\n\tTreinos completos: %d",listaAluno[i].treinosComp);
        }
    }else{
        printf("\nID: %d", listaAluno[0].id);
        printf("\n\tNome: %s", listaAluno[0].nome);
        printf("\n\tRegime: %d",listaAluno[0].regime);
        printf("\n\tTurno: %s",listaAluno[0].turno);
        printf("\n\tQuantidade de resposta Certas: %d",listaAluno[0].respostasCertas);
        printf("\n\tQuantidade de resposta Totais: %d",listaAluno[0].respostasTotais);
        printf("\n\tTreinos completos: %d",listaAluno[0].treinosComp);
    }
}
#pragma endregion