NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES_LIBFT = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

SRC_LIBFT = $(addprefix libft/, $(FILES_LIBFT))

LIBFT = libft

SRC_PRINTF =	ft_printf \
				printf_hexa \
				printf_nb
SRC = $(addsuffix .c, $(SRC_PRINTF))
OBJ = $(addsuffix .o, $(SRC_PRINTF))

################################################################################################################
###RULES

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
