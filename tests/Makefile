##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## test
##

CC          = gcc

SRC         = test.c

OBJ         = $(SRC:.c=.o)

NAME        = unit_tests

CFLAGS      = --coverage -Wall -Wextra -I./include

LDLIBS      = -lcriterion -lgcov

all: fclean $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(CFLAGS)

tests_run: $(NAME)
	./$(NAME)

coverage:
	@gcovr

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re tests_run
