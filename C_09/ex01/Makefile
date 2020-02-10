OBJECTS = ft.hㅑ
SRCS = srcs/ft_putchar.c srcs/ft_swap.c \
	   srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c 
OBJS = srcs/ft_putchar.o srcs/ft_swap.o \
	   srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
INC = includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar cr $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
