#include "ficheirosio.h"

FILE *ficheiro=NULL;

#pragma region Treino
void guardaTreino(treino *treGrav, int size){
    ficheiro=fopen("treino.dat", "r+");
    
    if(ficheiro==NULL){
        printf("Erro: O ficheiro treino.dat não existe a criar um novo");
        fclose(ficheiro);
        criaFichBinarioTreino();
        guardaTreino(treGrav,size);
    }else{
            fseek(ficheiro,0,SEEK_SET);
            fwrite(treGrav,sizeof(treino), size, ficheiro);     
            fclose(ficheiro);
    }
    
}
void loadTreino(treino *trevGrav, int size){
        ficheiro=fopen("treino.dat", "r+");
        
        if(ficheiro==NULL){
            printf("Erro: O ficheiro treino.dat não existe a criar um novo");
            fclose(ficheiro);
            criaFichBinarioTreino();
            loadTreino(trevGrav,size);
        }else{
            fread(trevGrav,sizeof(treino), size, ficheiro);     
            fclose(ficheiro);
        }
}
void criaFichBinarioTreino(){
    size_t debug=0;
    ficheiro=fopen("treino.dat", "wb");
    if(ficheiro==NULL){
        printf("\nAlgo correu mal com a criação do ficheiro");
        fclose(ficheiro);
    }else{
        treino tvazio ={0};
        debug = fwrite(&tvazio ,sizeof(treino), 1, ficheiro); 
        printf("\nEscritas: %d linhas", debug);
    }
    
}
#pragma endregion 
#pragma region Pergunta
void guardaPergunta(pergunta *trePer, int size){
    ficheiro=fopen("pergunta.dat", "r+");
    
    if(ficheiro==NULL){
        printf("Erro: O ficheiro treino.dat não existe a criar um novo");
        fclose(ficheiro);
        criaFichBinarioPergunta();
        guardaPergunta(trePer,size);
    }else{
            fseek(ficheiro,0,SEEK_SET);
            fwrite(trePer,sizeof(pergunta), size, ficheiro);     
            fclose(ficheiro);
    }
    
}
void loadPergunta(pergunta *trePer, int size){
        ficheiro=fopen("pergunta.dat", "r+");
        
        if(ficheiro==NULL){
            printf("Erro: O ficheiro treino.dat não existe a criar um novo");
            fclose(ficheiro);
            criaFichBinarioPergunta();
            loadPergunta(trePer,size);
        }else{
            fread(trePer,sizeof(pergunta), size, ficheiro);     
            fclose(ficheiro);
        }
}
void criaFichBinarioPergunta(){
    size_t debug=0;
    ficheiro=fopen("pergunta.dat", "wb");
    if(ficheiro==NULL){
        printf("\nAlgo correu mal com a criação do ficheiro");
        fclose(ficheiro);
    }else{
        pergunta vazia ={0};
        debug += fwrite(&vazia ,sizeof(pergunta), 1, ficheiro);
        printf("\nEscritas: %d linhas", debug);
    }
    fclose(ficheiro);
}
#pragma endregion
#pragma region Aluno
void guardaAluno(aluno *trePer, int size){
    ficheiro=fopen("Aluno.dat", "r+");
    
    if(ficheiro==NULL){
        printf("Erro: O ficheiro treino.dat não existe a criar um novo");
        fclose(ficheiro);
        criaFichBinarioAluno();
        guardaAluno(trePer,size);
    }else{
            fseek(ficheiro,0,SEEK_SET);
            fwrite(trePer,sizeof(aluno), size, ficheiro);     
            fclose(ficheiro);
    }
    
}
void loadAluno(aluno *trePer, int size){
        ficheiro=fopen("Aluno.dat", "r+");
        
        if(ficheiro==NULL){
            printf("Erro: O ficheiro treino.dat não existe a criar um novo");
            fclose(ficheiro);
            criaFichBinarioAluno();
            loadAluno(trePer,size);
        }else{
            fread(trePer,sizeof(aluno), size, ficheiro);     
            fclose(ficheiro);
        }
}
void criaFichBinarioAluno(){
    size_t debug=0;
    
    ficheiro=fopen("aluno.dat", "wb");
    if(ficheiro==NULL){
        printf("\nAlgo correu mal com a criação do ficheiro");
        fclose(ficheiro);
    }else{
        aluno avazio ={0};
        debug += fwrite(&avazio ,sizeof(aluno), 1, ficheiro);
        printf("\nEscritas: %d linhas", debug);
    }   
}
#pragma endregion