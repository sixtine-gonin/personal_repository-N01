/*
** EPITECH PROJECT, 2024
** hunter_test
** File description:
** render.c
*/

#include "../include/game.h"

void render_playing_state(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->duck->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    sfRenderWindow_drawText(game->window, game->time_text, NULL);
    sfRenderWindow_drawText(game->window, game->lives_text, NULL);
}

void render_gameover_state(game_t *game)
{
    char final_score[32] = "Final Score: ";
    char score_str[16] = {0};

    int_to_str(game->score, score_str);
    my_strcat(final_score, score_str);
    sfText_setString(game->score_text, final_score);
    sfText_setPosition(game->score_text,
        (sfVector2f){WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2});
    sfRenderWindow_drawSprite(game->window, game->gameover->sprite, NULL);
}

void render_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->background->sprite, NULL);
    if (game->state == PLAYING)
        render_playing_state(game);
    else if (game->state == GAME_OVER)
        render_gameover_state(game);
    sfRenderWindow_drawSprite(game->window, game->cursor->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void init_game_state(game_t *game)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

    game->window = sfRenderWindow_create(mode, "My Hunter",
        sfClose | sfResize, NULL);
    if (!game->window) {
        free(game);
        return;
    }
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    game->state = MENU;
    game->score = 0;
    game->lives = LIVES;
    game->game_time = 0;
    game->best_score = 0;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    init_game_state(game);
    init_game_objects(game);
    init_text(game);
    init_audio(game);
    return game;
}
