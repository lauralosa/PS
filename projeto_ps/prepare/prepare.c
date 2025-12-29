#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    // Valida o número de argumentos 
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <task_id> <duration>\n", argv[0]);
        return 1;
    }

    // Preenche a estrutura com os dados recebidos 
    Task t;
    t.id = atoi(argv[1]);
    t.duration = atoi(argv[2]);

    // Executa a função de gravação modular
    save_task_binary(t);

    return 0;
}