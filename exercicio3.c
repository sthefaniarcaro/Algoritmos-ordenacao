/*3 Ordene o vetor v = [20, 12, 28, 05, 10, 18] usando o Método da Bolha (Bubble Sorte). Mostre
o vetor a cada iteração.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // para getch()
#include <ctype.h>
#include <time.h>

int rep();
int funcao_menu();
void bubble(int *vet, int n);
void insert(int *vet, int n);
void select(int *vet, int n);
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
                int vet[100], n;
                printf("digite a quantidade de elementos do vetor:");
                scanf("%d", &n);

                // vetor gerado de forma random
                printf("vetor gerado de forma aleatoria:\n\n");
                for (int i = 0; i < n; i++)
                {
                    vet[i] = rand() % 101;
                    printf("%d ", vet[i]);
                }
                printf("\n\n");
                bubble(vet, n);

            } while (rep());
            break;
        case 2:
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
        case 3:
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
        case 4:
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
// bubble sort
void bubble(int *vet, int n)
{
    int continua, aux, fim = n;
    printf("vetor organizado pelo bubble sort:\n");
    do
    {
        continua = 0;                     // sempre começa com 0 para verificar se há trocas a serem feitas
        for (int i = 0; i < fim - 1; i++) // n é o tamanho do vetor
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                continua = 1; // pois há interacao, se não tiver continua = 0 e o while termina

                for (int j = 0; j < n; j++) // exibir cada iteração
                {
                    printf("%d ", vet[j]);
                }
                printf("\n");
            }
        }
        fim--; // diminui o tamanho do vet pois a cada iteracao o maior valor irá para o final
    } while (continua != 0);
}
// funcao menu
int funcao_menu()
{
    int op;
    printf("selecione a opcao:\n");
    printf("1 - bubble sort.\n");
    printf("2 - insert sort.\n");
    printf("3 - selection sort.\n");
    printf("4 - sair.\n");

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