NAME = libftprintf.a
CC = cc
ARFLAGS = rcs #le mete más flags

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
ft_dec_to_hex.c \
ft_putunsgnbr_fd.c \
ft_convertor.c \
ft_convertor2.c \
ft_strlen.c \
ft_putnbr_fd.c \
ft_putchar_fd.c

OBJ = $(SRC:.c=.o)

# añadir más archivos si hace falta

all: $(NAME)
$(NAME): $(OBJ)
	ar $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
# ejecuta esto en esta direccion

fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
