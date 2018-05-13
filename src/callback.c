/*
** EPITECH PROJECT, 2018
** callback
** File description:
** callback1
*/

#include "my.h"

void mortier(game_t *game)
{
	if (game->fight_turn == 0 && game->boat[game->selected_boat].life > 0
	&& game->anim == 0) {
		game->attack = 1;
		game->fight_turn = 1;
		game->anim = 1;
		handle_cooldown(game);
		game->scene[6].buttons[2].active = 2;
		sfMusic_play(game->music->mortar);
	}
}

void bordage(game_t *game)
{
	if (game->fight_turn == 0 && game->boat[game->selected_boat].life > 0
	&& game->anim == 0) {
		game->attack = 2;
		game->fight_turn = 1;
		game->anim = 1;
		handle_cooldown(game);
		sfMusic_play(game->music->boarding);
		game->scene[6].buttons[3].active = 4;
	}
}

void defence(game_t *game)
{
	sfVector2f mitroglou = {280, 250};

	if (game->boat[0].life + 5 <= 100 && game->fight_turn == 0
	&& game->anim == 0) {
		game->attack = 3;
		game->fight_turn = 1;
		game->anim = 1;
		handle_cooldown(game);
		game->scene[6].buttons[4].active = 2;
		sfSprite_setPosition(game->scene[6].objs[20].sprite,
		mitroglou);
		sfSprite_setRotation(game->scene[6].objs[20].sprite, 0);
		sfMusic_play(game->music->repair);
	}
}

void boss_fight2(game_t *game)
{
	sfVector2f aim_pos = {536, 45};

	sfSprite_setPosition(game->scene[6].objs[6].sprite, aim_pos);
	for (int i = 1; i != 4; i++)
		game->boat[i].attack = (rand() % game->difficulty) + 4;
	for (int i = 1; i != 4; i++)
		game->boat[i].def = (rand() % game->difficulty) + 4;
	for (int i = 1; i != 4; i++)
		game->boat[i].speed = (rand() % game->difficulty) + 4;
}

void boss_fight(game_t *game)
{
	sfVector2f click_pos = {541, 45};
	sfTexture *t = sfTexture_createFromFile("assets/void_ship.png", NULL);
	sfVector2f bars_pos = {541, 65};

	game->prev_scene = game->current_scene;
	game->boss = 0;
	game->current_scene = 6;
	game->scene[4].buttons[0].callback = 12;
	game->nb_boats_fight = 3;
	for (int i = 5; i != 8; i++) {
		game->scene[6].buttons[i].texture = t;
		game->scene[6].buttons[i].texture_hovered = t;
		sfSprite_setPosition(game->scene[6].buttons[i].sprite,
		click_pos);
		sfSprite_setPosition(game->scene[6].objs[i - 2].sprite,
		bars_pos);
		click_pos.y += 150;
		bars_pos.y += 110;
	}
	boss_fight2(game);
}