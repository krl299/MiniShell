SRCS	=	./src/minishell.c			./src/signal.c				./src/utils.c			\
			./src/parser/init_data.c	./src/parser/parse_data.c	./src/parser/parser.c	\
			./src/parser/cleaner.c		./src/parser/parser_fixer.c \
			./src/builtins/builtins.c	./src/builtins/pwd.c		./src/builtins/echo.c	\
			./src/builtins/env.c		./src/builtins/unset.c		./src/builtins/export.c 

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
