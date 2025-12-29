#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "functions.h"


void save_task_binary(Task t) {
    char nome_ficheiro[100];
    
    // Cria a pasta "tasks_data" no diretório superior se não existir 
    mkdir("../tasks_data", 0700);

    // O nome do ficheiro inclui o ID da tarefa 
    snprintf(nome_ficheiro, sizeof(nome_ficheiro), "../tasks_data/task_%d.bin", t.id);

    // Abre para escrita binária usando chamadas ao sistema 
    int fd = open(nome_ficheiro, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd < 0) {
        perror("Erro ao criar ficheiro da tarefa");
        return;
    }

    // Escreve a struct completa no ficheiro 
    if (write(fd, &t, sizeof(Task)) != sizeof(Task)) {
        perror("Erro ao escrever dados binários");
    }

    close(fd); 
    printf("Tarefa %d (Duração: %ds) guardada com sucesso em %s.\n", t.id, t.duration, nome_ficheiro);
}