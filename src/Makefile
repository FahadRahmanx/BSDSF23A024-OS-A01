#Macros
CC = gcc
CFLAGS = -Wall -I../include -g
OBJ_DIR = ../obj
BIN_DIR = ../bin
TARGET = $(BIN_DIR)/client

SRC = mystrfunctions.c myfilefunctions.c main.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
