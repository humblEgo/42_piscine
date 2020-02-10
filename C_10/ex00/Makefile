NAME = ft_display_file
SRCDIR = srcs/
SOURCES = ft_display_file.c
SRCS = $(SRCDIR)$(SOURCES)
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

