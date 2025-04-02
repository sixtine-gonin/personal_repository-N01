##
## EPITECH PROJECT, 2025
## hunter_testt
## File description:
## makefile
##

SRC     =       src/init.c \
                src/update.c \
                src/event.c \
                src/render.c \
                src/cleanup.c \
                src/my_revstr.c \
                src/main.c

OBJ     =       $(SRC:.c=.o)

NAME    =       my_hunter

CFLAGS  =       -Wall -Wextra -I./include

LDFLAGS =       -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:    $(NAME)

$(NAME):        $(OBJ)
	gcc $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

tests_run:
	make -C tests tests_run

re:     fclean all

.PHONY: all clean fclean re
