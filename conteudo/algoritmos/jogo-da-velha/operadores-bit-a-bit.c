/*
    Título           : Jogo da Velha
    Descrição        : Aplicação dos "bitwise operators" no Jogo da Velha
    Desenvolvido por : Eduardo Ono
    Data             : 08/11/2021
    Atualizado em    : 08/11/2021
    OBS.             : Baseado em https://www.youtube.com/watch?v=t_PwaRMMnbo
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

char verificarJogada(char jogo[])
{
    // Ternas das possíveis vitórias em valores decimais
    int ternas[] = { 
        448, // 0b111000000 - primeira linha
        56,  // 0b000111000 - segunda linha
        7,   // 0b000000111 - terceira linha
        292, // 0b100100100 - primeira coluna
        146, // 0b010010010 - segunda coluna
        73,  // 0b001001001 - terceira coluna
        273, // 0b100010001 - diagonal principal
        84   // 0b001010100 - diagonal secundária
    };
    int i;
    int jogoDec = 0;
    char vencedor = ' ';

    // Converte o jogo do jogador atual (jogo[0]) para um número decimal (jogoDec)
    for (i = 1; i < 10; i++)
        if (jogo[i] == jogo[0])
            jogoDec += pow(2, 9-i);

    // Verifica o jogo do jogador atual através do operador bit-a-bit &
    for (i = 0; i < 8; i++)
        if ((jogoDec & ternas[i]) == ternas[i])
        {
            vencedor = jogo[0];
            break;
        }

    // Retorna ' ' caso a jogada não encontre uma terna (vencedor)
    return vencedor;
}

int imprimirTabuleiro(char jogo[])
{
    char horLine[] = { 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, '\0' };
    int i;

    // Imprime o tabuleiro com as jogadas
    for (i = 1; i < 10; i++)
    {
        printf(" %c ", jogo[i]);
            if (i < 9 && (i % 3 == 1 || i % 3 == 2))
            printf("%c", 179); // separador vertical
        if (i == 3 || i == 6)
            printf("\n%s\n", horLine);
    }
    printf("\n\n");

    // Imprime o binário correspondente ao jogo do último jogador 
    printf("Jogo '%c': ", jogo[0]);
    for (i = 1; i < 10; i++)
    {
        if (jogo[i] == jogo[0])
            printf("1");
        else
            printf("0");
    }
    printf("\n\n");

    return 0;
}

int main()
{
    char jogo[] = { 'X', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int i, jogada, numJogadas = 0;
    char vencedor = ' ';

    printf("Jogo da Velha\n");
    printf("=============\n\n");
    imprimirTabuleiro(jogo);
    for (i = 1; i < 10; i++)
        jogo[i] = ' ';
    do {
        printf("Jogador '%c': ", jogo[0]);
        scanf("%d", &jogada);

        // Validação da jogada
        while (jogada < 1 || jogada > 9 || jogo[jogada] != ' ')
        {
            printf("Jogada invalida!\n");
            printf("Jogador '%c': ", jogo[0]);
            scanf("%d", &jogada);
        }

        printf("\n");
        jogo[jogada] = jogo[0];
        numJogadas++;
        vencedor = verificarJogada(jogo);
        imprimirTabuleiro(jogo);
        jogo[0] = jogo[0] == 'X' ? 'O' : 'X';
    } while (vencedor == ' ' && numJogadas < 9);

    // Imprime o vencedor ou empate
    if (vencedor == ' ')
        printf("Empate!\n");
    else
        printf("O jogador '%c' venceu!\n", vencedor);
    printf("\n");

    return 0;
}
