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
    size_t debug;
    resposta rvazio={""};
    
    resposta mvazio[NUMERO_RESPOSTAS_PERGUNTA]={rvazio};
    pergunta vazia={0,mvazio,0,0,0,0};
    aluno vazio;
    ficheiro=fopen("data.dat", "wb");
    if(ficheiro==NULL){
        printf("Algo correu mal com a criação do ficheiro");
    }else{
        
        debug = fwrite(HEADER_FICHEIROSIO, 8,1,ficheiro);
        debug += fwrite(0, sizeof(char), 2, ficheiro);
        debug += fwrite(0, sizeof(short), 1, ficheiro);
        debug += fwrite(0, sizeof(int), 1, ficheiro);
        debug += fwrite(PERGUNTASC_FICHEIROSIO, 8, 1, ficheiro);
        debug += fwrite(&vazia,sizeof(vazia), 40, ficheiro);
        debug += fwrite(ESTUDANTESC_FICHEIROSIO, 8, 1, ficheiro);
        debug += fwrite();
        fclose(ficheiro); 
    }
}
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