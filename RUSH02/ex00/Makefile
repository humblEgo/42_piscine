NAME = search_dict

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC = includes/ 
SRCS = srcs/search_dict_01.c srcs/search_dict_02.c srcs/string_util.c srcs/struct_util.c srcs/main.c srcs/parsing_dict_01.c srcs/parsing_dict_02.c srcs/dict_check.c
OBJS = srcs/search_dict_01.o srcs/search_dict_02.o srcs/string_util.o srcs/struct_util.o srcs/main.o srcs/parsing_dict_01.o srcs/parsing_dict_02.o srcs/dict_check.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
