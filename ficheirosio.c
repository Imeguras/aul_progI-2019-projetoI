#include "ficheirosio.h"

FILE *ficheiro=NULL;
/*
    Função usada para criar o ficheiro binário
    Data.dat é organizado da seguinte maneira e constituido por 5 chunks configuradas da seguinte maneira:
    um chunk header, INI, onde sao guardadas informações utilizadas para optimização de busca e integridade do mesmo
        8 bytes usados para anunciar o inicio do chunk header
        1*2+2 bytes para indicar respetivamente o numero de perguntas, o numero de estudantes e a quantidade de treinos existentes todos unsigned, sendo que o numero de estudantes e perguntas sao chars(min 0 max 255) e o numero de treinos é um short(min 0 max 65535)+ 4 bytes para um int vazio 
        
    um chunk perguntas, PER, onde sao guardadas informações referentes as perguntas
    um chunk estudantes, EST, onde sao guardadas informações referentes aos estudantes
    um chunk treinos, TRE, onde sao guardadas informações referentes ao treinos 
    um chunk fim, END, indica o fim do ficheiro
*/
void criaFichBinario(){
    //variaveis vazias
    size_t debug;
    int zero =0;
    resposta rvazio={'\1','\0'};
    resposta mvazio[NUMERO_RESPOSTAS_PERGUNTA]={rvazio,rvazio,rvazio,rvazio};
    pergunta vazia={0,mvazio,1,1,1,1};
    aluno avazio={0,'\1',1,'\1',1,1};
    struct tm yvazio={0};
    treino tvazio ={0,yvazio,yvazio,1,1,1,1,1,1,1};

    ficheiro=fopen("data.dat", "wb");
    if(ficheiro==NULL){
        printf("\nAlgo correu mal com a criação do ficheiro");
    }else{
        debug = fwrite(&HEADER_FICHEIROSIO, 1,8,ficheiro);
        debug += fwrite(&zero, sizeof(char), 2, ficheiro);
        debug += fwrite(&zero, sizeof(short), 1, ficheiro);
        debug += fwrite(&zero, sizeof(int), 1, ficheiro);
        debug += fwrite(&PERGUNTASC_FICHEIROSIO, 1, 8, ficheiro);
        for(unsigned f=0; f<MAX_PERGUNTAS; f++){
            debug += fwrite(&vazia,sizeof(pergunta), 1, ficheiro);
        }
        debug += fwrite(&ESTUDANTESC_FICHEIROSIO, 1, 8, ficheiro);
        for(unsigned f=0; f<MAX_ALUNOS; f++){
            debug += fwrite(&avazio,sizeof(aluno), 1,ficheiro);
        }
        debug += fwrite(&TREINOSC_FICHEIROSIO, 1, 8, ficheiro);
        debug += fwrite(&tvazio, sizeof(treino), 1, ficheiro);
        debug += fwrite(&ENDC_FICHEIROSIO, 1, 8, ficheiro);
        printf("\nEscritas: %d linhas", debug);
    }
    fclose(ficheiro);
}
/*void forcaListaPerguntas(){
    size_t debug; 
    
    debug = fread();
}*/
/*
    Função usada para guardar um treino dentro do ficheiro binário data.dat
    @param trevGrav, estrutura do tipo treino a qual se pretende ser guardada
*/
void guardaTreino(treino treGrav){
    ficheiro=fopen("data.dat", "r+");
    if(ficheiro==NULL){
        printf("Erro: O ficheiro data.dat não existe a criar um novo");
        fclose(ficheiro);
        criaFichBinario();
    }else{

    }
    
}

int main(int argc, char const *argv[])
{
    criaFichBinario();
    return 0;
}
