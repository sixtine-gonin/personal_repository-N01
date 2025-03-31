/*
** EPITECH PROJECT, 2024
** hunter_test
** File description:
** event.c
*/

#include "../include/game.h"

void handle_menu_click(game_t *game)
{
    game->state = PLAYING;
    game->score = 0;
    game->lives = LIVES;
    game->game_time = 0;
    game->duck->speed = DUCK_SPEED;
}

void handle_playing_click(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect duck_bounds = sfSprite_getGlobalBounds(game->duck->sprite);

    if (sfFloatRect_contains(&duck_bounds, mouse.x, mouse.y)) {
        game->score += 10;
        game->duck->pos.x = -DUCK_WIDTH;
        game->duck->pos.y = rand() % (WINDOW_HEIGHT - DUCK_HEIGHT);
        sfSound_play(game->duck_sound);
    } else {
        game->lives--;
        if (game->lives <= 0)
            game->state = GAME_OVER;
    }
}

void handle_gameover_click(game_t *game)
{
    if (game->score > game->best_score)
        game->best_score = game->score;
    game->state = MENU;
}

void handle_click(game_t *game)
{
    switch (game->state) {
        case MENU:
            handle_menu_click(game);
            break;
        case PLAYING:
            handle_playing_click(game);
            break;
        case GAME_OVER:
            handle_gameover_click(game);
            break;
    }
}

void handle_events(game_t *game)
{
    sfEvent event;
    sfVector2i mouse;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonPressed)
            handle_click(game);
    }
    mouse = sfMouse_getPositionRenderWindow(game->window);
    sfSprite_setPosition(game->cursor->sprite,
        (sfVector2f){mouse.x - 16, mouse.y - 16});
}
