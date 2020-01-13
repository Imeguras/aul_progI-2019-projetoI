#include "ficheirosio.h"

FILE *ficheiro=NULL;

#pragma region Treino
void guardaTreino(treino *treGrav, int size, int count){
    ficheiro=fopen("treino.dat", "r+b");
    
    if(ficheiro==NULL){
        printf("Erro: O ficheiro treino.dat não existe a criar um novo");
        fclose(ficheiro);
        criaFichBinarioTreino();
        guardaTreino(treGrav,size, count);
    }else{
            fseek(ficheiro,0,SEEK_SET);
            fwrite(&size, sizeof(int), 1, ficheiro);
            fwrite(&count, sizeof(int),1, ficheiro);
            fwrite(treGrav,sizeof(treino), size, ficheiro);     
            fclose(ficheiro);
    }
    
}
treino *loadTreino(treino *trevGrav, int *size, int *count){
        
        
        ficheiro=fopen("treino.dat", "r+b");
        if(ficheiro==NULL){
            printf("Erro: O ficheiro treino.dat não existe a criar um novo");
            fclose(ficheiro);
            criaFichBinarioTreino();
            loadTreino(trevGrav,size, count);
        }else{
            fread(size, sizeof(int), 1, ficheiro);
            fread(count, sizeof(int), 1, ficheiro);
            trevGrav=realloc(trevGrav,sizeof(treino)*(*size));
            if(size!=0){
                fread(trevGrav,sizeof(treino), *size, ficheiro);  
            }   
            fclose(ficheiro);
        }
        return trevGrav;
}
void criaFichBinarioTreino(){
    size_t debug=0;
    ficheiro=fopen("treino.dat", "wb");
    if(ficheiro==NULL){
        printf("\nAlgo correu mal com a criação do ficheiro");
        //fclose(ficheiro);
    }else{
        treino tvazio ={0};
        
        debug+=fwrite(&debug, sizeof(int), 1, ficheiro);
        debug+=fwrite(&debug, sizeof(int), 1, ficheiro);
        fwrite(&tvazio ,sizeof(treino), 1, ficheiro); 
        printf("\nEscritas: %d linhas", debug);
        fclose(ficheiro);
    }
    
}
#pragma endregion 
#pragma region Pergunta

void guardaPergunta(pergunta *trePer,int size, int count){
    ficheiro=fopen("pergunta.dat", "r+b");
    
    if(ficheiro==NULL){
        printf("Erro: O ficheiro treino.dat não existe a criar um novo");
        fclose(ficheiro);
        criaFichBinarioPergunta();
        guardaPergunta(trePer,size, count);
        
    }else{
            fseek(ficheiro,0,SEEK_SET);
            fwrite(&size, sizeof(int), 1, ficheiro);
            fwrite(&count, sizeof(int), 1, ficheiro);
            fwrite(trePer,sizeof(pergunta),size,ficheiro);
            /*for(int i=0; i<=size;i++){
                fwrite(&trePer[i].id,sizeof(int), 1, ficheiro); 
                fwrite(&trePer[i].strpergunta,sizeof(char), MAX_CHARACTERES_PERGUNTA_PERGUNTA, ficheiro); 
                fwrite(&trePer[i].mulrespostas,sizeof(resposta), NUMERO_RESPOSTAS_PERGUNTA,ficheiro);
                fwrite(&trePer[i].respostacerta, sizeof(int), 1, ficheiro);
                fwrite(&trePer[i].materia, sizeof(int), 1, ficheiro);
                fwrite(&trePer[i].exame, sizeof(int), 1, ficheiro);
            }*/    
            fclose(ficheiro);
    }
    
}
pergunta *loadPergunta(pergunta *trePer,int *size, int *count){
       
        ficheiro=fopen("pergunta.dat", "r+b");
        
        if(ficheiro==NULL){
            printf("Erro: O ficheiro treino.dat não existe a criar um novo");
            fclose(ficheiro);
            criaFichBinarioPergunta();
            loadPergunta(trePer, size, count);
        }else{
            fread(size, sizeof(int), 1, ficheiro);
            fread(count, sizeof(int), 1, ficheiro);
            trePer=realloc(trePer,sizeof(pergunta)*MAX_PERGUNTAS);
            if(size!=0){
                fread(trePer,sizeof(pergunta), *size, ficheiro);
            }     
            fclose(ficheiro);
            
        }
        return trePer;
}
void criaFichBinarioPergunta(){
    size_t debug=0;
    ficheiro=fopen("pergunta.dat", "wb");
    if(ficheiro==NULL){
        printf("\nAlgo correu mal com a criação do ficheiro");
        fclose(ficheiro);
    }else{
        pergunta vazia ={0};
        fwrite(&debug, sizeof(int), 1, ficheiro);//debug -0
        fwrite(&debug, sizeof(int), 1, ficheiro);//debug -1
        fwrite(&vazia ,sizeof(pergunta), 1, ficheiro);
        printf("\nEscritas: %d linhas", debug);
        fclose(ficheiro);
    }
    
}
#pragma endregion
#pragma region Aluno
void guardaAluno(aluno *trePer, int size){
    ficheiro=fopen("aluno.dat", "r+b");
    
    if(ficheiro==NULL){
        printf("Erro: O ficheiro treino.dat não existe a criar um novo");
        fclose(ficheiro);
        criaFichBinarioAluno();
        guardaAluno(trePer,size);
    }else{
            fseek(ficheiro,0,SEEK_SET);
            fwrite(&size, sizeof(int), 1, ficheiro);
            fwrite(trePer,sizeof(aluno), size, ficheiro); 
            fclose(ficheiro);
    }
    
}
aluno *loadAluno(aluno *trePer, int *size){
        
        ficheiro=fopen("aluno.dat", "r+b");
        if(ficheiro==NULL){
            printf("Erro: O ficheiro treino.dat não existe a criar um novo");
            fclose(ficheiro);
            criaFichBinarioAluno();
            loadAluno(trePer, size);
        }else{
            fread(size, sizeof(int), 1, ficheiro);
            trePer=realloc(trePer,sizeof(aluno)*MAX_ALUNOS);
            if(size!=0){
                fread(trePer,sizeof(aluno), *size, ficheiro); 
            }    
            fclose(ficheiro);
           
        }
        return trePer;
}
void criaFichBinarioAluno(){
    size_t debug=0;
    
    ficheiro=fopen("aluno.dat", "wb");
    if(ficheiro==NULL){
        printf("\nAlgo correu mal com a criação do ficheiro");
        fclose(ficheiro);
    }else{
        aluno avazio ={0};
         fwrite(&debug, sizeof(int), 1, ficheiro);
        fwrite(&avazio.id, sizeof(int), 1, ficheiro);
        fwrite(&avazio ,sizeof(aluno), 1, ficheiro);
        
        fclose(ficheiro);
    }   
}
#pragma endregion