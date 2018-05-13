/*
** EPITECH PROJECT, 2018
** init
** File description:
** init2
*/

#include "my.h"

void init_game_2_1(game_t *game)
{
	game->boat[0].first =
	sfTexture_createFromFile("assets/used_boat/green_ship_75.png", NULL);
	game->boat[0].second =
	sfTexture_createFromFile("assets/used_boat/green_ship_50.png", NULL);
	game->boat[0].third =
	sfTexture_createFromFile("assets/used_boat/green_ship_75p.png", NULL);
	game->boat[0].fourth =
	sfTexture_createFromFile("assets/used_boat/green_ship_50p.png", NULL);
	game->boat[0].init =
	sfTexture_createFromFile("assets/green_ship_m.png", NULL);
	game->boat[0].small_init =
	sfTexture_createFromFile("assets/green_ship.png", NULL);
}

void init_game_2(game_t *game)
{
	game->pos[0] = 100;
	game->pos[1] = 25;
	game->dir_y = 0;
	game->dir_x = 0;
	my_putstr("Loading music...\n");
	game->music = init_music();
	game->boat = malloc(sizeof(boat_t) * NB_BOATS);
	game->clock = sfClock_create();
	game->clock2 = sfClock_create();
	init_game_2_1(game);
	game->selected_boat = 1;
	game->boat[0].skill_token = 2;
	init_inventory(game);
	init_game_3(game);
	game->first_quest = 0;
	sfText_setString(game->scene[8].objs[1].text, " ");
}

void init_stat_cursor_2(game_t *game)
{
	game->first_qtextu =
	sfTexture_createFromFile("assets/first_quest.png", NULL);
	game->second_qtextu =
	sfTexture_createFromFile("assets/second_quest.png", NULL);
	game->third_qtextu =
	sfTexture_createFromFile("assets/third_quest.png", NULL);
	game->final_qtextu =
	sfTexture_createFromFile("assets/first_quest.png", NULL);
	game->no_qtextu =
	sfTexture_createFromFile("assets/parchemin.png", NULL);
}

void init_stat_cursor(game_t *game)
{
	game->cursor_stat = malloc(sizeof(cursor_stat_t));
	game->cursor_stat->cursor_stat_blue =
	sfTexture_createFromFile("assets/stat_board_green.png", NULL);
	game->cursor_stat->cursor_stat_red =
	sfTexture_createFromFile("assets/stat_board_red.png", NULL);
	game->cursor_stat->cursor_stat_yellow =
	sfTexture_createFromFile("assets/stat_board_yellow.png", NULL);
	game->cursor_stat->cursor_stat_green =
	sfTexture_createFromFile("assets/stat_board_blue.png", NULL);
	game->second_quest = 0;
	game->third_quest = 0;
	game->speed = 0;
	game->direction = 0;
	init_stat_cursor_2(game);
}

void init_game(game_t *game, scene_t *scene)
{
	callback_t *callbacks = init_callbacks();
	sfVideoMode mode = {816, 720, 32};

	game->window = sfRenderWindow_create(mode,"Pirate Quest", sfResize |
	sfClose, NULL);
	game->callbacks = callbacks;
	game->cursor = sfSprite_create();
	game->cursor_text = sfTexture_createFromFile("assets/cursor.png",
	NULL);
	init_stat_cursor(game);
	sfSprite_setTexture(game->cursor, game->cursor_text, sfTrue);
	game->current_scene = 10;
	game->prev_scene = 0;
	game->scene = scene;
	my_putstr("Loading world...\n");
	game->map = parse_map();
	game->pos = malloc(sizeof(double) * 2);
	init_game_2(game);
	sfText_setColor(game->scene[2].objs[3].text, sfBlack);
}