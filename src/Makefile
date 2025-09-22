CC = gcc
CFLAGS = -Wall -I../include -g
OBJ_DIR = ../obj
BIN_DIR = ../bin
LIB_DIR = ../lib

PREFIX = /usr/local
MANDIR = $(PREFIX)/share/man
BINDIR = $(PREFIX)/bin

TARGET_STATIC = $(BIN_DIR)/client_static
TARGET_DYNAMIC = $(BIN_DIR)/client_dynamic
TARGET = $(BIN_DIR)/client_dynamic

LIB_STATIC = $(LIB_DIR)/libmyutils.a
LIB_DYNAMIC = $(LIB_DIR)/libmyutils.so

SRC_LIB = mystrfunctions.c myfilefunctions.c
SRC_MAIN = main.c

OBJ_LIB = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_LIB))
OBJ_MAIN = $(OBJ_DIR)/main.o

.PHONY: all static dynamic clean dirs install

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
install: $(TARGET)

	install -d $(BINDIR)
	install -m 755 $(TARGET) $(BINDIR)/client

	install -d $(MANDIR)/man1
	install -m 644 ../man/man1/client.1 $(MANDIR)/man1/client.1

	install -d $(MANDIR)/man3
	install -m 644 ../man/man3/*.3 $(MANDIR)/man3/

uninstall:
	rm -f $(BINDIR)/client
	rm -f $(MANDIR)/man1/client.1
	rm -f $(MANDIR)/man3/mystrlen.3 \
	      $(MANDIR)/man3/mystrcpy.3 \
	      $(MANDIR)/man3/mystrncpy.3 \
	      $(MANDIR)/man3/mystrcat.3 \
	      $(MANDIR)/man3/wordCount.3 \
	      $(MANDIR)/man3/mygrep.3

