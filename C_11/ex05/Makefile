NAME = do-op

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC = includes/ 
SRCS = srcs/do_op.c srcs/ft_atoi.c 
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC)

test :
	$(info $(OBJS))

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
