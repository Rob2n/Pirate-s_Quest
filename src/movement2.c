/*
** EPITECH PROJECT, 2018
** movement2
** File description:
** movement2
*/

#include "my.h"

void apply_inertia_8_dirs_2(game_t *game)
{
	if (sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 101.25 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	< 123.75) {
		game->pos[0] -= game->speed / 1.35;
		game->pos[1] -= game->speed / 2;
		game->dir_x = -game->speed / 1.35;
		game->dir_y = -game->speed / 2;
	} else if (sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 146.25 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	< 168.75) {
		game->pos[0] -= game->speed / 2;
		game->pos[1] -= game->speed / 1.35;
		game->dir_x = -game->speed / 2;
		game->dir_y = -game->speed / 1.35;
	}
	apply_inertia_8_dirs_3(game);
}

void apply_inertia_8_dirs_3(game_t *game)
{
	if ((sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 191.25 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	< 213.75)) {
		game->pos[0] += game->speed / 2;
		game->pos[1] -= game->speed / 1.35;
		game->dir_x = game->speed / 2;
		game->dir_y = -game->speed / 1.35;
	} else if (sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 236.25 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	< 258.75) {
		game->pos[0] += game->speed / 1.35;
		game->pos[1] -= game->speed / 2;
		game->dir_x = -game->speed / 1.35;
		game->dir_y = -game->speed / 2;
	}
	apply_inertia_8_dirs_4(game);
}

void apply_inertia_8_dirs_4(game_t *game)
{
	if ((sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 281.25 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	< 303.75)) {
		game->pos[0] += game->speed / 1.35;
		game->pos[1] += game->speed / 2;
		game->dir_x = game->speed / 1.35;
		game->dir_y = game->speed / 2;
	} else if (sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 326.25 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	< 348.75) {
		game->pos[0] += game->speed / 2;
		game->pos[1] += game->speed / 1.35;
		game->dir_x = game->speed / 2;
		game->dir_y = game->speed / 1.35;
	}
}

void apply_inertia_8_dirs(game_t *game)
{
	if (sfSprite_getRotation(game->scene[2].objs[1].sprite) > 11.25 &&
	sfSprite_getRotation(game->scene[2].objs[1].sprite) < 33.75) {
		game->pos[0] -= game->speed / 2;
		game->pos[1] += game->speed / 1.35;
		game->dir_x = -game->speed / 2;
		game->dir_y = game->speed / 1.35;
	} else if (sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 56.25 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	< 78.75) {
		game->pos[0] -= game->speed / 1.35;
		game->pos[1] += game->speed / 2;
		game->dir_x = -game->speed / 1.35;
		game->dir_y = game->speed / 2;
	}
	apply_inertia_8_dirs_2(game);
}

void handle_player_movement(sfEvent event, game_t *game)
{
	if (event.key.code == sfKeyUp && game->speed <= 0.04 +
		((float)game->boat[0].speed / 250))
		game->speed += 0.010;
	if (event.key.code == sfKeyDown && game->speed >= -0.015)
		game->speed -= 0.010;
	if (event.key.code == sfKeyLeft && game->direction >= -1)
		sfSprite_rotate(game->scene[2].objs[1].sprite, -5);
	if (event.key.code == sfKeyRight && game->direction <= 1)
		sfSprite_rotate(game->scene[2].objs[1].sprite, 5);
}