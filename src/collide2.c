/*
** EPITECH PROJECT, 2018
** my
** File description:
** rpg
*/

#include "my.h"

void check_third_quest3(game_t *game)
{
	if (game->third_quest == 2) {
		sfText_setString(game->scene[2].objs[2].text,
		"Thanks for helping me\n+30xp + 1point");
		sfText_setString(game->scene[2].objs[3].text, " ");
		game->quest_involved = 0;
		game->boat[0].skill_token++;
		game->third_quest++;
		game->food = 100;
		game->boat[0].xp += 20;
	}
}

void check_third_quest_2(game_t *game, char *tempo)
{
	if (game->quest_involved != 0)
		sfText_setString(game->scene[2].objs[2].text,
		"Finish your before you can come back");
	else if (game->third_quest == 0) {
		sfSprite_setTexture(game->scene[8].objs[0].sprite,
		game->third_qtextu, sfTrue);
		game->third_quest = 1;
		game->quest_involved = 3;
		sfText_setString(game->scene[2].objs[3].text, tempo);
		quest(game);
	}
	check_third_quest3(game);
}

void check_third_quest(game_t *game, char ***map, draw_t *md)
{
	char *tempo = malloc(sizeof(char) * 15);

	tempo[0] = '\0';
	tempo = my_strcat(tempo, "Objective: ");
	tempo[10] = game->third_quest + 48;
	tempo = my_strcat(tempo, "/1 bottle");
	tempo[21] = '\0';
	if (my_strcmp(map[md->draw[1]][md->draw[0]], "75") == 0)
		check_third_quest_2(game, tempo);
	if (my_strcmp(map[md->draw[1]][md->draw[0]], "27") == 0 &&
	game->third_quest == 1) {
		map[md->draw[1]][md->draw[0]][0] = '0';
		map[md->draw[1]][md->draw[0]][1] = '0';
		game->third_quest++;
		sfText_setString(game->scene[2].objs[3].text, tempo);
	}
	if (my_strcmp(map[md->draw[1]][md->draw[0]], "27") == 0
	&& game->third_quest == 0) {
		sfText_setString(game->scene[2].objs[2].text, "A floating one");
	}
}

void check_second_quest_3(game_t *game)
{
	if (game->second_quest == 7) {
		sfText_setString(game->scene[2].objs[2].text,
		"Thanks for helping me\n+30xp + 1point");
		sfText_setString(game->scene[2].objs[3].text, " ");
		game->quest_involved = 0;
		game->second_quest++;
		game->boat[0].skill_token++;
		game->food = 100;
		game->boat[0].xp += 20;
	}
}

void check_second_quest_2(game_t *game, char *tempo)
{
	if (game->quest_involved != 0) {
		sfText_setString(game->scene[2].objs[2].text,
		"Finish the quest");
	} else if (game->second_quest == 0) {
		sfSprite_setTexture(game->scene[8].objs[0].sprite,
		game->second_qtextu, sfTrue);
		game->second_quest = 1;
		game->quest_involved = 2;
		sfText_setString(game->scene[2].objs[3].text, tempo);
		quest(game);
	}
	check_second_quest_3(game);
}
