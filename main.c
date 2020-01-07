#include <stdlib.h>
#include <stdio.h>
#include "ficheirosio.h"
#include "funcaux.h"
#include "funcaluno.h"

int menu()
{
    int opcao, submenu;
    do
    {
        printf("Escolha 0\n");
        printf("Escolha 1\n");
        printf("Escolha 2\n");
        printf("Escolha 3\n");
        printf("Escolha 4\n");
        printf("Escolha 5\n");
        printf("Escolha 6\n");
        printf("Escolha 7\n");

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
                printf("2. Escolha 0\n");
                printf("2. Escolha 1\n");
                printf("2. Escolha 2\n");
                printf("2. Escolha 3\n");

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
                default:
                    printf("\nOpcao invalida\n");
                }
            }
            while(submenu != 0);
            break;
        case 2:
            printf("\n2\n");
            break;
        case 3:
            printf("\n3\n");
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
int main(int argc, char const *argv[])
{
    
    return 0;
}
