/*
** EPITECH PROJECT, 2018
** anim
** File description:
** fight
*/

#include "my.h"

void handle_aiming_f(game_t *game, sfVector2f *pos, int *limit, float *rot)
{
	if (game->selected_boat == 1) {
		(*pos).y = -4;
		*rot = 60;
		*limit = 650;
	} else if (game->selected_boat == 3) {
		(*pos).y = 4;
		*rot = 120;
		*limit = 650;
	}
}

void handle_flames_f(game_t *game, int limit, float rot, int attack)
{
	sfVector2f scale = {1.3, 1.3};

	if (sfSprite_getPosition(game->scene[6].objs
	[attack + 8].sprite).x < limit / 2) {
		sfSprite_setScale(game->scene[6].objs[7].sprite, scale);
		sfSprite_setRotation(game->scene[6].objs[7].sprite, rot);
		sfSprite_setTexture(game->scene[6].objs[7].sprite,
		sfTexture_createFromFile("assets/fire_ll.png", NULL), sfTrue);
	} else if (sfSprite_getPosition(game->scene[6].objs
	[attack + 8].sprite).x > limit / 2) {
		sfSprite_setScale(game->scene[6].objs[7].sprite, scale);
		sfSprite_setRotation(game->scene[6].objs[7].sprite, rot);
		sfSprite_setTexture(game->scene[6].objs[7].sprite,
		sfTexture_createFromFile("assets/fire_l.png", NULL), sfTrue);
	}
}

void reset_anims_f(game_t *game, int attack)
{
	sfVector2f pos = {12, 0};

	game->maitre_ruben = game->fight_turn;
	apply_damage_friend(game);
	game->anim = 0;
	pos.x = 200;
	pos.y = 250;
	sfSprite_setTexture(game->scene[6].objs[7].sprite,
	sfTexture_createFromFile("assets/void.png", NULL), sfTrue);
	sfSprite_setPosition(game->scene[6].objs[attack + 8].sprite, pos);
}

void do_anim_friendly(game_t *game, int attack)
{
	sfTime time = sfClock_getElapsedTime(game->clock);
	float miliseconds = (time.microseconds / 10000000.0);
	int limit = 520;
	float rot = 90;
	sfVector2f pos = {12, 0};

	handle_aiming_f(game, &pos, &limit, &rot);
	if (miliseconds > 0.001) {
		sfSprite_rotate(game->scene[6].objs[attack + 8].sprite, 5);
		if (sfSprite_getPosition(game->scene[6].objs
		[attack + 8].sprite).x < limit) {
			handle_flames_f(game, limit, rot, attack);
			sfSprite_move(game->scene[6].objs
			[attack + 8].sprite, pos);
		} else {
			reset_anims_f(game, attack);
		}
		sfClock_restart(game->clock);
	}
}

void apply_damage_friend(game_t *game)
{
	if (game->attack == 0)
		game->boat[game->selected_boat].life -= 10 +
		(1.5 * game->boat[0].attack);
	if (game->attack == 1)
		game->boat[game->selected_boat].life -= 20 +
		(1.5 * game->boat[0].attack);
	if (game->attack == 2)
		game->boat[game->selected_boat].life -= 30 +
		(1.5 * game->boat[0].attack);
	if (game->attack == 3)
		game->boat[0].life += 20 + game->boat[0].def;
}