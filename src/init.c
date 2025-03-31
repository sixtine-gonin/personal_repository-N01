/*
** EPITECH PROJECT, 2024
** hunter_test
** File description:
** init.c
*/

#include "../include/game.h"

sprite_t *init_sprite_components(sprite_t *sprite, const char *path)
{
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->anim_clock = sfClock_create();
    if (!sprite->texture || !sprite->sprite || !sprite->anim_clock) {
        destroy_sprite(sprite);
        return NULL;
    }
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

sprite_t *create_sprite(const char *path, sfVector2f pos, sfIntRect rect)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (!sprite)
        return NULL;
    sprite->pos = pos;
    sprite->rect = rect;
    sprite->speed = DUCK_SPEED;
    return init_sprite_components(sprite, path);
}

void init_text(game_t *game)
{
    game->font = sfFont_createFromFile("assets/police1.ttf");
    game->score_text = sfText_create();
    game->time_text = sfText_create();
    game->lives_text = sfText_create();
    sfText_setFont(game->score_text, game->font);
    sfText_setFont(game->time_text, game->font);
    sfText_setFont(game->lives_text, game->font);
    sfText_setPosition(game->score_text, (sfVector2f){10, 10});
    sfText_setPosition(game->time_text, (sfVector2f){10, 40});
    sfText_setPosition(game->lives_text, (sfVector2f){10, 70});
}

void init_audio(game_t *game)
{
    game->background_music = sfMusic_createFromFile("assets/background.mp3");
    game->duck_sound_buffer = sfSoundBuffer_createFromFile("assets/hit.mp3");
    game->duck_sound = sfSound_create();
    sfSound_setBuffer(game->duck_sound, game->duck_sound_buffer);
    sfMusic_setLoop(game->background_music, sfTrue);
    sfMusic_play(game->background_music);
}

void init_game_objects(game_t *game)
{
    game->background = create_sprite("assets/background.jpg",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});
    game->duck = create_sprite("assets/duck_sprite.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, DUCK_WIDTH, DUCK_HEIGHT});
    game->cursor = create_sprite("assets/crosshair.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 85, 72});
    game->gameover = create_sprite("assets/game_over.png",
        (sfVector2f){WINDOW_WIDTH / 5, WINDOW_HEIGHT / 30},
        (sfIntRect){10, 100, 500, 500});
    game->game_clock = sfClock_create();
}
