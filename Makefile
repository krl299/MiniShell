SRCS	=	minishell.c signal.c utils.c init_data.c parse_data.c \
			parser.c cleaner.c parse_data_utils.c \
			builtins.c	pwd.c	echo.c	env.c

OBJS	=	${SRCS:.c=.o}

GCC		=	gcc -Wall -Werror -Wextra -g

RM		=	rm -rf

NAME	=	minishell

LIBFT_LIB	=	-I./libft

LIBFT_LINK	=	./libft/libft.a

RL_LIB	=	-I/Users/$(USER)/.brew/opt/readline/include

RL_LIB_LINK	=	-L/Users/$(USER)/.brew/opt/readline/lib -lreadline

.c.o:
		${GCC} -c $< ${RL_LIB} ${LIBFT} -o ${<:.c=.o}

all:	libft	$(NAME)

libft:	
		make -C libft

$(NAME):	${OBJS}
		${GCC} ${OBJS} ${RL_LIB_LINK} ${LIBFT_LINK} -o ${NAME}

clean:
		${RM} ${OBJS}
		make -C libft fclean

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all	clean	fclean	re	libft
