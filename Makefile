SRC =   ft_atoi.c ft_putstr_fd.c ft_split.c ft_strncmp.c parsing.c push_swap_free.c \
		push_swap_list.c push_swap_op_1.c  push_swap_op_2.c push_swap.c sorting.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC	= cc
INC = push_swap.h
all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c $(INC) 
	$(CC) -c $< -o $@ 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	
re : fclean all