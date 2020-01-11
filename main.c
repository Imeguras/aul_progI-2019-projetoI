#include <stdlib.h>
#include <stdio.h>
#include "ficheirosio.h"
#include "funcaux.h"
#include "funcaluno.h"
treino *listaTreino=NULL;
aluno *listaAluno=NULL;
pergunta *listaPergunta=NULL;
int sizeTreino, sizeAluno, sizePergunta;
int countTreino, countPergunta;
void menu();
int main(int argc, char const *argv[]){
    sizeTreino=loadTreino(listaTreino,&countTreino);
    sizeAluno=loadAluno(listaAluno);
    sizePergunta=loadPergunta(listaPergunta,countPergunta);
    menu();
    guardaTreino(listaTreino,sizeTreino, countTreino);
    guardaAluno(listaAluno,sizeAluno);
    guardaPergunta(listaPergunta,sizePergunta, countPergunta);
    free(listaTreino);
    free(listaPergunta);
    free(listaAluno);
    return 0;
}
void menu(){
    int opcao, submenu;
    do{
        printf("0 - Sair\n");
        printf("1 - Perguntas\n");
        printf("2 - Dados dos estudantes\n");
        printf("3 - Treinos\n");
        printf("4 - \n");
        printf("5 - \n");
        printf("6 - \n");
        printf("7 - \n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 0:
            printf("\n\tA sair do programa.\n");
            break;
        case 1:
            do{
                printf("0 - Voltar\n");
                printf("1 - Inserir\n");
                printf("2 - Consultar\n");
                printf("3 - Alterar\n");
                printf("4 - Listar\n");
                printf("Opcao: ");
                scanf("%d", &submenu);

                switch(submenu){
                    case 0:
                        printf("\n\nA voltar\n\n");
                        break;
                    case 1:
                        char enunciado[MAX_CHARACTERES_PERGUNTA_PERGUNTA];
                        resposta listaResposta[4];
                        lerString("Escreve o enunciado da pergunta: ",enunciado,MAX_CHARACTERES_PERGUNTA_PERGUNTA);
                        int respostacerta = lerInteiro("Escreve o id da resposta certa", 1, MAX_ID);    
                        int materia = lerInteiro("Escreve o id da resposta certa", 1, MAX_ID);    
                        int exame = lerInteiro("Escreve o id da resposta certa", 1, MAX_ID);    
                        int tipo = lerInteiro("Escreve o id da resposta certa", 1, MAX_ID);    

                        insPergunta(&sizePergunta,countPergunta,enunciado,listaResposta,respostacerta, materia, exame, tipo, listaPergunta);
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
            printf("\n5\n");
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