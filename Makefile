OBJS = main.o handlers.o
SOURCE = main.c handlers.c
HEADER =
OUT = main
CC = gcc
FLAGS =    -Wall -Werror -Wextra
LFLAGS =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


main.o: main.c
	$(CC) $(FLAGS) main.c


fonctions.o: handlers.c
	$(CC) $(FLAGS) handlers.c


clean:
		rm -f $(OBJS)

fclean:
		rm -f $(OUT)

re:
		rm -f $(OUT) all