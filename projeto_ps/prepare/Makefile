CC = gcc
CFLAGS = -Wall -Wextra -g

# Nome do executável final
TARGET = prepare

# Objetos necessários
OBJS = prepare.o functions.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

prepare.o: prepare.c functions.h
	$(CC) $(CFLAGS) -c prepare.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f *.o $(TARGET)
	@echo "Limpeza concluída!"