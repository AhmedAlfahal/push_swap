# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 23:54:55 by aalfahal          #+#    #+#              #
#    Updated: 2023/02/19 22:48:06 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

OBJ		=	ft_strdup.c		\
			ft_isdgt.c		\
			ft_strlen.c		\
			ft_strjoin.c	\
			ft_split.c		\
			ft_substr.c		\
			ft_isalnum.c
		

BOBJ	=	ft_lstnew.c				\
			ft_lstsize.c			\
			ft_lstlast.c			\
			ft_lstadd_back.c		\
			ft_lstadd_front.c		\
			ft_bfrlast.c
			
OBJS 	= $(OBJ:%.c=%.o)

BOBJS 	= $(BOBJ:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(BOBJS)
	ar rc $(NAME) $(BOBJS)

clean:
	rm -fr $(OBJS) $(BOBJS)

fclean: clean
	rm -fr $(NAME)

re: clean all
