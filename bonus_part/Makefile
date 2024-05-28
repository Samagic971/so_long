SRC			= so_long.c \
				create_array.c verif_array.c parse_grid.c \
				utils.c \
				graphics.c hook_events.c graphics_bis.c update_win.c \
				cow_end.c

DIR			= obj/
DIR2		= ./main_part/

OBJS		= ${addprefix ${DIR}, ${SRC:.c=.o}}

NAME		= so_long.a

AR			= ar rc

LIB			= ranlib

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}
			@${GCC} ${CFLAGS} so_long.c ${NAME} -o so_long_bonus -L. -lmlx
			@mv so_long_bonus ../

${DIR}%.o: %.c
			@${GCC} ${CFLAGS} -Ilmx -c $< -o $@

${NAME}:	libft ${OBJS}
			@${AR} ${NAME} ${OBJS}
			@${LIB} ${NAME}

libft:
			@mkdir -p obj
			@make -C libft
			@cp libft/libftprintf.a ${NAME}

clean:
			@rm -f ${OBJS}
			@make -C libft clean

fclean:		clean
			@rm -f ${NAME}
			@rm -f ../so_long_bonus
			@make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re libft
