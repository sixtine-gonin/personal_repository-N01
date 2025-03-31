/*
** EPITECH PROJECT, 2024
** hunter_test
** File description:
** update.c
*/

#include "../include/game.h"

void update_duck_animation(sprite_t *duck)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(duck->anim_clock));

    if (time > 0.2f) {
        duck->rect.left += DUCK_WIDTH;
        if (duck->rect.left >= DUCK_WIDTH * 3)
            duck->rect.left = 0;
        sfSprite_setTextureRect(duck->sprite, duck->rect);
        sfClock_restart(duck->anim_clock);
    }
}

void update_duck_position(sprite_t *duck, float delta)
{
    duck->pos.x += duck->speed * delta;
    if (duck->pos.x > WINDOW_WIDTH) {
        duck->pos.x = -DUCK_WIDTH;
        duck->pos.y = rand() % (WINDOW_HEIGHT - DUCK_HEIGHT);
        duck->speed += 20.0f;
    }
    sfSprite_setPosition(duck->sprite, duck->pos);
}

void update_duck(sprite_t *duck, float delta)
{
    update_duck_animation(duck);
    update_duck_position(duck, delta);
}

void update_score(game_t *game)
{
    char score_str[32] = "Score: ";
    char time_str[32] = "Time: ";
    char lives_str[32] = "Lives: ";
    char temp[16];

    int_to_str(game->score, temp);
    my_strcat(score_str, temp);
    int_to_str((int)(GAME_DURATION - game->game_time), temp);
    my_strcat(time_str, temp);
    int_to_str(game->lives, temp);
    my_strcat(lives_str, temp);
    sfText_setString(game->score_text, score_str);
    sfText_setString(game->time_text, time_str);
    sfText_setString(game->lives_text, lives_str);
}

void update_game(game_t *game)
{
    float delta = sfTime_asSeconds(sfClock_restart(game->game_clock));

    if (game->state != PLAYING)
        return;
    game->game_time += delta;
    if (game->game_time >= GAME_DURATION)
        game->state = GAME_OVER;
    update_duck(game->duck, delta);
    update_score(game);
}
