#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // para getch()
#include <ctype.h>

int rep();
int funcao_menu();
int main()
{
    int op = -1;
    do
    {
        system("cls");
        int menu = funcao_menu();
        switch (menu)
        {
        case 1:
            do
            {
            } while (rep());
            break;
        case 2:
            op = 0;
            return op;
        default:
            printf("\ndados invalidos.\npressione qualquer tecla para voltar ao menu...");
            getch();
        }

    } while (op != 0);
    return 0;
}
// funcao menu
int funcao_menu()
{
    int op;
    printf("selecione a opcao:\n");
    printf("1 - opcao.\n");
    printf("2 - sair.\n");

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
    if (op == 1)
        return 0;
    return op;
}