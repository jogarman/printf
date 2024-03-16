NAME = libftprintf.a
LIBFT = ./libft/libft.a
CC = gcc
ARFLAGS = -rcs

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
ft_dec_to_hex.c \
ft_putunsgnbr_fd.c \
ft_convertor.c \
ft_convertor2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar $(ARFLAGS) $(NAME) $(OBJ)

$(LIBFT):
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
