/*
** EPITECH PROJECT, 2018
** draw
** File description:
** draw
*/

#include "my.h"

void check_end_fight_2(game_t *game)
{
	game->current_scene = 2;
	game->scene[4].buttons[0].callback = 1;
	game->boat[1].life = 100;
	game->boat[2].life = 100;
	game->boat[3].life = 100;
	game->fight_turn = 0;
	game->anim = 0;
	game->maitre_ruben = 0;
	for (int i = 1; i != 5; i++)
		game->scene[6].buttons[i].active = 0;
	game->difficulty += 2;
	handle_xp_winnings(game);
	if (sfMusic_getStatus(game->music->fight) == sfPlaying) {
		sfMusic_stop(game->music->fight);
		sfMusic_play(game->music->menu);
	}
	game->speed = 0;
	if (game->boss == 0)
		goto_credits(game);
}

void check_end_fight(game_t *game)
{
	int nb_dead_boats = 0;

	for (int i = 1; i < game->nb_boats_fight + 1; i++)
		if (game->boat[i].life <= 0)
			nb_dead_boats++;
	if (nb_dead_boats == 3)
		check_end_fight_2(game);
	if (game->boat[0].life <= 0) {
		for (int i = 1; i != 4; i++)
			game->boat[i].life = 100;
		game->current_scene = 7;
		game->fight_turn = -1;
		if (sfMusic_getStatus(game->music->fight) == sfPlaying ||
		sfMusic_getStatus(game->music->boss) == sfPlaying) {
			sfMusic_stop(game->music->fight);
			sfMusic_stop(game->music->boss);
			sfMusic_play(game->music->end);
		}
	}
}

int fight_draw(game_t *game)
{
	sfVector2f scale = {0.5, 0.5};

	if (game->current_scene == 6) {
		handle_parallax(game, 6, 0, 1);
		sfSprite_setScale(game->scene[6].objs[2].sprite, scale);
		sfSprite_setScale(game->scene[6].objs[3].sprite, scale);
		sfSprite_setScale(game->scene[6].objs[4].sprite, scale);
		sfSprite_setScale(game->scene[6].objs[5].sprite, scale);
		if (game->boss == 1)
			fight_draw_2(game);
		fight_draw_3(game);
	}
	return (0);
}

void fight_draw_3(game_t *game)
{
	sfIntRect cooldown_bar = {0, 0, 190, 49};

	for (int i = 1; i != 5; i++) {
		if (i == 3) {
			cooldown_bar.width = game->scene[6].buttons[i].active
			* 47;
		} else {
			cooldown_bar.width = game->scene[6].buttons[i].active
			* 95;
		}
		sfSprite_setTextureRect(game->scene[6].objs[i + 15].sprite,
		cooldown_bar);
	}
}

void fight_draw_2(game_t *game)
{
	for (int i = 5; i != game->nb_boats_fight + 5; i++) {
		if (game->boat[i - 4].life <= 65 &&
		game->boat[i - 4].life > 40) {
			game->scene[6].buttons[i].texture =
			game->boat[i - 4].second;
			game->scene[6].buttons[i].texture_hovered =
			game->boat[i - 4].second_h;
		} else if (game->boat[i - 4].life <= 40) {
			game->scene[6].buttons[i].texture =
			game->boat[i - 4].third;
			game->scene[6].buttons[i].texture_hovered =
			game->boat[i - 4].third_h;
		} else {
			game->scene[6].buttons[i].texture =
			game->boat[i - 4].first;
			game->scene[6].buttons[i].texture_hovered =
			game->boat[i - 4].first_h;
		}
	}
}