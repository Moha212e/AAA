# Variables
CC = gcc
CFLAGS = -Wall -g
OBJ_DIR = .
SRC_DIR = .
BIN = TCPServer TCPClient

# Fichiers source et objets
SRCS_SERVER = $(SRC_DIR)/HandleTCPClient.c $(SRC_DIR)/LibSer.c $(SRC_DIR)/LibSerHV.c $(SRC_DIR)/TCPEchoServer.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = $(SRC_DIR)/TCPEchoClient.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Cibles principales
all: $(BIN)

# Serveur
TCPServer: $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

# Client
TCPClient: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)

# Nettoyage complet
mrproper: clean
	rm -f $(BIN)
  