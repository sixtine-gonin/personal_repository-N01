/*
** EPITECH PROJECT, 2024
** hunter_test
** File description:
** main.c
*/

#include "../include/game.h"

void display_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./my_hunter\n\n", 13);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tDuck hunting game!\n", 19);
    write(1, "\tShoot the ducks with right click\n", 33);
    write(1, "\tYou have 5 lives and 60 seconds\n", 32);
}

int game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        handle_events(game);
        update_game(game);
        render_game(game);
    }
    destroy_game(game);
    return 0;
}

int main(int ac, char **av)
{
    game_t *game;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        display_help();
        return 0;
    }
    game = init_game();
    if (!game)
        return 84;
    srand(time(NULL));
    return game_loop(game);
}
