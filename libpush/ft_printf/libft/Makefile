NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_isdigit.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS)
	@ar rcs ${NAME} $(OBJS) $(BONUS)

clean:
	@rm -f $(OBJS) $(BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
