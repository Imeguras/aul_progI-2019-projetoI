#include <stdlib.h>
#include <stdio.h>
#include "ficheirosio.h"
#include "funcaux.h"
#include "funcaluno.h"
treino *listaTreino=NULL;
aluno *listaAluno=NULL;
pergunta *listaPergunta=NULL;
int sizeTreino=0, sizeAluno=0, sizePergunta=0;
int countTreino=1, countPergunta=1;
void menu();
int main(int argc, char const *argv[]){
    //criaFichBinarioAluno();
    //criaFichBinarioTreino();
    //criaFichBinarioPergunta();
    //sizeTreino=loadTreino(listaTreino,&countTreino);
    //sizeAluno=loadAluno(listaAluno);
    listaPergunta=loadPergunta(listaPergunta,&sizePergunta,&countPergunta);
    menu();
    //guardaTreino(listaTreino,sizeTreino, countTreino);
    //guardaAluno(listaAluno,sizeAluno);
    guardaPergunta(listaPergunta,sizePergunta, countPergunta);
    //free(listaTreino);
    free(listaPergunta);
    //free(listaAluno);
    return 0;
}

void menu(){
    int opcao, submenu;
    char enunciado[MAX_CHARACTERES_PERGUNTA_PERGUNTA];
    int materia;
    int exame;
    resposta listaResposta[4];
    int respostacerta;
    int tipo;
    do
    {
        printf("Quantidade de estudantes: %d\n", sizeAluno);
        printf("Quantidade de perguntas: %d\n", sizePergunta);
        printf("Quantidade de treinos realizados: %d\n", sizeTreino);
        printf("Quantidade de treinos a decorrer: %d\n", sizeTreino);
        printf("\n---------------Menu---------------\n\n");
        printf("0 - Sair\n");
        printf("1 - Perguntas\n");
        printf("2 - Dados dos estudantes\n");
        printf("3 - Treinos\n");
        printf("4 - Rankings\n");
        printf("5 - Dados Estatisticos\n");
        printf("6 - \n");
        printf("7 - \n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 0:
            printf("\n\tA sair do programa.\n");
            break;
        case 1:
            do
            {
        
               printf("0 - Voltar\n");
                printf("1 - Inserir\n");
                printf("2 - Consultar\n");
                printf("3 - Alterar\n");
                printf("4 - Listar\n");
                printf("Opcao: ");
                scanf("%d", &submenu);

                switch(submenu)
                {
                case 0:
                    printf("\n\nA voltar\n\n");
                    break;
               
                    case 1:
                        
                        lerString("Escreve o enunciado da pergunta: ",enunciado,MAX_CHARACTERES_PERGUNTA_PERGUNTA);
                        respostacerta=lerInteiro("Escreve o id da resposta certa", 1, MAX_ID);    
                        materia = lerInteiro("Escreve a materia", 1, MAX_ID);    
                        exame = lerInteiro("Escreve o exame", 1, MAX_ID);    
                        tipo = lerInteiro("Escreve o tipo", 1, MAX_ID);
                        #pragma region im bored
                                listaResposta[0].id=0;
                                listaResposta[0].strresposta[0]='d';
                                listaResposta[0].strresposta[1]='\0';
                                listaResposta[1].id=0;
                                listaResposta[1].strresposta[0]='d';
                                listaResposta[1].strresposta[1]='\0';
                                listaResposta[2].id=0;
                                listaResposta[2].strresposta[0]='d';
                                listaResposta[2].strresposta[1]='\0';
                                listaResposta[3].id=0;
                                listaResposta[3].strresposta[0]='d';
                                listaResposta[3].strresposta[1]='\0';
                        #pragma endregion 
                        /*printf("\n%d",sizePergunta);
                        printf("\n%d",countPergunta);
                        printf("\n%s",enunciado);
                        printf("\n%s", listaResposta[0].strresposta);
                        printf("\n%s", listaResposta[1].strresposta);
                        printf("\n%s", listaResposta[2].strresposta);
                        printf("\n%s", listaResposta[3].strresposta);
                        */
                        insPergunta(&sizePergunta,countPergunta,(char *)enunciado,(resposta *)listaResposta,respostacerta, materia, exame, listaPergunta);
                        //insPergunta(&sizePergunta,0,"0",listaResposta, 0,0,0,0,listaPergunta);
                        break;
                    case 2:
                        printf("\n2sub\n");
                        break;
                    case 3:
                        printf("\n3sub\n");
                        break;
                    case 4:
                        printaPerguntas(sizePergunta, listaPergunta);
                        break;
                    default:
                        printf("\nOpcao invalida\n");
                }
            }while(submenu != 0);
            break;
        case 2:
            do{
                printf("0 - Voltar\n");
                printf("1 - Inserir\n");
                printf("2 - Alterar\n");
                printf("3 - Consultar\n");
                printf("4 - Listar\n");
                printf("Opcao: ");
                scanf("%d", &submenu);

                switch(submenu){
                    case 0:
                        printf("\n\nA voltar\n\n");
                        break;
                    case 1:
                        printf("\n1sub\n");
                        break;
                    case 2:
                        printf("\n2sub\n");
                        break;
                    case 3:
                        printf("\n3sub\n");
                        break;
                    default:
                        printf("\nOpcao invalida\n");
                }
            }while(submenu != 0);
            break;
        case 3:
            do{
                printf("0 - Voltar\n");
                printf("1 - Consultar\n");
                printf("2 - Listar\n");
                printf("Opcao: ");
                scanf("%d", &submenu);

                switch(submenu){
                    case 0:
                        printf("\n\nA voltar\n\n");
                        break;
                    case 1:
                        printf("\n1sub\n");
                        break;
                    case 2:
                        printf("\n2sub\n");
                        break;
                    default:
                        printf("\nOpcao invalida\n");
                }
            }while(submenu != 0);
            break;
        case 4:
            printf("\n4\n");
            break;
        case 5:
            do
            {
                printf("0 - Voltar\n");
                printf("1 - O tempo medio de resposta a uma pergunta\n");
                printf("2 - Quantidade de treinos realizados entre duas datas\n");
                printf("3 - Percentagem de treinos efetuados por cada prova\n");
                printf("4 - Pergunta com a maior quantidade de respostas erradas\n");
                printf("5 - Tipo de perguntas com a menor percentagem de respostas corretas\n");
                printf("Opcao: ");
                scanf("%d", &submenu);

                switch(submenu)
                {
                case 0:
                    printf("\n\nA voltar\n\n");
                    break;
                case 1:
                    printf("\n1sub\n");
                    break;
                case 2:
                    printf("\n2sub\n");
                    break;
                case 3:
                    printf("\n3sub\n");
                    break;
                case 4:
                    printf("\n4sub\n");
                    break;
                case 5:
                    printf("\n5sub\n");
                    break;
                default:
                    printf("\nOpcao invalida\n");
                }
            }
            while(submenu != 0);
            break;
        case 6:
            printf("\n6\n");
            break;
        case 7:
            printf("\n7\n");
            break;
        default:
            printf("\nOpcao invalida\n");
        }

    }
    while(opcao != 0);
}
