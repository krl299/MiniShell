SRCS	=	minishell.c	

OBJS	=	${SRCS:.c=.o}

GCC		=	gcc -Wall -Werror -Wextra -g

RM		=	rm -rf

NAME	=	minishell

RL_LIB	=	-I/Users/$(USER)/.brew/opt/readline/include

RL_LIB_LINK	=	-L/Users/$(USER)/.brew/opt/readline/lib -lreadline

.c.o:
		${GCC} -c $< ${RL_LIB} -o ${SRCS:.c=.o}

all:	$(NAME)

$(NAME):	${OBJS}
		${GCC} ${OBJS} ${RL_LIB_LINK} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all	clean	fclean	re
