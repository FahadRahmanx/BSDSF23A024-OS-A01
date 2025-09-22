CC = gcc
CFLAGS = -Wall -I../include -g
OBJ_DIR = ../obj
BIN_DIR = ../bin
LIB_DIR = ../lib

TARGET_STATIC = $(BIN_DIR)/client_static
TARGET_DYNAMIC = $(BIN_DIR)/client_dynamic

LIB_STATIC = $(LIB_DIR)/libmyutils.a
LIB_DYNAMIC = $(LIB_DIR)/libmyutils.so

SRC_LIB = mystrfunctions.c myfilefunctions.c
SRC_MAIN = main.c

OBJ_LIB = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_LIB))
OBJ_MAIN = $(OBJ_DIR)/main.o

.PHONY: all static dynamic clean dirs

all: dirs static dynamic

dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)

# Static build
static: $(TARGET_STATIC)

$(LIB_STATIC): $(OBJ_LIB)
	ar rcs $@ $^

$(TARGET_STATIC): $(OBJ_MAIN) $(LIB_STATIC)
	$(CC) $(CFLAGS) $(OBJ_MAIN) $(LIB_STATIC) -o $@

# Dynamic build
dynamic: $(TARGET_DYNAMIC)

$(LIB_DYNAMIC): $(OBJ_LIB)
	$(CC) -fPIC -shared -o $@ $^

$(TARGET_DYNAMIC): $(OBJ_MAIN) $(LIB_DYNAMIC)
	$(CC) $(CFLAGS) $(OBJ_MAIN) -L$(LIB_DIR) -lmyutils -Wl,-rpath,'$$ORIGIN/../lib' -o $@

# Compile object files
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET_STATIC) $(TARGET_DYNAMIC) $(LIB_STATIC) $(LIB_DYNAMIC)
