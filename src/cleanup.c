/*
** EPITECH PROJECT, 2024
** hunter_test
** File description:
** cleanup.c
*/

#include "../include/game.h"

void destroy_sprite(sprite_t *sprite)
{
    if (!sprite)
        return;
    if (sprite->sprite)
        sfSprite_destroy(sprite->sprite);
    if (sprite->texture)
        sfTexture_destroy(sprite->texture);
    if (sprite->anim_clock)
        sfClock_destroy(sprite->anim_clock);
    free(sprite);
}

void destroy_game(game_t *game)
{
    if (!game)
        return;
    destroy_sprite(game->background);
    destroy_sprite(game->duck);
    destroy_sprite(game->cursor);
    destroy_sprite(game->gameover);
    sfText_destroy(game->score_text);
    sfText_destroy(game->time_text);
    sfText_destroy(game->lives_text);
    sfFont_destroy(game->font);
    sfClock_destroy(game->game_clock);
    sfMusic_destroy(game->background_music);
    sfSound_destroy(game->duck_sound);
    sfSoundBuffer_destroy(game->duck_sound_buffer);
    sfRenderWindow_destroy(game->window);
    free(game);
}
