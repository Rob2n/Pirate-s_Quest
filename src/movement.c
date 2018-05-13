/*
** EPITECH PROJECT, 2018
** movement
** File description:
** handling
*/

#include "my.h"

void apply_inertia_4_dirs(game_t *game)
{
	if (sfSprite_getRotation(game->scene[2].objs[1].sprite) >=
	168.75 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	<= 191.25) {
		game->pos[1] -= game->speed;
		game->dir_y = -game->speed;
	} else if ((sfSprite_getRotation(game->scene[2].objs[1].sprite) <=
	11.25 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	>= 0) || (sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 348.75)) {
		game->pos[1] += game->speed;
		game->dir_y = game->speed;
	}
	apply_inertia_diag(game);
}

void apply_inertia_diag_2(game_t *game)
{
	if (sfSprite_getRotation(game->scene[2].objs[1].sprite) > 213.75 &&
	sfSprite_getRotation(game->scene[2].objs[1].sprite) < 236.25) {
		game->pos[0] += game->speed / 2;
		game->pos[1] -= game->speed / 2;
		game->dir_x = game->speed / 2;
		game->dir_y = -game->speed / 2;
	}
	else if ((sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 303.25 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	< 326.25)) {
		game->pos[0] += game->speed / 2;
		game->pos[1] += game->speed / 2;
		game->dir_x = game->speed / 2;
		game->dir_y = game->speed / 2;
	}
	apply_inertia_8_dirs(game);
}

void apply_inertia_diag(game_t *game)
{
	if (sfSprite_getRotation(game->scene[2].objs[1].sprite) > 33.75 &&
	sfSprite_getRotation(game->scene[2].objs[1].sprite) < 56.25) {
		game->pos[0] -= game->speed / 2;
		game->pos[1] += game->speed / 2;
		game->dir_x = -game->speed / 2;
		game->dir_y = game->speed / 2;
	}
	else if (sfSprite_getRotation(game->scene[2].objs[1].sprite)
	> 123.75 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	< 146.25) {
		game->pos[0] -= game->speed / 2;
		game->pos[1] -= game->speed / 2;
		game->dir_x = -game->speed / 2;
		game->dir_y = -game->speed / 2;
	}
	apply_inertia_diag_2(game);
}

void apply_inertia(game_t *game)
{
	sfVector2f echodolarstatus = {24, 42};
	int tempo = 0;

	handle_parallax(game, 2, 0, 1);
	sfSprite_setOrigin(game->scene[2].objs[1].sprite, echodolarstatus);
	tempo = check_boat(game, game->map, game->pos);
	game->speed = (tempo == 1) ? -game->speed : game->speed;
	if (sfSprite_getRotation(game->scene[2].objs[1].sprite) >=
	78.75 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	<= 101.25) {
		game->pos[0] -= game->speed;
		game->dir_x = -game->speed;
	} else if (sfSprite_getRotation(game->scene[2].objs[1].sprite) >=
	258.75 && sfSprite_getRotation(game->scene[2].objs[1].sprite)
	<= 281.25) {
		game->pos[0] += game->speed;
		game->dir_x = game->speed;
	}
	apply_inertia_4_dirs(game);
}