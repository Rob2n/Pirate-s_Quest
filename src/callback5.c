/*
** EPITECH PROJECT, 2018
** callback
** File description:
** callback4
*/

#include "my.h"

void focus_boat_1(game_t *game)
{
	sfVector2f pos = {571, 45};

	game->selected_boat = 1;
	if (game->boss == 0)
		pos.x -= 35;
	sfSprite_setPosition(game->scene[6].objs[6].sprite, pos);
}

void focus_boat_2(game_t *game)
{
	sfVector2f pos = {451, 175};

	game->selected_boat = 2;
	if (game->boss == 0) {
		pos.x += 80;
		pos.y -= 10;
	}
	sfSprite_setPosition(game->scene[6].objs[6].sprite, pos);
}

void focus_boat_3(game_t *game)
{
	sfVector2f pos = {571, 305};

	game->selected_boat = 3;
	if (game->boss == 0) {
		pos.x -= 35;
		pos.y -= 20;
	}
	sfSprite_setPosition(game->scene[6].objs[6].sprite, pos);
}

void quest(game_t *game)
{
	game->prev_scene = game->current_scene;
	game->current_scene = 8;
}

void goto_map(game_t *game)
{
	sfVector2f pos = {0, 0};
	pos.x = ((game->pos[0] * 48) / 10.777202072538) + 113;
	pos.y = ((game->pos[1] * 48) / 10.497017892644) + 80;
	sfSprite_setPosition(game->scene[9].objs[1].sprite, pos);
	game->prev_scene = game->current_scene;
	game->current_scene = 9;
}