#include <stdio.h>
#include <stdlib.h>

#define Info int
#include "./stack.c"

void imprimirNo(No *, int);
void imprimirTorre(No **, const int, int);
void moverDisco(No **, No **);

int main()
{
    const int NUM_PINOS = 3;
    No *pino[] = { NULL, NULL, NULL };
    int num_discos = 3;
    int menor_disco;
    int pino_menor_disco = 0;
    int num_movimentos = 0;
    int pino_recente, pino_destino;

    printf("\n--- TORRE DE HANOI ---\n\n");

    for (int i = num_discos; i > 0; i--)
        stack_push(&pino[0], i);
    imprimirTorre(pino, NUM_PINOS, num_discos);

    // Primeiro movimento.
    pino_destino = (num_discos % 2 == 1) ? 2 : 1;
    moverDisco(&pino[0], &pino[pino_destino]);
    pino_recente = pino_destino;
    imprimirTorre(pino, NUM_PINOS, num_discos);

    while (stack_size(pino[2]) < num_discos)
    {
        // Determina o pino do menor disco que não seja o último movido.
        menor_disco = num_discos + 1;
        for (int i = 0; i < NUM_PINOS; i++)
        {
            if (i != pino_recente && !stack_isEmpty(pino[i]))
            {
                if (stack_info(pino[i], 0) < menor_disco)
                {
                    menor_disco = stack_info(pino[i], 0);
                    pino_menor_disco = i;
                }
            }
        }
        printf("Pino do menor disco: %d\n", pino_menor_disco);
        getchar();

        // Move o menor disco para o pino não utilizado recentemente.
        if (pino_menor_disco == 0)
            pino_destino = (pino_recente == 1) ? 2 : 1;
        if (pino_menor_disco == 1)
            pino_destino = (pino_recente == 0) ? 2 : 0;
        if (pino_menor_disco == 2)
            pino_destino = (pino_recente == 0) ? 1 : 0;
        printf("Pino destino: %d\n", pino_destino);
        getchar();
        moverDisco(&pino[pino_menor_disco], &pino[pino_destino]);
        pino_recente = pino_destino;

        imprimirTorre(pino, NUM_PINOS, num_discos);

    }
    
    return 0;
}

void imprimirNo(No *pilha, int nivel)
{
    int tamanho_pilha = stack_size(pilha);

    if (tamanho_pilha < nivel)
        printf("  |  ");
    else
        printf(" (%d) ", stack_info(pilha, tamanho_pilha - nivel));
}

void imprimirTorre(No *pilhas[], const int N, int num_discos)
{
    int i;

    for (i = 3; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
            imprimirNo(pilhas[j], i);
        printf("\n");
    }

    for (int i = 0; i < 15; i++)
        printf("%c", 223);
    printf("\n\n");
}

void moverDisco(No **pOrigem, No **pDestino)
{
    int disco;

    disco = stack_pop(pOrigem);
    stack_push(pDestino, disco);
}
