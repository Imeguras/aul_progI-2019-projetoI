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
    criaFichBinarioAluno();
    criaFichBinarioTreino();
    criaFichBinarioPergunta();
    //sizeTreino=loadTreino(listaTreino,&countTreino);
    listaAluno=loadAluno(listaAluno,&sizeAluno);
    listaPergunta=loadPergunta(listaPergunta,&sizePergunta,&countPergunta);
    menu();
    //guardaTreino(listaTreino,sizeTreino, countTreino);
    guardaAluno(listaAluno,sizeAluno);
    guardaPergunta(listaPergunta,sizePergunta, countPergunta);
    //free(listaTreino);
    free(listaPergunta);
    free(listaAluno);
    return 0;
}
//48-57
void menu(){
    char opcao, submenu;
    char enunciado[MAX_CHARACTERES_PERGUNTA_PERGUNTA];
    int materia;
    int exame;
    resposta listaResposta[4];
    int respostacerta;
    int pos;
    int IDal;
    char nome[MAX_CHARACTERES_NOME_ALUNO];
    int regime;
    char turno[4]; 
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
        scanf("%c", &opcao);
        limpaBufferStdin();

        switch(opcao)
        {
        case '0':
            printf("\n\tA sair do programa.\n");
            break;
        case '1':
            do
            {

               printf("\n0 - Voltar\n");
                printf("1 - Inserir\n");
                printf("2 - Consultar\n");
                printf("3 - Alterar\n");
                printf("4 - Listar\n");
                printf("Opcao: ");
                scanf("%c", &submenu);
                limpaBufferStdin();

                switch(submenu)
                {
                case '0':
                    printf("\n\nA voltar\n\n");
                    break;

                    case '1':

                        
                        lerString("Escreve o enunciado da pergunta: ",enunciado,MAX_CHARACTERES_PERGUNTA_PERGUNTA);
                        respostacerta=lerInteiro("Escreve o id da resposta certa", 1, MAX_ID);    
                        materia = lerInteiro("Escreve a materia", 1, MAX_ID);    
                        exame = lerInteiro("Escreve o exame", 1, MAX_ID);    
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
                        insPergunta(&sizePergunta,++countPergunta,(char *)enunciado,(resposta *)listaResposta,respostacerta, materia, exame, listaPergunta);
                        
                        //insPergunta(&sizePergunta,0,"0",listaResposta, 0,0,0,0,listaPergunta);
                        break;
                    case '2':
                        printf("\n2sub\n");
                        break;
                    case '3':
                        printf("\n3sub\n");
                        break;
                    case '4':
                        printaPerguntas(sizePergunta, listaPergunta);
                        break;
                    default:
                        printf("\nOpcao invalida\n\n");
                }
            }while(submenu != '0');
            break;
        case '2':
            do{
                printf("\n0 - Voltar\n");
                printf("1 - Inserir\n");
                printf("2 - Alterar\n");
                printf("3 - Consultar\n");
                printf("4 - Listar\n");
                printf("Opcao: ");
                scanf("%c", &submenu);
                limpaBufferStdin();

                switch(submenu){
                    case '0':
                        printf("\n\nA voltar\n\n");
                        break;
                    case '1':
                        IDal=lerInteiro("\nInsere o ID do aluno", 1,MAX_ID);
                        lerString("\nInsere o nome do aluno\n", nome, 50);
                        regime= lerInteiro("Insere o regime: ",0,1);
                        lerString("Insere a turma do aluno\n", turno, 4);
                        insAluno(sizeAluno,IDal, nome, regime,turno,listaAluno);
                        ++sizeAluno;
                        break;
                    case '2':
                        printf("\n2sub\n");
                        break;
                    case '3':
                        //nome usado para nao haver tantas strings inicializadasd
                        lerString("Escreve um nome ou um id\n",nome,50);
                        
                        if(nome[0]>=48&&nome[0]<=57){
                            
                            IDal=atoi(nome);
                            
                            pos=procurAluno("",IDal,sizeAluno,listaAluno);
                                      
                        }else{
                            pos=procurAluno(nome,-1,sizeAluno,listaAluno);
                        }
                        if(pos==-1){
                            printf("Não existe nenhum aluno com tal id ou nome");
                        }else{
                            printaAlunos(1,&listaAluno[pos]);
                        }

                        break;
                        case '4':
                            printaAlunos(sizeAluno, listaAluno);
                        break;
                    default:
                        printf("\nOpcao invalida\n\n");
                }
            }while(submenu != '0');
            break;
        case '3':
            do{
                printf("\n0 - Voltar\n");
                printf("1 - Consultar\n");
                printf("2 - Listar\n");
                printf("Opcao: ");
                scanf("%c", &submenu);
                limpaBufferStdin();

                switch(submenu){
                    case '0':
                        printf("\n\nA voltar\n\n");
                        break;
                    case '1':
                        printf("\n1sub\n");
                        break;
                    case '2':
                        printf("\n2sub\n");
                        break;
                    default:
                        printf("\nOpcao invalida\n\n");
                }
            }while(submenu != '0');
            break;
        case '4':
            printf("\n4\n\n");
            break;
        case '5':
            do
            {
                printf("\n0 - Voltar\n");
                printf("1 - O tempo medio de resposta a uma pergunta\n");
                printf("2 - Quantidade de treinos realizados entre duas datas\n");
                printf("3 - Percentagem de treinos efetuados por cada prova\n");
                printf("4 - Pergunta com a maior quantidade de respostas erradas\n");
                printf("5 - Tipo de perguntas com a menor percentagem de respostas corretas\n");
                printf("Opcao: ");
                scanf("%c", &submenu);
                limpaBufferStdin();

                switch(submenu)
                {
                case '0':
                    printf("\n\nA voltar\n\n");
                    break;
                case '1':
                    printf("\n1sub\n");
                    break;
                case '2':
                    printf("\n2sub\n");
                    break;
                case '3':
                    printf("\n3sub\n");
                    break;
                case '4':
                    printf("\n4sub\n");
                    break;
                case '5':
                    printf("\n5sub\n");
                    break;
                default:
                    printf("\nOpcao invalida\n\n");
                }
            }
            while(submenu != '0');
            break;
        case '6':
            printf("\n6\n\n");
            break;
        case '7':
            printf("\n7\n\n");
            break;
        default:
            printf("\nOpcao invalida\n\n");
        }

    }
    while(opcao != '0');
}
