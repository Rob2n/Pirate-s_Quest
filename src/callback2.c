/*
** EPITECH PROJECT, 2018
** callback
** File description:
** callback2
*/

#include "my.h"

void quit(game_t *game)
{
	sfMusic_destroy(game->music->menu);
	sfMusic_destroy(game->music->boss);
	sfMusic_destroy(game->music->fight);
	sfMusic_destroy(game->music->end);
	sfMusic_destroy(game->music->canon);
	sfMusic_destroy(game->music->repair);
	sfMusic_destroy(game->music->mortar);
	sfMusic_destroy(game->music->boarding);
	sfRenderWindow_close(game->window);
}

void goto_game(game_t *game)
{
	game->prev_scene = game->current_scene;
	game->current_scene = 2;
}

void goto_options(game_t *game)
{
	game->prev_scene = game->current_scene;
	game->current_scene = 3;
}

void goto_last_scene(game_t *game)
{
	int save = game->prev_scene;

	game->prev_scene = game->current_scene;
	game->current_scene = save;
}

void goto_pause(game_t *game)
{
	game->prev_scene = game->current_scene;
	game->current_scene = 4;
}