
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rep();
int funcao_menu();
int main()
{
    do
    {
        system("cls");
        int menu;

        menu = funcao_menu();

        switch (menu)
        {
        case 0:
            exit(0);
            break;

        case 1:
            system("exercicio3.exe");
            break;
        case 2:
            system("bubble.exe");
            break;

        case 3:
            system("select.exe");
            break;
        case 4:
            system("insert.exe");
            break;
        case 5:
            system("gnome.exe");
            break;

        default:
            printf("dados invalidos!\n");
            break;
        }

    } while (rep());
    return 0;
}
// menu
int funcao_menu()
{
    int op;
    printf("LISTA 5 - RECURSIVIDADE\n\n");
    printf("selecione a opcao:\n");
    printf("0 - sair do programa.\n");
    printf("1 - exercicio 1.\n");
    printf("2 - bubble sort.\n");
    printf("3 - select sort.\n");
    printf("4 - insert sort.\n");
    printf("5 - gnome sort.\n");

    scanf("%d", &op);
    return op;
}
// reprocessamento
int rep()
{
    int op;
    printf("deseja voltar ao menu? (1 - sim || 2 - nao) ");
    scanf("%d", &op);
    while (op != 1 && op != 2)
    {
        printf("\ndados invalidos!\ndeseja voltar ao menu? (1 - sim || 2 - nao) ");
        scanf("%d", &op);
    }
    if (op == 2)
        return 0;
    return op;
}