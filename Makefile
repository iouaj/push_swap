NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES =	push_swap.c \
		stack.c \
		movement.c \
		sort.c \
		utils.c \
		repush.c \
		test.c \
		target.c

PATH_FILES = srcs/

SRC = $(addprefix $(PATH_FILES), $(FILES))

OBJS = $(SRC:.c=.o)

INCLUDES = includes/push_swap.h

FT_PRINTF_PATH = srcs/ft_printf
FT_PRINTF = libftprintf.a

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_PATH)/$(FT_PRINTF) -I $(INCLUDES) -o $(NAME)

clean:
	make fclean -C $(FT_PRINTF_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re
