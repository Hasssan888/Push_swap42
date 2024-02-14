CC = cc 

FLAGC = -Wall -Wextra -Werror -g -fsanitize=address

NAME = push_swap

NAME_B = checker

SRC = push_swap.c link_list.c utilis.c sort_simple.c rules.c \
	condition.c sort_comple.c sort_arr.c push_to_stack_b.c \
	push_to_stack_a.c push_to_stack_b_100.c ft_split.c check_args.c \
	move.c push_to_stack_b_500.c push_stack_utilis.c move_2.c botom.c \
	move_3.c

SRC_BONUS = checker.c link_list.c utilis.c rules.c ft_split.c check_args.c \
    move_bonus_1.c move_bonus_2.c  move_bonus_3.c get_next_line.c get_next_line_utils.c \
	ft_strcmp.c

OBJE = ${SRC:.c=.o}

OBJE_bonus = ${SRC_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJE}
	${CC} ${FLAGC} -o ${NAME} ${OBJE}

bonus : ${NAME_B}

${NAME_B} : ${OBJE_bonus}
	${CC} ${FLAGC} -o ${NAME_B} ${OBJE_bonus}

%.o: %.c
	${CC} ${FLAGC} -c $< -o $@

clean :
	rm -f ${OBJE} ${OBJE_bonus}

fclean : clean
	rm -f $(NAME) ${NAME_B}

re: fclean all
