#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // para getch()
#include <ctype.h>

int rep();
int funcao_menu();
void select(int *v, int n);
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
                srand(time(NULL));

                int v2[100], n3;
                printf("digite o tamanho do vetor:");
                scanf("%d", &n3);

                printf("vetor gerado de forma aleatoria:");
                for (int i = 0; i < n3; i++)
                {
                    v2[i] = rand() % 101;
                    printf("%d ", v2[i]);
                }
                printf("\n");

                select(v2, n3);
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
// selection sort
void select(int *v, int n)
{ // 20 12 28 05 10 18
    int menor, troca;
    for (int i = 0; i < n - 1; i++)
    {
        menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[menor])
                menor = j;
        }
        if (i != menor)
        {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;

            for (int k = 0; k < n; k++)
            {
                printf("%d ", v[k]);
            }
            printf("\n");
        }
    }
}
// funcao menu
int funcao_menu()
{
    int op;
    printf("selecione a opcao:\n");
    printf("1 - select sort.\n");
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