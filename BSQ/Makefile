# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 19:41:15 by sanam             #+#    #+#              #
#    Updated: 2020/02/12 22:25:25 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	BSQ	
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	srcs/bsq.c \
			srcs/ft_basic_print.c \
			srcs/ft_basic_utility.c \
			srcs/ft_malloc_free.c \
			srcs/ft_read_map.c \
			srcs/ft_read_stdin.c \
			srcs/ft_valid_check1.c \
			srcs/ft_valid_check2.c \
			srcs/main.c

OBJS	=	$(SRCS:%.c=%.o)
INC		=	includes/

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o		:	%.c
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)
	
clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all
