/*
** EPITECH PROJECT, 2018
** callback
** File description:
** callback3
*/

#include "my.h"

void goto_menu(game_t *game)
{
	game->prev_scene = game->current_scene;
	game->current_scene = 0;
}

void goto_game_yellow_2(game_t *game)
{
	game->boat[0].third =
	sfTexture_createFromFile("assets/used_boat/yellow_ship_75p.png", NULL);
	game->boat[0].fourth =
	sfTexture_createFromFile("assets/used_boat/yellow_ship_50p.png", NULL);
	game->boat[0].init =
	sfTexture_createFromFile("assets/yellow_ship_m.png", NULL);
	game->boat[0].small_init =
	sfTexture_createFromFile("assets/yellow_ship.png", NULL);
	game->prev_scene = game->current_scene;
	game->current_scene = 2;
	game->boat[0].attack = 1;
	game->boat[0].def = 1;
	game->boat[0].speed = 1;
}

void goto_game_yellow(game_t *game)
{
	sfSprite_setTexture(game->scene[5].objs[3].sprite,
	sfTexture_createFromFile("assets/yellow_ship_m.png", NULL),
	sfTrue);
	sfSprite_setTexture(game->scene[2].objs[1].sprite,
	sfTexture_createFromFile("assets/yellow_ship.png", NULL),
	sfTrue);
	sfSprite_setTexture(game->scene[6].objs[1].sprite,
	sfTexture_createFromFile("assets/yellow_ship_m.png", NULL),
	sfTrue);
	game->boat[0].first =
	sfTexture_createFromFile("assets/used_boat/yellow_ship_75.png", NULL);
	game->boat[0].second =
	sfTexture_createFromFile("assets/used_boat/yellow_ship_50.png", NULL);
	sfSprite_setTexture(game->scene[11].objs[1].sprite,
	sfTexture_createFromFile("assets/yellow_ship_m.png", NULL),
	sfTrue);
	goto_game_yellow_2(game);
}

void goto_inventory(game_t *game)
{
	sfVector2f scale = {1.5, 1.5};

	game->prev_scene = game->current_scene;
	game->current_scene = 5;
	sfSprite_setScale(game->scene[5].objs[3].sprite, scale);
}

void canon(game_t *game)
{
	if (game->fight_turn == 0 && game->boat[game->selected_boat].life > 0
	&& game->anim == 0) {
		game->attack = 0;
		game->fight_turn = 1;
		game->anim = 1;
		handle_cooldown(game);
		sfMusic_play(game->music->canon);
	}
}