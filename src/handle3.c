/*
** EPITECH PROJECT, 2018
** handle
** File description:
** handle3
*/

#include "my.h"

void handle_cooldown(game_t *game)
{
	for (int i = 1; i != 5; i++) {
		if (game->scene[6].buttons[i].active > 0)
			game->scene[6].buttons[i].active -= 1;
	}
}

void update_inventory2_2(game_t *game, sfVector2f pos)
{
	sfText_setString(game->scene[5].objs[5].text, "MAX");
	pos.x = 218;
	pos.y = 525;
	sfText_setPosition(game->scene[5].objs[5].text, pos);
}

void update_inventory2(game_t * game, sfVector2f pos)
{
	sfIntRect food_bar = {0, 0, 281, 31};
	sfIntRect xp_bar = {0, 0, 0, 17};

	game->inv->health_rect.width = game->boat[0].life * 2.81;
	food_bar.width = game->food * 2.81;
	xp_bar.width = game->boat[0].xp * 5.25;
	sfSprite_setTextureRect(game->scene[5].objs[4].sprite,
	game->inv->health_rect);
	sfSprite_setTextureRect(game->scene[5].objs[2].sprite, xp_bar);
	sfSprite_setTextureRect(game->scene[5].objs[10].sprite,
	food_bar);
	if (game->boat[0].attack == 10) {
		update_inventory2_2(game, pos);
	} else {
		sfText_setString(game->scene[5].objs[5].text,
		nbr_to_str(game->boat[0].attack));
	}
}

void update_inventory3(game_t *game, sfVector2f pos)
{
	if (game->boat[0].def == 10) {
		sfText_setString(game->scene[5].objs[6].text, "MAX");
		pos.x = 386;
		pos.y = 515;
		sfText_setPosition(game->scene[5].objs[6].text, pos);
	} else {
		sfText_setString(game->scene[5].objs[6].text,
		nbr_to_str(game->boat[0].def));
	}
	if (game->boat[0].speed == 10) {
		sfText_setString(game->scene[5].objs[7].text, "MAX");
		pos.x = 542;
		pos.y = 515;
		sfText_setPosition(game->scene[5].objs[7].text, pos);
	} else {
		sfText_setString(game->scene[5].objs[7].text,
		nbr_to_str(game->boat[0].speed));
	}
	sfText_setString(game->scene[5].objs[8].text,
	nbr_to_str(game->boat[0].skill_token));
}