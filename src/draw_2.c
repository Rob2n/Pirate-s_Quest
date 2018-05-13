/*
** EPITECH PROJECT, 2018
** draw
** File description:
** draw
*/

#include "my.h"

void draw_boss(game_t game)
{
	sfRenderWindow_drawSprite(game.window, game.scene[6].objs[2].sprite,
	NULL);
	sfRenderWindow_drawSprite(game.window, game.scene[11].objs[2].sprite,
	NULL);
	for (int i = 2; i != 7; i++)
		sfRenderWindow_drawSprite(game.window, game.scene[6].objs[i].
		sprite, NULL);
}

void draw_buttons(game_t game)
{
	for (int i = 0; i != game.scene[game.current_scene].nb_buttons; i++)
		sfRenderWindow_drawSprite(game.window,
		game.scene[game.current_scene].buttons[i].sprite, NULL);
	if (game.current_scene == 6) {
		for (int i = 16; i != 20; i++)
			sfRenderWindow_drawSprite(game.window,
			game.scene[6].objs[i].sprite, NULL);
	}
	if (game.boss == 0 && game.current_scene == 6)
		draw_boss(game);
	sfRenderWindow_drawSprite(game.window, game.cursor, NULL);
}

void draw_scene(game_t game)
{
	if (game.current_scene == 2) {
		sfRenderWindow_drawSprite(game.window,
		game.scene[game.current_scene].objs[0].sprite, NULL);
		draw_map(game.map, game.pos, game.window);
	}
	for (int i = 0; i != game.scene[game.current_scene].nb_objs; i++) {
		if (game.scene[game.current_scene].objs[i].str)
			sfRenderWindow_drawText(game.window,
			game.scene[game.current_scene].objs[i].text, NULL);
		if (game.current_scene == 2 && i == 0)
			i++;
		sfRenderWindow_drawSprite(game.window,
		game.scene[game.current_scene].objs[i].sprite, NULL);
	}
	if (game.current_scene == 6)
		sfRenderWindow_drawSprite(game.window,
		game.scene[6].objs[1].sprite, NULL);
	draw_buttons(game);
}

void play_ai_2(game_t *game, int i)
{
	int random_e = rand() % 100;
	int random = 0;
	int *stat = malloc(sizeof(int) * 3);

	(random_e < 5 * (0.7 * game->boat[0].speed)) ? (game->esquive = 1) :
	(game->esquive = 0);
	if (game->boat[i].life > 0) {
		while (random == game->attack)
			random = rand() % 3;
		if (random == 0)
			game->attack = 0;
		if (random == 1)
			game->attack = 1;
		if (random == 2)
			game->attack = 2;
		stat[0] = game->attack;
		stat[1] = i;
		stat[2] = game->esquive;
		game->attack_stat[i - 1] = stat;
	}
}

void play_ai(game_t *game)
{
	for (int i = 1; i != game->nb_boats_fight + 1; i++)
		play_ai_2(game, i);
	game->fight_turn = 0;
	game->anim = 1;
}