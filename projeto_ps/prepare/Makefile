# Variáveis de compilação
CC = gcc
CFLAGS = -Wall -Wextra -g

# Pasta
SRC_DIR = .
BIN_DIR = ..

# Alvo (executável)
TARGET = prepare_exec

all: $(TARGET)

# Compilação
$(TARGET): $(SRC_DIR)/prepare.c $(SRC_DIR)/task.h
	$(CC) $(CFLAGS) $(SRC_DIR)/prepare.c -o $(BIN_DIR)/$(TARGET)

# Limpeza
clean:
	rm -f $(BIN_DIR)/$(TARGET)
	@echo "Limpeza concluída!"
