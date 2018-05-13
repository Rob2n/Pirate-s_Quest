/*
** EPITECH PROJECT, 2018
** my
** File description:
** rpg
*/

#include "my.h"

int check_cell2(game_t *game, char ***map, draw_t *md)
{
	if (game->quest_involved == 0) {
		sfSprite_setTexture(game->scene[8].objs[0].sprite,
		game->no_qtextu, sfTrue);
	}
	if (check_collide(game, md) == 1) {
		sfClock_restart(game->clock2);
		if (my_strcmp(map[md->draw[1]][md->draw[0]], "43") == 0 ||
		my_strcmp(map[md->draw[1]][md->draw[0]], "42") == 0) {
			fight(game);
			map[md->draw[1]][md->draw[0] - 1][0] = '0';
			map[md->draw[1]][md->draw[0] - 1][1] = '0';
			map[md->draw[1]][md->draw[0]][0] = '0';
			map[md->draw[1]][md->draw[0]][1] = '0';
			map[md->draw[1]][md->draw[0] + 1][0] = '0';
			map[md->draw[1]][md->draw[0] + 1][1] = '0';
		}
		check_cell3(game, map, md);
		return (1);
	}
	return (0);
}

int check_cell(game_t *game, char ***map, draw_t *md)
{
	if (md->draw[0] >= 0 && md->draw[0] <= 129)
		if (my_strcmp(map[md->draw[1]][md->draw[0]], "00"))
			return (check_cell2(game, map, md));
	return (0);
}

int check_line(game_t *game, char ***map, draw_t *md)
{
	for (; md->pos.x < 816; md->pos.x += 48) {
		if (md->draw[1] < 0 || md->draw[1] > 109)
			break;
		if (check_cell(game, map, md) == 1)
			return (1);
		md->draw[0]++;
	}
	return (0);
}

void pop_up_handling(game_t *game)
{
	sfTime timer = sfClock_getElapsedTime(game->clock2);
	float miliseconds = (timer.microseconds / 10000000.0);

	if (miliseconds > 0.4) {
		sfText_setString(game->scene[2].objs[2].text, " ");
		sfClock_restart(game->clock2);
	}
}

int check_boat(game_t *game, char ***map, double *perso)
{
	draw_t *md = init_draw(perso);

	pop_up_handling(game);
	md->pos.y = (perso[1] - (int)perso[1]) * -48;
	md->pos.y = (md->pos.y > 0) ? -md->pos.y + 48 : md->pos.y;
	md->draw[1] -= (perso[1] < 7 && (perso[1] -
	(int)perso[1]) != 0) ? 1 : 0;
	md->draw[0] -= (perso[0] < 8 && (perso[0] -
	(int)perso[0]) != 0) ? 1 : 0;
	for (; md->pos.y < 720; md->pos.y += 48) {
		md->pos.x = (perso[0] - (int)perso[0]) * -48;
		md->pos.x = (md->pos.x > 0) ? -md->pos.x + 48 : md->pos.x;
		if (check_line(game, map, md) == 1)
			return (1);
		md->draw[0] = perso[0] - 8;
		md->draw[0] -= (perso[0] < 8 && (perso[0] -
		(int)perso[0]) != 0) ? 1 : 0;
		md->draw[1]++;
	}
	return (0);
}