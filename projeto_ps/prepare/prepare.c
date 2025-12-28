#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    // Para open()
#include <unistd.h>   // Para write() e close()
#include "../prepare/task.h"

int main(int argc, char *argv[]) {
    // 1. Validar se temos os 3 argumentos: ./prepare <id> <duration>
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <task_id> <duration>\n", argv[0]);
        return 1;
    }

    // 2. Criar e preencher a estrutura [cite: 24]
    Task t;
    t.id = atoi(argv[1]);
    t.duration = atoi(argv[2]);

    

    // 3. Criar o caminho do ficheiro dentro da pasta 'data'
    char filepath[64];
    // Colocamos o prefixo "data/" antes do nome do ficheiro
    sprintf(filepath, "tasks_data/task_%d.bin", t.id); 

    // 4. Gravar a usar System Calls
    int fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Erro ao abrir ficheiro (certifica-te que a pasta 'tasks_data' existe)");
        return 1;
    }



    // Escrevemos o bloco de memória da struct inteira no ficheiro 
    if (write(fd, &t, sizeof(Task)) == -1) {
        perror("Erro ao escrever");
        close(fd);
        return 1;
    }

    close(fd);
    printf("Tarefa %d guardada com sucesso em %s\n", t.id, filepath);
    return 0;
}