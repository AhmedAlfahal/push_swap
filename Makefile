# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 19:14:21 by aalfahal          #+#    #+#              #
#    Updated: 2023/02/24 17:23:45 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

SRC	=	push_swap.c	\
		moves.c		\
		parsing.c	\
		clean_free.c\
		sort.c		\
		sort2.c		\
		sort3.c

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