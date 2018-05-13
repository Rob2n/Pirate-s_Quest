/*
** EPITECH PROJECT, 2018
** callback
** File description:
** callback3
*/

#include "my.h"

void goto_select_player(game_t *game)
{
	game->prev_scene = game->current_scene;
	game->current_scene = 1;
}

void goto_game_red_2(game_t *game)
{
	game->boat[0].third =
	sfTexture_createFromFile("assets/used_boat/red_ship_75p.png", NULL);
	game->boat[0].fourth =
	sfTexture_createFromFile("assets/used_boat/red_ship_50p.png", NULL);
	game->boat[0].init =
	sfTexture_createFromFile("assets/red_ship_m.png", NULL);
	game->boat[0].small_init =
	sfTexture_createFromFile("assets/red_ship.png", NULL);
	game->prev_scene = game->current_scene;
	game->current_scene = 2;
	game->boat[0].attack = 0;
	game->boat[0].def = 3;
	game->boat[0].speed = 0;
}

void goto_game_red(game_t *game)
{
	sfSprite_setTexture(game->scene[5].objs[3].sprite,
	sfTexture_createFromFile("assets/red_ship_m.png", NULL),
	sfTrue);
	sfSprite_setTexture(game->scene[2].objs[1].sprite,
	sfTexture_createFromFile("assets/red_ship.png", NULL),
	sfTrue);
	sfSprite_setTexture(game->scene[6].objs[1].sprite,
	sfTexture_createFromFile("assets/red_ship_m.png", NULL),
	sfTrue);
	game->boat[0].first =
	sfTexture_createFromFile("assets/used_boat/red_ship_75.png", NULL);
	game->boat[0].second =
	sfTexture_createFromFile("assets/used_boat/red_ship_50.png", NULL);
	sfSprite_setTexture(game->scene[11].objs[1].sprite,
	sfTexture_createFromFile("assets/red_ship_m.png", NULL),
	sfTrue);
	goto_game_red_2(game);
}

void goto_game_blue_2(game_t *game)
{
	game->boat[0].third =
	sfTexture_createFromFile("assets/used_boat/blue_ship_75p.png", NULL);
	game->boat[0].fourth =
	sfTexture_createFromFile("assets/used_boat/blue_ship_50p.png", NULL);
	game->boat[0].init =
	sfTexture_createFromFile("assets/blue_ship_m.png", NULL);
	game->boat[0].small_init =
	sfTexture_createFromFile("assets/blue_ship.png", NULL);
	game->prev_scene = game->current_scene;
	game->current_scene = 2;
	game->boat[0].attack = 0;
	game->boat[0].def = 0;
	game->boat[0].speed = 3;
}

void goto_game_blue(game_t *game)
{
	sfSprite_setTexture(game->scene[5].objs[3].sprite,
	sfTexture_createFromFile("assets/blue_ship_m.png", NULL),
	sfTrue);
	sfSprite_setTexture(game->scene[2].objs[1].sprite,
	sfTexture_createFromFile("assets/blue_ship.png", NULL),
	sfTrue);
	sfSprite_setTexture(game->scene[6].objs[1].sprite,
	sfTexture_createFromFile("assets/blue_ship_m.png", NULL),
	sfTrue);
	game->boat[0].first =
	sfTexture_createFromFile("assets/used_boat/blue_ship_75.png", NULL);
	game->boat[0].second =
	sfTexture_createFromFile("assets/used_boat/blue_ship_50.png", NULL);
	sfSprite_setTexture(game->scene[11].objs[1].sprite,
	sfTexture_createFromFile("assets/blue_ship_m.png", NULL),
	sfTrue);
	goto_game_blue_2(game);
}