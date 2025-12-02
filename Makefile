NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

SRC = main.c parse.c list_ops.c operations.c small_sort.c index.c radix_sort.c max_bits.c ctrl_atoi.c parse_utils.c
OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
