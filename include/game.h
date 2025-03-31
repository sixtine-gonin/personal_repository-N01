/*
** EPITECH PROJECT, 2024
** hunter_test
** File description:
** game.h
*/

#ifndef GAME_H_
    #define GAME_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>

    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600
    #define DUCK_SPEED 200.0f
    #define GAME_DURATION 60.0f
    #define LIVES 5
    #define DUCK_WIDTH 110
    #define DUCK_HEIGHT 110

typedef enum {
    MENU,
    PLAYING,
    GAME_OVER
} game_state_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *anim_clock;
    float speed;
} sprite_t;

typedef struct {
    sfRenderWindow *window;
    sprite_t *background;
    sprite_t *duck;
    sprite_t *cursor;
    sprite_t *start_btn;
    sprite_t *gameover;
    sfText *score_text;
    sfText *time_text;
    sfText *lives_text;
    sfFont *font;
    sfClock *game_clock;
    sfMusic *background_music;
    sfSound *duck_sound;
    sfSoundBuffer *duck_sound_buffer;
    game_state_t state;
    int score;
    int lives;
    int best_score;
    float game_time;
    sfVector2f score_pos;
} game_t;

int my_strlen(const char *str);
void my_strcat(char *dest, const char *src);
void int_to_str(int num, char *str);
void my_revstr(char *str, int len);
sprite_t *create_sprite(const char *, sfVector2f, sfIntRect);
sprite_t *init_sprite_components(sprite_t *, const char *);
void init_text(game_t *);
void init_game_objects(game_t *);
void init_game_state(game_t *);
void init_audio(game_t *);
void init_gameover(game_t *);
game_t *init_game(void);
void update_duck(sprite_t *, float);
void update_score(game_t *);
void update_game(game_t *);
void handle_menu_click(game_t *);
void handle_playing_click(game_t *);
void handle_gameover_click(game_t *);
void handle_click(game_t *);
void handle_events(game_t *);
void destroy_sprite(sprite_t *);
void destroy_game(game_t *);
void render_playing_state(game_t *);
void render_gameover_state(game_t *);
void render_game(game_t *);
void display_help(void);
int game_loop(game_t *);

#endif /* GAME_H_ */
