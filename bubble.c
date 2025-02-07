#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // para getch()
#include <ctype.h>

int rep();
int funcao_menu();
void bubble(int *vet, int n);
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
            op = 0;
            return op;
        default:
            printf("\ndados invalidos.\npressione qualquer tecla para voltar ao menu...");
            getch();
        }

    } while (op != 0);
    return 0;
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