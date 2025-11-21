NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c parse.c list_ops.c operations.c small_sort.c

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(LIB) $(NAME)

$(LIB) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C libft

clean:
	rm -rf $(OBJS)
	make -C libft clean



re: fclean all

.PHONY: all clean fclean re
