NAME = ft_tail
SRCS = srcs/display_msg_util.c srcs/ft_tail.c srcs/string_util.c srcs/valid_util.c srcs/display_msg_util2.c
OBJS = $(SRCS:%.c=%.o)
INC = includes/

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean	all

