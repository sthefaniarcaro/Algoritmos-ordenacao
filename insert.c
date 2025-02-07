#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // para getch()
#include <ctype.h>

int rep();
int funcao_menu();
void insert(int *vet, int n);
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

                int v[100], n2;
                printf("digite o tamanho do vetor:");
                scanf("%d", &n2);

                printf("vetor gerado de forma aleatoria:");
                for (int i = 0; i < n2; i++)
                {
                    v[i] = rand() % 101;
                    printf("%d ", v[i]);
                }
                printf("\n");

                insert(v, n2);
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
// insert sort
void insert(int *vet, int n)
{
    int aux, j;
    for (int i = 1; i < n; i++)
    {
        aux = vet[i];
        for (j = i; (j > 0) && (aux < vet[j - 1]); j--)
        {
            vet[j] = vet[j - 1];
        }
        vet[j] = aux;
        for (int k = 0; k < n; k++)
        {
            printf("%d ", vet[k]);
        }
        printf("\n");
    }
}
// funcao menu
int funcao_menu()
{
    int op;
    printf("selecione a opcao:\n");
    printf("1 - insert sort.\n");
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