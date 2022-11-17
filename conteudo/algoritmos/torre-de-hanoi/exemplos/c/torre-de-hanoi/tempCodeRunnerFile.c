    while (stack_size(pino[2]) < num_discos)
    {
        // Determina o pino do menor disco.
        if (num_movimentos == 1)
            pino_menor_disco = 0;
        else
        {
            menor_disco = num_discos + 1;
            for (int i = 0; i < NUM_PINOS; i++)
            {
                if (!stack_isEmpty(pino[i]))
                {
                    if (stack_info(pino[i], 0) < menor_disco)
                    {
                        menor_disco = stack_info(pino[i], 0);
                        pino_menor_disco = i;
                    }
                }
            }
        }

        // Move o menor disco para o pino não utilizado recentemente.
        pino_destino = 2;
        if (pino_menor_disco == 2 || pino_recente == 2)
            pino_destino = 1;
        if (pino_menor_disco == 1 || pino_recente == 1)
            pino_destino = 0;
        moverDisco(&pino[pino_menor_disco], &pino[pino_destino]);
    }
