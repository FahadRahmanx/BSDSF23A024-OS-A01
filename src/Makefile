# Macros
CC = gcc
CFLAGS = -Wall -I../include -g
OBJ_DIR = ../obj
BIN_DIR = ../bin
LIB_DIR = ../lib
TARGET = $(BIN_DIR)/client_static
LIB = $(LIB_DIR)/libmyutils.a

SRC_LIB = mystrfunctions.c myfilefunctions.c
OBJ_LIB = $(addprefix $(OBJ_DIR)/, $(SRC_LIB:.c=.o))
SRC_MAIN = main.c
OBJ_MAIN = $(OBJ_DIR)/main.o

.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)

$(TARGET): $(OBJ_MAIN) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(LIB): $(OBJ_LIB)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET) $(LIB)
