CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC_CLIENT = src/client.c
SRC_SERVER = src/server.c

CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(SRC_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SRC_CLIENT) -L$(LIBFT_PATH) -lft

$(SERVER): $(SERVER_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SRC_SERVER) -L$(LIBFT_PATH) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re 