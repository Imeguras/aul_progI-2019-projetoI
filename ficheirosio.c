#include "ficheirosio.h"

FILE *ficheiro=NULL;
/*
    Função usada para guardar um treino dentro do ficheiro binário data.dat
    @param trevGrav, estrutura do tipo treino a qual se pretende ser guardada
    Data.dat é organizado da seguinte maneira e constituido por 5 chunks configuradas da seguinte maneira:
    um chunk header, INI, onde sao guardadas informações utilizadas para optimização de busca e integridade do mesmo
    um chunk perguntas, PER, onde sao guardadas informações referentes as perguntas
    um chunk estudantes, EST, onde sao guardadas informações referentes aos estudantes
    um chunk treinos, TRE, onde sao guardadas informações referentes ao treinos 
*/
void guardaTreino(treino treGrav){
    ficheiro=fopen("data.dat", "wb");
    if(ficheiro==NULL){
        printf("Erro: não existe memória suficiente para criar este ficheiro");
    }   
}