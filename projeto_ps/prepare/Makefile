# Variáveis de Compilação
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

# Pastas
SRC_DIR = src
INC_DIR = include
BIN_DIR = .

# Alvos (Executáveis)
TARGETS = prepare scheduler

# Regra padrão: compila tudo
all: $(TARGETS)

# Compilação do programa prepare
prepare: $(SRC_DIR)/prepare.c $(INC_DIR)/task.h
	$(CC) $(CFLAGS) $(SRC_DIR)/prepare.c -o $(BIN_DIR)/prepare

# Compilação do programa scheduler
scheduler: $(SRC_DIR)/scheduler.c $(INC_DIR)/task.h
	$(CC) $(CFLAGS) $(SRC_DIR)/scheduler.c -o $(BIN_DIR)/scheduler

# Limpeza de ficheiros temporários e executáveis
clean:
	rm -f $(BIN_DIR)/prepare $(BIN_DIR)/scheduler *.bin *.txt
	@echo "Limpeza concluída!"