# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 17:59:17 by jmatas-p          #+#    #+#              #
#    Updated: 2023/05/11 17:19:37 by jmatas-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	GCC

FLAGS	= 	-Wall -Werror -Wextra -I libft.h

AR		=	ar crs

RM		=	rm -rf

FILES	= 	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_strlen \
	   		ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp \
	   		ft_strnstr ft_strlcpy ft_strlcat ft_atoi ft_strdup \
	   		ft_substr ft_strjoin ft_split ft_itoa ft_strmapi \
	   		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_isprint \
	   		ft_putnbr_fd ft_strtrim ft_memcpy ft_memmove ft_memset \
	   		ft_memcmp ft_memchr ft_bzero ft_calloc ft_striteri \
			ft_printf ft_printf_utils ft_printnbr_unsigned ft_printhex \
			ft_printptr get_next_line_bonus ft_swap ft_abs ft_strcmp \
			ft_atol ft_free_str_array get_next_line_utils_bonus

BFILES  = 	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
			ft_lstdelone ft_lstclear ft_lstiter ft_lstmap \

OBJ		=	$(FILES:=.o)

BOBJ	=	$(BFILES:=.o)

all: 		$(NAME)

bonus: 		all $(BOBJ)
			@$(AR) $(NAME) $(BOBJ)

$(NAME): 	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

%.o: 		%.c libft.h
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ) $(BOBJ)

fclean: 	clean
			@$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all bonus clean fclean re
