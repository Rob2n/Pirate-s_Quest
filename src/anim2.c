/*
** EPITECH PROJECT, 2018
** anim
** File description:
** fight
*/

#include "my.h"

void apply_damage_bad(game_t *game, int current_boat)
{
	int random = rand() % 100;

	if (random < 5 * (0.7 * game->boat[0].speed))
		game->esquive = 1;
	if (game->attack_stat[current_boat][0] == 0 &&
	game->attack_stat[game->current_boat][2] == 0)
		game->boat[0].life -= game->boat[current_boat + 1].attack -
		(game->boat[0].def * 0.3);
	if (game->attack_stat[current_boat][0] == 1 &&
	game->attack_stat[game->current_boat][2] == 0)
		game->boat[0].life -= game->boat[current_boat + 1].attack -
		(game->boat[0].def * 0.3);
	if (game->attack_stat[current_boat][0] == 2 &&
	game->attack_stat[game->current_boat][2] == 0)
		game->boat[0].life -= game->boat[current_boat + 1].attack -
		(game->boat[0].def * 0.3);
}

void handle_sounds_bad2(game_t *game, int *my_bool_music)
{
	if (*my_bool_music != game->current_boat &&
	game->attack_stat[game->current_boat][0] == 2) {
		sfMusic_play(game->music->boarding);
		*my_bool_music = game->current_boat;
	} else if (*my_bool_music != game->current_boat &&
	game->attack_stat[game->current_boat][0] == 3) {
		sfMusic_play(game->music->repair);
		*my_bool_music = game->current_boat;
	}
}

void handle_sounds_bad(game_t *game, int *my_bool_music)
{
	if (*my_bool_music != game->current_boat &&
	game->attack_stat[game->current_boat][0] == 0) {
		sfMusic_play(game->music->canon);
		*my_bool_music = game->current_boat;
	} else if (*my_bool_music != game->current_boat &&
	game->attack_stat[game->current_boat][0] == 1) {
		sfMusic_play(game->music->mortar);
		*my_bool_music = game->current_boat;
	} else
		handle_sounds_bad2(game, my_bool_music);
}

void handle_flames_bad(game_t *game)
{
	sfVector2f scale = {1.3, 1.3};
	int limit = 200;

	if (sfSprite_getPosition(game->scene[6].objs[
	game->attack_stat[game->current_boat][0] + 12].sprite).x > limit * 2 &&
	game->attack_stat[game->current_boat][2] == 0) {
		sfSprite_setScale(game->scene[6].objs[11].sprite, scale);
		sfSprite_setTexture(game->scene[6].objs[11].sprite,
		sfTexture_createFromFile("assets/fire_ll.png", NULL), sfTrue);
	} else if (sfSprite_getPosition(game->scene[6].objs[
	game->attack_stat[game->current_boat][0] + 12].sprite).x < limit * 2 &&
	game->attack_stat[game->current_boat][2] == 0) {
		sfSprite_setScale(game->scene[6].objs[11].sprite, scale);
		sfSprite_setTexture(game->scene[6].objs[11].sprite,
		sfTexture_createFromFile("assets/fire_l.png", NULL), sfTrue);
	}
	if (game->attack_stat[game->current_boat][2] == 1) {
		sfText_setColor(game->scene[6].objs[15].text, sfRed);
		sfText_setString(game->scene[6].objs[15].text, "     Dodged!");
	}
}

void reset_anims_bad2(game_t *game, sfVector2f pos,
int *my_bool_music, sfVector2f pos_f)
{
	sfText_setString(game->scene[6].objs[15].text, "       ");
	sfSprite_setTexture(game->scene[6].objs[11].sprite,
	sfTexture_createFromFile("assets/void.png", NULL), sfTrue);
	for (int i = 0; i != 3; i++)
		sfSprite_setPosition(game->scene[6].objs[12 + i].sprite, pos);
	sfSprite_setPosition(game->scene[6].objs[11].sprite, pos_f);
	*my_bool_music = -1;
	if (game->boat[game->current_boat + 1].life > 0)
		apply_damage_bad(game, game->current_boat);
	game->current_boat++;
	if (game->current_boat == 3) {
		game->maitre_ruben = game->fight_turn;
		game->anim = 0;
		game->current_boat = 0;
	}
}