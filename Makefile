SRC_DIR = mandatory
SRC_B_DIR = bonus
SRC_B = $(SRC_B_DIR)/checker_bonus.c  $(SRC_B_DIR)/ft_atoi_bonus.c $(SRC_B_DIR)/ft_putstr_fd_bonus.c $(SRC_B_DIR)/ft_split_bonus.c \
		$(SRC_B_DIR)/ft_strncmp_bonus.c $(SRC_B_DIR)/get_next_line_bonus.c $(SRC_B_DIR)/get_next_line_utils_bonus.c $(SRC_B_DIR)/parsing_bonus.c \
		$(SRC_B_DIR)/push_swap_free_bonus.c $(SRC_B_DIR)/push_swap_list_bonus.c \
		$(SRC_B_DIR)/push_swap_op_1_bonus.c \
		$(SRC_B_DIR)/push_swap_op_2_bonus.c

SRC =   $(SRC_DIR)/ft_atoi.c  $(SRC_DIR)/ft_putstr_fd.c  $(SRC_DIR)/ft_split.c  $(SRC_DIR)/parsing.c  $(SRC_DIR)/push_swap_free.c \
		 $(SRC_DIR)/push_swap_list.c  $(SRC_DIR)/push_swap_op_1.c  $(SRC_DIR)/push_swap_op_2.c $(SRC_DIR)/push_swap.c  $(SRC_DIR)/sorting.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(SRC_B:.c=.o)
NAME = push_swap
NAME_CH = checker
CFLAGS = -Wall -Wextra -Werror
CC	= cc
INC = mandatory/push_swap.h
INC_B = bonus/checker_bonus.h

all : $(NAME)

bonus :$(NAME_CH)


$(NAME_CH) : $(B_OBJ) $(INC_B)
		$(CC) $(CFLAGS) $(B_OBJ) -o $@

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c $(INC) 
	$(CC) -c $< -o $@ 

clean :
	rm -f $(OBJ) $(B_OBJ)

fclean : clean
	rm -f $(NAME)
	
re : fclean all