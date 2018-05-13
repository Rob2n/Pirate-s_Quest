/*
** EPITECH PROJECT, 2018
** Project my_rpg
** File description:
** Header file
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define NB_SCENES (14)
#define NB_CALLBACKS (30)
#define NB_BOATS (4)

typedef struct boat_s {
	int life;
	int attack;
	int def;
	int speed;
	int skill_token;
	int xp;
	sfTexture *first;
	sfTexture *first_h;
	sfTexture *second;
	sfTexture *second_h;
	sfTexture *third;
	sfTexture *fourth;
	sfTexture *third_h;
	sfTexture *dead;
	sfTexture *init;
	sfTexture *small_init;
} boat_t;

typedef struct button_s {
	sfVector2f position;
	sfSprite *sprite;
	sfTexture *texture;
	sfTexture *texture_hovered;
	int callback;
	int active;
} button_t;

typedef struct game_object_s {
	sfSprite *sprite;
	sfText *text;
	char *texture_path;
	char *str;
} game_object_t;

typedef struct callback_s {
	void (*callback)();
} callback_t;

typedef struct scene_s {
	game_object_t *objs;
	int nb_objs;
	button_t *buttons;
	int nb_buttons;
} scene_t;

typedef struct music_s {
	sfMusic *menu;
	sfMusic *fight;
	sfMusic *canon;
	sfMusic *mortar;
	sfMusic *boarding;
	sfMusic *repair;
	sfMusic *end;
	sfMusic *boss;
} music_t;

typedef struct inventory_s {
	sfIntRect health_rect;
} inventory_t;

typedef struct cursor_stat_s {
	sfTexture *cursor_stat_green;
	sfTexture *cursor_stat_red;
	sfTexture *cursor_stat_blue;
	sfTexture *cursor_stat_yellow;
} cursor_stat_t;

typedef struct game_s {
	sfRenderWindow *window;
	sfEvent event;
	sfClock *clock;
	sfClock *clock2;
	sfSprite *cursor;
	scene_t *scene;
	music_t *music;
	inventory_t *inv;
	callback_t *callbacks;
	boat_t *boat;
	float dir_x;
	float dir_y;
	float speed;
	float direction;
	float seconds;
	double *pos;
	char ***map;
	int boss;
	int current_scene;
	int prev_scene;
	int nb_boats_fight;
	int selected_boat;
	int fight_turn;
	int anim;
	int attack;
	int nb_attacking_boat;
	int first_quest;
	int second_quest;
	int third_quest;
	int quest_involved;
	int current_boat;
	int esquive;
	int difficulty;
	int food;
	int maitre_ruben;
	int **attack_stat;
	sfTexture *cursor_text;
	cursor_stat_t *cursor_stat;
	sfTexture *first_qtextu;
	sfTexture *second_qtextu;
	sfTexture *third_qtextu;
	sfTexture *final_qtextu;
	sfTexture *no_qtextu;
	sfTexture *first_how;
	sfTexture *second_how;
	sfTexture *third_how;
} game_t;

typedef struct draw_s {
	int *draw;
	sfVector2f pos;
	char *path;
	sfTexture *text;
	sfSprite *sprite;
} draw_t;

void draw_scene(game_t game);
void handle_cooldown(game_t *game);
int my_putstr(char *str);
char *nbr_to_str(int nbr);
void init_button(button_t *button, char **line);
int main(int ac, char **av);
char **conv_array(char *str, char var);
void boss_fight(game_t *game);
void update_inventory(game_t *game);
int my_getnbr(char const *str);
char ***parse_map(void);
void handle_parallax(game_t *game, int nb_scene, int nb_obj, int anim_bool);
void draw_map(char ***, double *, sfRenderWindow *);
draw_t *init_draw(double *);
int fight_draw(game_t *game);
void check_end_fight(game_t *game);
void apply_inertia_4_dirs(game_t *game);
void handle_cinematics(game_t *game);
void play_ai_2(game_t *game, int i);
void check_third_quest3(game_t *game);
void apply_damage_friend(game_t *game);
void goto_boss_cinematic(game_t *game);
void handle_boss_cinematic(game_t *game);
void goto_menu(game_t *game);
void play_ai(game_t *game);
void apply_inertia_8_dirs_2(game_t *game);
void apply_inertia_8_dirs_3(game_t *game);
void check_second_quest_2(game_t *game, char *tempo);
void goto_credits(game_t *game);
void apply_inertia_8_dirs_4(game_t *game);
void apply_inertia_8_dirs(game_t *game);
void fight_draw_3(game_t *game);
void init_inventory(game_t *game);
void apply_inertia_diag_2(game_t *game);
void handle_fight_turns(game_t *game);
void apply_inertia_diag(game_t *game);
void apply_inertia(game_t *game);
int check_boat(game_t *game, char ***map, double *perso);
void handle_parallax(game_t *game, int nb_scene, int nb_obj, int anim_bool);
void handle_player_movement(sfEvent event, game_t *game);
void canon(game_t *game);
void mortier(game_t *game);
void bordage(game_t *game);
void do_canon_anim_friendly(game_t *game);
void do_anim(game_t *game);
void defence(game_t *game);
void fight(game_t *game);
void quit(game_t *game);
void goto_game(game_t *game);
void goto_options(game_t *game);
void goto_last_scene(game_t *game);
void goto_pause(game_t *game);
void goto_select_player(game_t *game);
void wait_1_sec(game_t *game, int);
void goto_game_red(game_t *game);
void goto_game_blue(game_t *game);
void goto_game_yellow(game_t *game);
void goto_inventory(game_t *game);
void goto_map(game_t *game);
callback_t *init_callbacks(void);
scene_t *init_scenes(void);
music_t *init_music(void);
void init_game_2(game_t *game);
void init_game(game_t *game, scene_t *scene);
void change_volume_2(int *volume, game_t *game);
void focus_boat_1(game_t *game);
void focus_boat_2(game_t *game);
void focus_boat_3(game_t *game);
void change_volume(game_t *game);
void change_bool(int *my_bool, game_t *game);
void change_graphics(game_t *game);
int create_my_scene(scene_t *scene, FILE *stream);
void init_objs(game_object_t *objs, char **line);
void init_button(button_t *button, char **line);
void create_my_scene_bis(scene_t *scene, FILE *stream);
int create_my_scene(scene_t *scene, FILE *stream);
void draw_buttons(game_t game);
void draw_scene(game_t game);
void fight_draw_2(game_t *game);
int fight_draw(game_t *game);
void handle_keys(game_t *game);
void cursor_handle(game_t *game);
int event_handler(game_t *game);
void handle_ship_menu_anim(game_t *game);
void handle_parallax(game_t *game, int nb_scene, int nb_obj, int anim_bool);
int check_buttons(game_t *game);
int handle_hovering(game_t *game);
void handle_other_funcs(game_t *game);
int button_is_clicked(button_t button, sfVector2f clickPosition);
int button_is_hovered(button_t button, sfVector2i clickPosition);
int check_collide(game_t *game, draw_t *md);
void stat_att(game_t *game);
void stat_def(game_t *game);
void stat_speed(game_t *game);
void quest(game_t *game);
void quest_checker(game_t *game);
void check_quest(game_t *game, char ***map, draw_t *md);
int check_fight(game_t *game, char ***map, draw_t *md);
int my_strcmp(char *s1, char *s2);
void check_second_quest(game_t *game, char ***map, draw_t *md);
void pop_up_handling(game_t *game);
void check_third_quest(game_t *game, char ***map, draw_t *md);
void reset_anims_bad2(game_t *game, sfVector2f pos,
int *my_bool_music, sfVector2f pos_f);
void handle_flames_bad(game_t *game);
void handle_sounds_bad(game_t *game, int *my_bool_music);
void handle_sounds_bad2(game_t *game, int *my_bool_music);
void handle_xp_winnings(game_t *game);
void apply_damage_bad(game_t *game, int current_boat);
void reset_anims_bad(game_t *game, int *my_bool_music);
void handle_aiming_bad(game_t *game, sfVector2f *pos);
void do_anim_bad(game_t *game);
void do_anim_repair_f(game_t *game);
void init_game(game_t *game, scene_t *scene);
void do_anim(game_t *game);
void check_fight_2(game_t *game, char ***map, draw_t *md, char *tempo);
void check_second_quest(game_t *game, char ***map, draw_t *md);
void do_anim_friendly(game_t *game, int attack);
void check_cell3(game_t *game, char ***map, draw_t *md);
void check_quest_2(game_t *game, char *tempo);
void check_fight_2(game_t *game, char ***map, draw_t *md, char *tempo);
void init_game_3(game_t *game);
void init_stat_game_1(game_t *game);
void handle_level_up(game_t *game);
void goto_how_to(game_t *game);
void the_how_to(game_t *game);
void handle_cinematics2(game_t *game, sfVector2f decal, float rot,
int move_title);
void update_inventory4(game_t *game);
void update_inventory3(game_t *game, sfVector2f pos);
void update_inventory2(game_t * game, sfVector2f pos);
void set_scene(game_t *game);
char *my_strcat(char *dest, const char *src);
void fight_2(game_t *game, int i);

#endif
