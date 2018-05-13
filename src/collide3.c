/*
** EPITECH PROJECT, 2018
** my
** File description:
** rpg
*/

#include "my.h"

void check_final_quest(game_t *game)
{
	if (game->first_quest == 5 && game->second_quest == 8 &&
	game->third_quest == 3)
		goto_boss_cinematic(game);
	else
		sfText_setString(game->scene[2].objs[2].text,
		"Go help my friend first");
}

void check_cell3(game_t *game, char ***map, draw_t *md)
{
	if (my_strcmp(map[md->draw[1]][md->draw[0]], "75") == 0 ||
	my_strcmp(map[md->draw[1]][md->draw[0]], "27") == 0) {
		check_third_quest(game, map, md);
	}
	if (map[md->draw[1]][md->draw[0]][0] == '8') {
		check_fight(game, map, md);
	} else if (my_strcmp(map[md->draw[1]][md->draw[0]], "71") == 0)
		check_quest(game, map, md);
	else if (my_strcmp(map[md->draw[1]][md->draw[0]],
	"74") == 0 || my_strcmp(map[md->draw[1]][md->draw[0]], "72") == 0)
		check_second_quest(game, map, md);
	else if (my_strcmp(map[md->draw[1]][md->draw[0]], "46") == 0)
		check_final_quest(game);
	else
		game->boat[0].life--;
}

int check_fight(game_t *game, char ***map, draw_t *md)
{
	char *tempo = malloc(sizeof(char) * 30);

	tempo[0] = '\0';
	tempo = my_strcat(tempo, "Objective: ");
	tempo[10] = game->first_quest + 48;
	tempo = my_strcat(tempo, "/3 boat");
	tempo[19] = '\0';
	if ((map[md->draw[1]][md->draw[0]][1] == '7' ||
	map[md->draw[1]][md->draw[0]][1] == '8') && game->first_quest > 0) {
		check_fight_2(game, map, md, tempo);
		return (1);
	} else if ((map[md->draw[1]][md->draw[0]][1] == '7' ||
	map[md->draw[1]][md->draw[0]][1] == '8') && game->first_quest == 0) {
		sfText_setString(game->scene[2].objs[2].text,
		"Go see the pirate at the dock");
	} else
		game->boat[0].life--;
	return (0);
}

void check_quest_2(game_t *game, char *tempo)
{
	sfSprite_setTexture(game->scene[8].objs[0].sprite,
	game->first_qtextu, sfTrue);
	game->first_quest = 1;
	game->quest_involved = 1;
	sfText_setString(game->scene[2].objs[3].text, tempo);
	quest(game);
}

void check_quest(game_t *game, char ***map, draw_t *md)
{
	char *tempo = malloc(sizeof(char) * 15);

	tempo[0] = '\0';
	tempo = my_strcat(tempo, "Objective: ");
	tempo[10] = game->first_quest + 48;
	tempo = my_strcat(tempo, "/3 boat");
	tempo[19] = '\0';
	if (game->first_quest == 0) {
		check_quest_2(game, tempo);
	} else if (game->first_quest == 4 && game->quest_involved == 1) {
		sfText_setString(game->scene[2].objs[2].text,
		"Thanks for helping me\n+30xp + 1point");
		sfText_setString(game->scene[2].objs[3].text, " ");
		game->boat[0].xp += 50;
		game->quest_involved = 0;
		map[md->draw[1]][md->draw[0]][0] = '7';
		map[md->draw[1]][md->draw[0]][1] = '0';
		game->first_quest++;
		game->boat[0].skill_token++;
		game->food = 100;
		game->boat[0].xp += 20;
	}
}
