/*
    Título           : Jogo da Velha
    Descrição        : Aplicação dos "bitwise operators" no Jogo da Velha
    Desenvolvido por : Eduardo Ono
    Data             : 08/11/2021
    Atualizado em    : 16/11/2021
    OBS.             : Baseado em https://www.youtube.com/watch?v=t_PwaRMMnbo
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* dec2bin(int num)
{
    int size = 10; // 9 + '\0'
    char *bin = NULL;
    int i;

    bin = (char*)malloc(size * sizeof (char));
    for (i = size-2; i >= 0; i--)
        bin[size-i-2] = ((num >> i) & 1) ? '1' : '0';
    bin[9] = '\0';

    return bin;
}

void analisarJogo(char jogo[], int ternas[])
{
    int i, jogoDec = 0;
    int terna, resultado;
    char *bin, *jogoBin, *ternaBin;

    // Converte o jogo do jogador atual (jogo[0]) em um número decimal
    for (i = 1; i < 10; i++)
        if (jogo[i] == jogo[0])
            jogoDec += pow(2, 9-i);
    printf("Analise do jogo do jogador '%c': %s\n", jogo[0], dec2bin(jogoDec));

    // Verificação em decimal
    for (i = 0; i < 8; i++)
    {
        terna = ternas[i];
        resultado = (jogoDec & terna);
        printf("(%3d & %3d) == %3d", jogoDec, terna, terna);

        // Em binário
        jogoBin = dec2bin(jogoDec);
        ternaBin = dec2bin(terna);
        bin = dec2bin(resultado);
        printf("  =>  ((%s & %s) == %s)", jogoBin, ternaBin, ternaBin);
        printf("  =>  %s == %s  =>  %c\n", bin, ternaBin, (resultado == terna ? 'V': 'F'));
    }
    free(jogoBin);
    free(ternaBin);
    free(bin);
    printf("\n");
}

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
    int i, jogoDec = 0;
    char vencedor = ' ';

    // Converte o jogo do jogador atual para um número decimal (jogoDec)
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

    // APENAS PARA FINS DIDÁTICOS
    analisarJogo(jogo, ternas);

    // Retorna ' ' caso a jogada não encontre uma terna (vencedor)
    return vencedor;
}

int imprimirTabuleiro(char jogo[])
{
    // Código ASCII para o desenho do tabuleiro
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
        printf("%d", jogo[i] == jogo[0] ? 1 : 0);
    printf("\n\n");

    return 0;
}

int main()
{
    char jogo[] = { 'X', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int jogoX = 0, jogoY = 0;
    int i, pos, numJogadas = 0;
    char vencedor = ' ';

    printf("Jogo da Velha\n");
    printf("=============\n\n");
    imprimirTabuleiro(jogo);

    // Substitui as posições das jogadas por espaços em branco
    for (i = 1; i < 10; i++)
        jogo[i] = ' ';
    
    do {
        printf("Jogador '%c': ", jogo[0]);
        scanf("%d", &pos);

        // Validação da jogada
        while (pos < 1 || pos > 9 || jogo[pos] != ' ')
        {
            printf("Jogada invalida!\n");
            printf("Jogador '%c': ", jogo[0]);
            scanf("%d", &pos);
        }

        printf("\n");
        jogo[pos] = jogo[0];
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
