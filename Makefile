##
## EPITECH PROJECT, 2022
## mysh
## File description:
## makefile for mysh project
##

NAME	=	42sh

SRC = $(shell find ./src -type f \( -iname "*.c" ! -iname "main.c" \))
OBJ	= $(SRC:.c=.o)

TESTS	=	$(shell find ./tests -type f -name "*.c" )
TESTSOBJ	=	$(TESTS:.c=.o)

CC	=	gcc
LDFLAGS = -L./lib/ -lmy
CFLAGS	= -I./include/ -W -Wall -Wextra
TFLAGS	= -lcriterion --coverage

all:	make_lib $(NAME)

$(NAME):	compile_main $(OBJ)
	$(CC) -o $(NAME) $(OBJ) ./src/main.o $(LDFLAGS) $(CFLAGS)

debug:	compile_main
	$(CC) -o $(NAME) $(SRC) ./src/main.o $(LDFLAGS) $(CFLAGS) -g

compile_main: make_lib
	$(CC) -c -o ./src/main.o ./src/main.c $(LDFLAGS) $(CFLAGS)

tests_run: make_lib $(NAME) $(TESTSOBJ) $(OBJ)
	$(CC) -o test_$(NAME) $(SRC) $(TESTS) $(LDFLAGS) $(CFLAGS) $(TFLAGS)
	./test_${NAME}
	gcovr --exclude tests

clean:
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(OBJ) ./src/main.o
	rm -f $(TESTSOBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f test_$(NAME)
	make fclean -C lib/my

re:	fclean all

make_lib:
	make -C lib/my
