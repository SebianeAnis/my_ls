CC = gcc
NAME = my_ls
SRC = my_ls.c
RM = rm -f
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
$(NAME) : $(OBJ)
$(CC) : $(SRC) -o $(NAME)
all : $(NAME)
clean :
        $(RM) : $(NAME)
fclean:
        $(RM) : $(OBJ)
re : fclean all