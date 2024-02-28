NAME = libftprintf.a
CC = cc
ARFLAGS = rcs #le mete más flags

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
ft_dec_to_hex.c \
ft_putunsgnbr_fd.c \
ft_convertor.c

OBJ = $(SRC:.c=.o)

# añadir más archivos si hace falta

all: $(NAME)
$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	ar $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	@make clean -C libft
# ejecuta esto en esta direccion

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
