NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

FILES =	pile \
		action \
		push_swap \
		lowerfirst

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

FILES_LIB = libpush/ft_atoi \
			libpush/ft_putendl_fd

SRC_LIB = $(addsuffix .c, $(FILES_LIB))
OBJ_LIB = $(addsuffix .o, $(FILES_LIB))

FT_PRINTF = libpush/ft_printf/
LIB = libpush.a
INCLUDES = push_swap.h

all: $(NAME)

$(LIB) : $(OBJ_LIB)
	@make -C $(FT_PRINTF)
	@cp $(FT_PRINTF)/libftprintf.a .
	@mv libftprintf.a $(LIB)
	@ar rc $(LIB) $(OBJ_LIB)

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -I $(INCLUDES) -o $(NAME)

clean :
	@rm -f $(OBJ)
	@rm -f $(OBJ_LIB)
	@rm -f $(LIB)
	@make fclean -C $(FT_PRINTF)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
