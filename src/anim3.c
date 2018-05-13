/*
** EPITECH PROJECT, 2018
** anim
** File description:
** fight
*/

#include "my.h"

void reset_anims_bad(game_t *game, int *my_bool_music)
{
	sfVector2f pos = {-12, 0};
	sfVector2f pos_f = {580, 130};

	if (game->current_boat == 0) {
		pos.x = 515;
		pos.y = 245;
		pos_f.x = 470;
		pos_f.y = 265;
	} else if (game->current_boat == 2) {
		pos.x = 635;
		pos.y = 110;
	} else {
		pos.x = 635;
		pos.y = 370;
		pos_f.y = 400;
	}
	reset_anims_bad2(game, pos, my_bool_music, pos_f);
}

void handle_aiming_bad(game_t *game, sfVector2f *pos)
{
	if (game->current_boat == 0)
		(*pos).y = 4;
	else if (game->current_boat == 2)
		(*pos).y = -3;
}

void do_anim_bad(game_t *game)
{
	sfTime time = sfClock_getElapsedTime(game->clock);
	float miliseconds = (time.microseconds / 10000000.0);
	int limit = 200;
	sfVector2f pos = {-12, 0};
	static int my_bool_music = -1;

	handle_aiming_bad(game, &pos);
	if (miliseconds > 0.001) {
		if (sfSprite_getPosition(game->scene[6].objs
		[game->attack_stat[game->current_boat][0] + 12].sprite).x >
		limit && game->boat[game->current_boat + 1].life > 0) {
			handle_flames_bad(game);
			handle_sounds_bad(game, &my_bool_music);
			sfSprite_move(game->scene[6].objs[game->attack_stat
			[game->current_boat][0] + 12].sprite, pos);
		} else {
			reset_anims_bad(game, &my_bool_music);
		}
		sfClock_restart(game->clock);
	}
}

void do_anim_repair_f(game_t *game)
{
	sfTime time = sfClock_getElapsedTime(game->clock);
	float miliseconds = (time.microseconds / 10000000.0);
	int limit = 200;
	sfVector2f reset = {200, 250};
	sfVector2f move = {-1, 0};

	if (miliseconds > 0.001) {
		if (sfSprite_getPosition(game->scene[6].objs[20].sprite).x >
		limit) {
			sfSprite_rotate(game->scene[6].objs[20].sprite, 2);
			sfSprite_move(game->scene[6].objs[20].sprite, move);
		} else {
			sfSprite_setPosition(game->scene[6].objs[20].sprite,
			reset);
			game->maitre_ruben = game->fight_turn;
			game->anim = 0;
			apply_damage_friend(game);
		}
		sfClock_restart(game->clock);
	}
}

void do_anim(game_t *game)
{
	if (game->anim == 1 && game->current_scene == 6 && game->maitre_ruben
	!= game->fight_turn) {
		if (game->fight_turn == 1 && game->attack != 3)
			do_anim_friendly(game, game->attack);
		if (game->fight_turn == 0)
			do_anim_bad(game);
		if (game->attack == 3) {
			do_anim_repair_f(game);
		}
	}
}