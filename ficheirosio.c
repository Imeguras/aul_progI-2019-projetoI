#include "ficheirosio.h"

FILE *ficheiro=NULL;

/*void forcaListaPerguntas(){
    size_t debug; 
    
    debug = fread();
}*/
/*
    Função usada para guardar um treino dentro do ficheiro binário data.dat
    @param trevGrav, estrutura do tipo treino a qual se pretende ser guardada
*/
void guardaTreino(treino *treGrav, int size){
    ficheiro=fopen("treino.dat", "r+");
    
    if(ficheiro==NULL){
        printf("Erro: O ficheiro treino.dat não existe a criar um novo");
        fclose(ficheiro);
        criaFichBinario();
    }else{
        for(int i =0; i<size; i++){
            fwrite(treGrav,sizeof(treino), size, ficheiro);
        }     
    }
    
}
void loadTreino(treino *trevGrav, int size){
        ficheiro=fopen("treino.dat", "r+");
        
        if(ficheiro==NULL){
            printf("Erro: O ficheiro treino.dat não existe a criar um novo");
            fclose(ficheiro);
            criaFichBinario();
        }else{
            for(int i =0; i<size; i++){
                fread(trevGrav,sizeof(treino), size, ficheiro);
            }     
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
        for(unsigned char f=0; f<MAX_PERGUNTAS; f++){
            debug += fwrite(&vazia ,sizeof(pergunta), 1, ficheiro);
        }
        printf("\nEscritas: %d linhas", debug);
    }
    fclose(ficheiro);
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
void criaFichBinarioAluno(){
    size_t debug=0;
    ficheiro=fopen("aluno.dat", "wb");
    if(ficheiro==NULL){
        printf("\nAlgo correu mal com a criação do ficheiro");
        fclose(ficheiro);
    }else{
        aluno avazio ={0};
        for(unsigned char f=0; f<MAX_ALUNOS; f++){
            debug += fwrite(&avazio ,sizeof(aluno), 1, ficheiro);
        }
        printf("\nEscritas: %d linhas", debug);
    }   
}