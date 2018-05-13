/*
** EPITECH PROJECT, 2018
** handle
** File description:
** handle3
*/

#include "my.h"

void handle_parallax(game_t *game, int nb_scene, int nb_obj, int anim_bool)
{
	static float offset_x = 0;
	static float offset_y = 0;
	sfVector2f offset_pos = {0, 0};

	offset_x -= 1;
	offset_y += 0.4;
	if (anim_bool == 0)
		handle_ship_menu_anim(game);
	if (offset_x <= -800) {
		offset_x = 0;
	} else if (offset_x > 0)
		offset_x = -800;
	if (offset_y >= 720) {
		offset_y = 0;
	} else if (offset_y < 0)
		offset_y = 720;
	offset_pos.x = offset_x;
	offset_pos.y = -offset_y;
	sfSprite_setPosition(game->scene[nb_scene].objs[nb_obj].sprite,
	offset_pos);
}

int button_is_hovered(button_t button, sfVector2i clickPosition)
{
	return (clickPosition.x < sfSprite_getPosition(button.sprite).x +
	sfSprite_getGlobalBounds(button.sprite).width &&
	clickPosition.x > sfSprite_getPosition(button.sprite).x &&
	clickPosition.y < sfSprite_getPosition(button.sprite).y +
	sfSprite_getGlobalBounds(button.sprite).height &&
	clickPosition.y > sfSprite_getPosition(button.sprite).y);
}

int check_collide(game_t *game, draw_t *md)
{
	sfFloatRect boat =
	sfSprite_getGlobalBounds(game->scene[2].objs[1].sprite);
	sfFloatRect spr = {md->pos.x, md->pos.y, 30.0, 30.0};

	if (sfFloatRect_intersects(&boat, &spr, NULL) == sfTrue)
		return (1);
	return (0);
}

void handle_boss_cinematic2(game_t *game, int limit)
{
	sfVector2f decal_boss = {0, 1};

	handle_parallax(game, 11, 0, 0);
	if (sfSprite_getPosition(game->scene[11].objs[2].sprite).y <
	limit)
		sfSprite_move(game->scene[11].objs[2].sprite, decal_boss);
	else
		boss_fight(game);
}

void handle_boss_cinematic(game_t *game)
{
	sfVector2f decal = {-2, 0};
	sfVector2f decal_boat = {0, 1.5};
	int limit = 70;
	static int my_bool = 0;

	if (game->current_scene == 11 && sfSprite_getPosition
	(game->scene[11].objs[0].sprite).x < 0)
		my_bool = 1;
	if (game->current_scene == 11 && my_bool == 0) {
		sfSprite_move(game->scene[11].objs[0].sprite, decal);
	} else if (game->current_scene == 11 && my_bool == 1) {
		handle_boss_cinematic2(game, limit);
	}
	if (sfSprite_getPosition(game->scene[11].objs[0].sprite).x < limit &&
	sfSprite_getPosition(game->scene[11].objs[1].sprite).y < 200)
		sfSprite_move(game->scene[11].objs[1].sprite, decal_boat);
}