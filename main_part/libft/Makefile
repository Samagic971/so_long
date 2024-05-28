SRC			= ft_printf.c ft_printf_utils.c

SRC2_I		= get_next_line.c get_next_line_utils.c

SRC2		= ${addprefix get_next_line/, ${SRC2_I}}

DIR			= ./obj/

OBJ			= ${addprefix ${DIR}, ${SRC:c=o}}
OBJ2		= ${addprefix ${DIR}, ${SRC2:c=o}}

OBJS		= ${OBJ} ${OBJ2}

NAME		= libftprintf.a

AR			= ar rc

LIB			= ranlib

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${DIR}%.o: %.c
			@mkdir -p obj
			@mkdir -p obj/get_next_line
			@${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	libft ${OBJS}
			@${AR} ${NAME} ${OBJS}
			@${LIB} ${NAME}

libft:
			@make -C libft_first
			@cp libft_first/libft.a libftprintf.a

clean:
			@rm -f ${OBJS}
			@make -C libft_first clean

fclean:		clean
			@rm -f ${NAME}
			@make -C libft_first fclean

re:			fclean all

.PHONY:		all clean fclean re libft
