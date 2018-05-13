/*
** EPITECH PROJECT, 2018
** init
** File description:
** init2
*/

#include "my.h"

void how_to_play_sprite(game_t *game)
{
	game->first_how = sfTexture_createFromFile("assets/control.png", NULL);
	game->second_how = sfTexture_createFromFile("assets/ingame.png", NULL);
	game->third_how = sfTexture_createFromFile("assets/inventory.png",
	NULL);
}

void init_game_3(game_t *game)
{
	game->boat[0].life = 100;
	game->boat[1].life = 100;
	game->boat[2].life = 100;
	game->boat[3].life = 100;
	game->boat[0].attack = 3;
	game->boat[0].def = 0;
	game->boat[0].speed = 0;
	game->food = 100;
	game->difficulty = 3;
	game->maitre_ruben = 0;
	game->anim = 0;
	game->esquive = 0;
	game->attack = 0;
	game->fight_turn = 0;
	game->current_boat = 0;
	game->boat[0].xp = 0;
	init_stat_game_1(game);
	how_to_play_sprite(game);
}

void set_scene(game_t *game)
{
	sfText_setString(game->scene[2].objs[2].text, " ");
	sfText_setString(game->scene[2].objs[3].text, " ");
}

void init_inventory(game_t *game)
{
	sfIntRect health_rect = {0, 0, 250, 31};

	game->inv = malloc(sizeof(game->inv));
	game->inv->health_rect = health_rect;
}