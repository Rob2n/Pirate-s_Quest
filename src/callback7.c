/*
** EPITECH PROJECT, 2018
** callback
** File description:
** callback2
*/

#include "my.h"

void goto_how_to(game_t *game)
{
	game->prev_scene = game->current_scene;
	game->current_scene = 12;
}

void the_how_to(game_t *game)
{
	static int i = 1;

	if (i == 1)
		sfSprite_setTexture(game->scene[12].objs[0].sprite,
		game->second_how, sfTrue);
	if (i == 2)
		sfSprite_setTexture(game->scene[12].objs[0].sprite,
		game->third_how, sfTrue);
	if (i == 3) {
		sfSprite_setTexture(game->scene[12].objs[0].sprite,
		game->first_how, sfTrue);
		i = 1;
		return;
	}
	i++;
}

void goto_boss_cinematic(game_t *game)
{
	if (sfMusic_getStatus(game->music->menu) == sfPlaying) {
		sfMusic_stop(game->music->menu);
		sfMusic_play(game->music->boss);
	}
	game->prev_scene = game->current_scene;
	game->current_scene = 11;
}

void fight_2(game_t *game, int i)
{
	game->boat[i].first =
	sfTexture_createFromFile("assets/black_ship.png", NULL);
	game->boat[i].first_h =
	sfTexture_createFromFile("assets/black_ship_s.png", NULL);
	game->boat[i].second =
	sfTexture_createFromFile("assets/black_ship_50.png", NULL);
	game->boat[i].second_h =
	sfTexture_createFromFile("assets/black_ship_50_s.png", NULL);
	game->boat[i].third =
	sfTexture_createFromFile("assets/black_ship_75.png", NULL);
	game->boat[i].third_h =
	sfTexture_createFromFile("assets/black_ship_75_s.png", NULL);
}

void fight(game_t *game)
{
	game->prev_scene = game->current_scene;
	game->current_scene = 6;
	game->scene[4].buttons[0].callback = 12;
	game->nb_boats_fight = 3;
	for (int i = 1; i != 4; i++)
		game->boat[i].attack = (rand() % game->difficulty) + 2;
	for (int i = 1; i != 4; i++)
		game->boat[i].def = (rand() % game->difficulty) + 2;
	for (int i = 1; i != 4; i++)
		game->boat[i].speed = (rand() % game->difficulty) + 2;
	for (int i = 1; i != game->nb_boats_fight + 1; i++)
		fight_2(game, i);
	if (sfMusic_getStatus(game->music->menu) == sfPlaying) {
		sfMusic_stop(game->music->menu);
		sfMusic_play(game->music->fight);
	}
}