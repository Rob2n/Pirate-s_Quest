/*
** EPITECH PROJECT, 2018
** handle
** File description:
** handle3
*/

#include "my.h"

void update_inventory4_2(game_t *game, sfIntRect *health_bar, int i)
{
	if ((*health_bar).width <= 0) {
		if (game->boss == 1) {
			game->scene[6].buttons[i + 4].texture =
			sfTexture_createFromFile("assets/ship_dead_bad.png",
			NULL);
		}
		(*health_bar).width = 0;
	}
}

void update_inventory4(game_t *game)
{
	sfIntRect health_bar = {0, 0, 125, 15};

	if (game->current_scene == 6) {
		health_bar.width = game->boat[0].life * 2.81;
		sfSprite_setTextureRect(game->scene[6].objs[2].sprite,
		health_bar);
		for (int i = 1; i != 4; i++) {
			health_bar.width = game->boat[i].life * 2.81;
			update_inventory4_2(game, &health_bar, i);
			sfSprite_setTextureRect(game->scene[6].objs[i + 2]
			.sprite, health_bar);
		}
	}
}

void stat_def(game_t *game)
{
	if (game->boat[0].def < 10 && game->boat[0].skill_token != 0) {
		game->boat[0].def++;
		game->boat[0].skill_token--;
	}
}

void stat_speed(game_t *game)
{
	if (game->boat[0].speed < 10 && game->boat[0].skill_token != 0) {
		game->boat[0].speed++;
		game->boat[0].skill_token--;
	}
}

int button_is_clicked(button_t button, sfVector2f clickPosition)
{
	return (clickPosition.x < sfSprite_getPosition(button.sprite).x +
	sfSprite_getGlobalBounds(button.sprite).width &&
	clickPosition.x > sfSprite_getPosition(button.sprite).x &&
	clickPosition.y < sfSprite_getPosition(button.sprite).y +
	sfSprite_getGlobalBounds(button.sprite).height &&
	clickPosition.y > sfSprite_getPosition(button.sprite).y);
}