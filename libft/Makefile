NAME = libft.a
CC = cc
AR = ar
ARFLAGS = rcs

CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_isdigit.c ft_memmove.c ft_strlen.c \
ft_toupper.c ft_bzero.c   ft_isprint.c ft_memset.c \
ft_strncmp.c ft_isalnum.c ft_memchr.c  ft_strchr.c \
ft_strnstr.c ft_isalpha.c ft_memcmp.c  ft_strlcat.c \
ft_strrchr.c ft_isascii.c ft_memcpy.c  ft_strlcpy.c ft_tolower.c \
\
ft_calloc.c ft_strdup.c \
\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

#esc = \033
#GREEN= ${esc}[32m
#COLOR_RESET = ${esc}[0m

all: $(NAME)
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(GREEN)make all succesfully done!$(COLOR_RESET)"

bonus: $(BONUS_OBJ)
$(BONUS_OBJ): $(OBJ)
	${CC} ${CFLAGS} -c $(BONUS_SRC)
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJ) $(OBJ)
#@echo "$(GREEN)bonus succesful!$(COLOR_RESET)"

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
#@echo "$(GREEN)clean succesful!$(COLOR_RESET)"

fclean: clean
	rm -f $(NAME)
#@echo "$(GREEN)fclean succesful!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re