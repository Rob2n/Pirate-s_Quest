/*
** EPITECH PROJECT, 2018
** callback
** File description:
** callback8
*/

#include "my.h"

void goto_credits(game_t *game)
{
	game->prev_scene = game->current_scene;
	game->current_scene = 13;
}

void check_second_quest(game_t *game, char ***map, draw_t *md)
{
	char *tempo = malloc(sizeof(char) * 30);

	tempo[0] = '\0';
	tempo = my_strcat(tempo, "Objective: ");
	tempo[10] = game->second_quest + 48;
	tempo = my_strcat(tempo, "/6 rhum");
	tempo[19] = '\0';
	if (map[md->draw[1]][md->draw[0]][0] == '7' &&
	map[md->draw[1]][md->draw[0]][1] == '4')
		check_second_quest_2(game, tempo);
	if (map[md->draw[1]][md->draw[0]][0] == '7' &&
	map[md->draw[1]][md->draw[0]][1] == '2' && game->second_quest >= 1) {
		map[md->draw[1]][md->draw[0]][0] = '0';
		map[md->draw[1]][md->draw[0]][1] = '0';
		game->second_quest++;
		sfText_setString(game->scene[2].objs[3].text, tempo);
	}
	if (map[md->draw[1]][md->draw[0]][0] == '7' &&
	map[md->draw[1]][md->draw[0]][1] == '2' && game->second_quest == 0)
		sfText_setString(game->scene[2].objs[2].text, "A floating one");
}

void check_fight_2(game_t *game, char ***map, draw_t *md, char *tempo)
{
	game->quest_involved = 1;
	fight(game);
	game->first_quest++;
	sfText_setString(game->scene[2].objs[3].text, tempo);
	map[md->draw[1] - 1][md->draw[0]][0] = '0';
	map[md->draw[1] - 1][md->draw[0]][1] = '0';
	map[md->draw[1]][md->draw[0]][0] = '0';
	map[md->draw[1]][md->draw[0]][1] = '0';
	map[md->draw[1] + 1][md->draw[0]][0] = '0';
	map[md->draw[1] + 1][md->draw[0]][1] = '0';
}

void handle_xp_winnings(game_t *game)
{
	float won_xp = 0;

	for (int i = 1; i != 4; i++)
		won_xp += (game->boat[i].attack + game->boat[i].def +
		game->boat[i].speed) / 2.5;
	game->boat[0].xp += (won_xp / (game->difficulty / 2)) * 19;
}

void handle_level_up(game_t *game)
{
	int save = 0;

	if (game->boat[0].xp > 100) {
		save = game->boat[0].xp - 100;
		game->boat[0].xp = save;
		game->boat[0].skill_token += 2;
	}
}
