#include "ficheirosio.h"

FILE *ficheiro=NULL;
//Cria um ficheiro binário fazendo o *ficheiro com o valor desse mesme ficheiro
void criaBinario(void){
    ficheiro=fopen("data.dat", "wb");
    if(ficheiro==NULL){
        printf("Erro: não existe memória suficiente para criar este ficheiro");
    }   
}