CC=gcc

FLAGS=-Wall -Wextra -Werror

SRC=ft_bzero.c\
	ft_putstr.c\
	ft_strchr.c\
	ft_strcpy.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strndup.c\
	get_next_line.c\
	list.c\
	main.c\
	ft_putnbr.c\
	ft_putchar.c

OBJ_NAME=$(SRC:.c=.o)

NAME=gnl

all:$(NAME)

$(NAME):$(OBJ_NAME)
	$(CC) $(FLAGS) $^ -o $@

$(OBJ_NAME):$(SRC)
	@$(CC) $(FLAGS) -c $^

re:fclean all

c:all
	make clean
clean:
	@rm -rf *.o

fclean:clean
	@rm  -rf $(NAME)
