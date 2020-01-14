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
int ranking(aluno *vetor, int sizeAluno);
void respostas(int sizePergunta, resposta *listaResposta);
int main(int argc, char const *argv[]){
    listaAluno=loadAluno(listaAluno,&sizeAluno);
    listaPergunta=loadPergunta(listaPergunta,&sizePergunta,&countPergunta);
    listaTreino=loadTreino(listaTreino,&sizeTreino,&countTreino);
    menu();
    
    guardaTreino(listaTreino,sizeTreino, countTreino);
    guardaAluno(listaAluno,sizeAluno);
    guardaPergunta(listaPergunta,sizePergunta, countPergunta);
    free(listaTreino);
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
    int d;
    #pragma region NORMAL 
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
        printf("6 - Resetar os ficheiros\n");
        

        printf("Opcao: ");
        scanf("%c", &opcao);
        limpaBufferStdin();

        switch(opcao)
        {
        case '0':
            printf("\n\tA sair do programa.\n");
            break;
        #pragma endregion 
    #pragma region perguntas
        case '1':
            do
            {

               printf("\n0 - Voltar\n");
                printf("1 - Inserir\n");
                printf("2 - Alterar\n");
                printf("3 - Consultar\n");
                printf("4 - Listar\n");
                printf("5 - Eliminar\n");
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
                        respostas(countPergunta,listaResposta);
                        respostacerta = lerInteiro("Escreve o qual das respostas esta certa", 1, NUMERO_RESPOSTAS_PERGUNTA);
                        int idRespostaCerta = sizePergunta * 10 + respostacerta-1;
                        materia = lerInteiro("Escreve a materia", 1, MAX_ID);    
                        exame = lerInteiro("Escreve o exame", 1, NUMERO_PROVAS);   
                        insPergunta(&sizePergunta,countPergunta,(char *)enunciado,(resposta *)listaResposta,respostacerta, materia, exame, listaPergunta);
                        ++countPergunta;
                        break;
                    case '2':
                        
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
        #pragma endregion
        #pragma region aluno
        case '2':
            do{
                printf("\n0 - Voltar\n");
                printf("1 - Inserir\n");
                printf("2 - Alterar\n");
                printf("3 - Consultar\n");
                printf("4 - Listar\n");
                printf("5 - Apagar\n");
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
                        insAluno(sizeAluno,IDal, nome, regime,turno,listaAluno,0);
                        ++sizeAluno;
                        break;
                    case '2':
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
                            IDal=lerInteiro("\nInsere o ID novo do aluno", 1,MAX_ID);
                            lerString("\nInsere o nome novo do aluno\n", nome, 50);
                            regime= lerInteiro("Insere o novo regime: ",0,1);
                            lerString("Insere a nova turma do aluno\n", turno, 4);
                            insAluno(pos,IDal, nome, regime,turno,listaAluno,1);
                            
                        }
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
                        case '5':
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
                                printf("A apagar os registos de: %s",listaAluno[pos].nome);
                                insAluno(pos,0, "\0", 0,"\0",listaAluno,1);
                                --sizeAluno;
                            }
                        break;
                    default:
                        printf("\nOpcao invalida\n\n");
                }
            }while(submenu != '0');
            break;
            #pragma endregion
            #pragma region treino
        case '3':
            do{
                printf("\n0 - Voltar\n");
                printf("1 - Criar\n");
                printf("2 - Treinar\n");
                printf("3 - Listar\n");
                printf("4 - Consultar as perguntas e respostas dadas\n");
                printf("Opcao: ");
                scanf("%c", &submenu);
                limpaBufferStdin();

                switch(submenu){
                    case '0':
                        printf("\n\nA voltar\n\n");
                        break;
                    case '1':
                        IDal=lerInteiro("Qual e o aluno a realizar a prova?\n", 1,MAX_ID);
                        exame=lerInteiro("Qual e o exame a treinar?\n", 1,4);
                        regime =lerInteiro("Quantas perguntas e que queres no treino?\n", MIN_PERGUNTAS_TREINO,MAX_PERGUNTAS_TREINO);
                        listaTreino=criaTreino(countTreino,IDal,sizePergunta,exame,regime,listaTreino,listaPergunta);
                        countTreino++;
                        sizeTreino++;
                        break;
                    case '2':
                            lerString("Escreve um nome ou um id de um aluno\n",nome,50);
                            d=lerInteiro("Escreve o id do treino\n",1,sizeTreino);
                            d=procurTreino(d,sizeTreino,listaTreino);
                            //verifica se e um numero ou um nome
                            if(nome[0]>=48&&nome[0]<=57){
                                IDal=atoi(nome);
                                pos=procurAluno("",IDal,sizeAluno,listaAluno); 
                            }else{
                                pos=procurAluno(nome,-1,sizeAluno,listaAluno);
                            }
                            if(pos==-1||d==-1){
                                printf("Não existe nenhum aluno com tal id ou nome ou nao existe nenhum exame com esse id");
                            }else{
                            
                                fazTreino(&listaAluno[pos],&listaTreino[d]);
                               
                                
                            }
                        break;
                        case '3':
                            printaTreino(sizeTreino, listaTreino);
                            break;
                        case '4':
                             d=lerInteiro("Escreve o treino\n",1,sizeTreino);
                            procurTreino(d,sizeTreino,listaTreino);
                            printaPerguntas(sizePergunta, listaTreino[d].per);
                            for (size_t i = 0; i < MAX_PERGUNTAS_TREINO; i++)
                            {
                                
                                printf("ID da reposta dada a pergunta %d: %d\n",d,listaTreino[d].respostasDadas[i]);
                            }
                            
                            break;
                    default:
                        printf("\nOpcao invalida\n\n");
                }
            }while(submenu != '0');
            break;
            #pragma endregion
        case '4':
            printf("O aluno com mais certas é: ");
            printf("%d",ranking(listaAluno,sizeAluno));
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
                    lerString("Escreve um id\n",nome,50);
                    procurPergunta(enunciado, &IDal,-1,nome[0],-1,sizePergunta,listaPergunta);
                    if(pos==-1){
                        printf("Não existe nenhuma pergunta com tal id");
                    }else{
                        IDal= enunciado[0];
                        printf("Tempo media da resposta e:%0.1f", listaPergunta[IDal].tempoMedio);
                    }
                    break;
                case '2':
                   
                    
                    break;
                case '3':
                    /*for (size_t i = 0; i < sizeTreino; i++){
                        printf("%",);
                    }*/
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
            //apaga e carrega tudo de novo (hard reset)
            criaFichBinarioAluno();
            criaFichBinarioTreino();
            criaFichBinarioPergunta();
            listaAluno=loadAluno(listaAluno,&sizeAluno);
            listaPergunta=loadPergunta(listaPergunta,&sizePergunta,&countPergunta);
            listaTreino=loadTreino(listaTreino,&sizeTreino,&countTreino);
            break;
        
        default:
            printf("\nOpcao invalida\n\n");
        }

    }
    while(opcao != '0');
}
//@param SizePergunta-Determina o id pelo contador
void respostas(int sizePergunta, resposta *listaResposta){
    char resposta1[50],resposta2[50],resposta3[50],resposta4[50];
    lerString("Introduza a primeira resposta: ", resposta1, MAX_CHARACTERES_RESPOSTA_RESPOSTA);
    lerString("Introduza a segunda resposta: ", resposta2, MAX_CHARACTERES_RESPOSTA_RESPOSTA);
    lerString("Introduza a terceira resposta: ", resposta3, MAX_CHARACTERES_RESPOSTA_RESPOSTA);
    lerString("Introduza a quarta resposta: ", resposta4, MAX_CHARACTERES_RESPOSTA_RESPOSTA);
    strcpy(listaResposta[0].strresposta, resposta1);
    strcpy(listaResposta[1].strresposta, resposta2);
    strcpy(listaResposta[2].strresposta, resposta3);
    strcpy(listaResposta[3].strresposta, resposta4);
    listaResposta[0].id=sizePergunta * 10 + 0;
    listaResposta[1].id=sizePergunta * 10 + 1;
    listaResposta[2].id=sizePergunta * 10 + 2;
    listaResposta[3].id=sizePergunta * 10 + 3;
}
int ranking(aluno *vetor, int sizeAluno)
{
    int i,variavel, maior=0;
    for(i = 0; i < sizeAluno; i++){
        
        if(maior <= vetor[i].respostasCertas){
            maior = vetor[i].respostasCertas;
            variavel=vetor[i].id;
        }
        
    }
    return variavel;
}