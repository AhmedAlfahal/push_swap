# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 19:14:21 by aalfahal          #+#    #+#              #
#    Updated: 2023/03/12 17:20:41 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

SRC	=	SRC/push_swap.c	\
		SRC/moves.c		\
		SRC/parsing.c	\
		SRC/clean_free.c\
		SRC/sort.c		\
		SRC/sort2.c		\
		SRC/sort3.c

SRCS	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRCS)
	@make all -C ./libft
	@make bonus -C ./libft
	@make all -C ./ft_printf
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)
clean:
	rm -fr $(SRCS)
	make clean -C ./ft_printf
	make clean -C ./libft

fclean: clean
	rm -fr $(NAME)
	make fclean -C ./ft_printf
	make fclean -C ./libft

re: fclean all