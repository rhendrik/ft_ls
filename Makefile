NAME = ft_ls
LIB = libft/libft.a
SRC = src/main.c
FLAGS = gcc -Wall -Werror -Wextra
INCL = -I

.PHONY = clean fclean re lib

all: $(NAME)

$(NAME): lib
	$(FLAGS) $(INCL) $(SRC) $(LIB)

lib:
	$(FLAGS) $(INCL) -c libft/*.c
	ar rc $(LIB) *.o 
	make clean

clean:
	rm *.o

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all
