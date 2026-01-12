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

all: $(NAME) $(NAMESV)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): client.o $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@ -L$(LIBFT_DIR) -lft

$(NAMESV): server.o $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@ -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAMESV) $(NAME)_bonus $(NAMESV)_bonus
	make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(NAME)_bonus.o -o $(NAME)_bonus -L$(LIBFT_DIR) -lft
	$(CC) $(CFLAGS) $(NAMESV)_bonus.o -o $(NAMESV)_bonus -L$(LIBFT_DIR) -lft

.PHONY: all bonus clean fclean re