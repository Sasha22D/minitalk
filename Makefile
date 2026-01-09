NAME = client
NAMESV = server

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Werror -Wextra -Wall

SRC_FILES = client.c server.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

BONUS_FILES = client_bonus.c server_bonus.c
BONUS_OBJ = $(BONUS_FILES:%.c=%.o)

all:

$(NAME): client.o
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBFT_DIR) -lft

$(NAMESV): server.o
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAMESV)
	make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(NAME) $(NAMESV) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(NAME).o -o $(NAME) -L$(LIBFT_DIR) -lft
	$(CC) $(CFLAGS) $(NAMESV).o -o $(NAMESV) -L$(LIBFT_DIR) -lft

.PHONY: all bonus clean fclean re