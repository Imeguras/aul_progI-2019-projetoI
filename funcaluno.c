#include "funcaluno.h"

unsigned char count=0;

#pragma region treinos
/*typedef struct{
    int id;
    int IDaluno; 
    int minutosDur;
    int prova;
    int estado;
    int numperg;
    int numdaserradas;
    pergunta per[10];
    resposta respostasDadas[10];
    float nota; 
}treino;*/
//Estado 256 indica por fazer

treino *criaTreino(int id, int IDaluno, int sizePergunta,int prova, int numperg, treino *listaTreino, pergunta *listaPergunta){
    int k=0;
    if(sizePergunta<4){
        printf("nao existem perguntas suficientes para fazer um exame");
    }else{
        
        listaTreino=realloc(listaTreino,(id+1)*sizeof(treino));
        listaTreino[id-1].id=id;
        listaTreino[id-1].estado=256;
        listaTreino[id-1].IDaluno= IDaluno;
        listaTreino[id-1].numperg=numperg;
        listaTreino[id-1].prova=prova;
        char ids[MAX_PERGUNTAS];
        procurPergunta(ids,&k,prova,-1,-1,sizePergunta,listaPergunta);
        
        for (size_t i = 0; i < numperg; i++)
        {
            
            //printf("%d ",k);
            int aleatoria=numeroAle(0,k);
            listaTreino[id].per[i]=listaPergunta[aleatoria];//=procur(numeroAle(1,sizePergunta));
        }
        
    }
    return listaTreino;
    
}    
void fazTreino(aluno al, treino realizado){
    realizado.estado=0;
    realizado.IDaluno= al.id;
    realizado.minutosDur= lerInteiro("Demoraste quantos minutos a fazer o treino?\n",0,MAX_TEMPO);
    for(int i=0; i<realizado.numperg; i++){
        printf("%s",realizado.per[i].strpergunta);
        realizado.per[i].tempoMedio=(int)realizado.numperg/realizado.minutosDur;
        for (int j = 0; j < NUMERO_RESPOSTAS_PERGUNTA; j++)
        {
            printf("%s", realizado.per[i].mulrespostas[j].strresposta);
        }
        realizado.respostasDadas[i]=lerInteiro("Qual a resposta: ",0,3)+realizado.per[i].id;
        if(realizado.respostasDadas[i]== realizado.per[i].respostacerta) {
            al.respostasCertas+=1;
            realizado.nota += 1/realizado.numperg;
        }
        al.respostasTotais+=1;
    }
    al.treinosComp+=1;
    
}
void printaTreino(int size, treino *listaTreino){
    for(int i=0;i<size;i++){
        printf("\nID: %d", listaTreino[i].id);
        if(listaTreino[i].estado==0){
            printf("Estado: Realizado");
            printf("\nDemorou: %d a ser realizado", listaTreino[i].minutosDur);
            printf("\nNota: %d",listaTreino[i].nota);
            printf("\n\tMateria: %d",listaTreino[i].numdaserradas);
        }else
        {
            printf("Estado: Por fazer");
        }
        printf("\nCriado pelo aluno de ID: %d", listaTreino[i].IDaluno);
        printf("\nExame: %d",listaTreino[i].prova);
        for (size_t t = 0; t < MAX_PERGUNTAS_TREINO; t++)
            printf("\n\tExame: %d",listaTreino[i].per[t]);
        }
        
        
        
       
        
    }

#pragma endregion
#pragma region Perguntas
void insPergunta(int *tamanhoLista,int id, char enunciado[MAX_CHARACTERES_PERGUNTA_PERGUNTA], resposta respostas[NUMERO_RESPOSTAS_PERGUNTA], int IDrespostacerta,int materia,int exame, pergunta *listaPergunta){
        
        if(*tamanhoLista==MAX_PERGUNTAS){
            printf("Lista cheia");
        }else{
            int i,t;
            
            t=*tamanhoLista;     
            listaPergunta[t].id = id;
            strcpy(listaPergunta[*tamanhoLista].strpergunta, enunciado);
            for(i=0; i<NUMERO_RESPOSTAS_PERGUNTA; i++){
               listaPergunta[*tamanhoLista].mulrespostas[i]=respostas[i];
            }
            listaPergunta[*tamanhoLista].materia= materia;
            listaPergunta[*tamanhoLista].respostacerta = IDrespostacerta;
            listaPergunta[*tamanhoLista].exame= exame;
            *tamanhoLista+=1;
        }
}
void printaPerguntas(int size, pergunta *listaPerguntas){
    for(int i=0;i<size;i++){
        
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


void procurPergunta(char *lista,int *t,int exame, int id, int materia,int size, pergunta *listaPergunta){
    unsigned int i=0;    
    
    if(size!=0){
        if(id==-1 && materia==-1){
            for (*t = 0; *t < size; (*t)++){
                if(listaPergunta[*t].exame == exame){  
                    lista[i++]=*t;
                }
            }
          
            
        }else if(exame==-1 && materia==-1 ){
            for (*t = 0; *t < size; (*t)++){
                if(listaPergunta[*t].id == id){
                    lista[i++]=*t;
                }
            }
        }else if(exame==-1 && id==-1 ){
            for (*t = 0; *t < size; (*t)++){
                if(listaPergunta[*t].materia == materia){
                    lista[i++]=*t;
                }
            }
        }

    }
    
    
}
#pragma endregion 
#pragma region Aluno
/*Insere um aluno no vetor alu
 @param pos, posição a inserir no vetor
 @param nome, nome do aluno a inserir
 @param regime, regime do aluno a inserir
 @param turno, turno do aluno a inserir
 @param overwrite, "boolean" que quando esta a um salta a verificação da existencia de um membro na pos
 */
void insAluno(int pos, int id,char nome[MAX_CHARACTERES_NOME_ALUNO], int regime, char turno[MAX_CHARACTERES_TURNO_ALUNO], aluno *listaAluno, int overwrite){
     if((overwrite==1)||procurAluno(nome,-1,pos,listaAluno) ==-1){
            if((overwrite==0)&&listaAluno[pos].id != 0){
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
    if(size!=0){
        if(id==-1){
            for(t=0;t<=size;t++){
                if(strcmp(nome,listaAluno[t].nome)==0){
                        return t;
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