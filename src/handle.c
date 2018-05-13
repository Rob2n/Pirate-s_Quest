/*
** EPITECH PROJECT, 2018
** handle
** File description:
** handle
*/

#include "my.h"

void handle_keys_2(game_t *game)
{
	if (game->event.key.code == sfKeyEscape && (game->current_scene == 2 ||
	game->current_scene == 6)) {
		game->callbacks[4].callback(game);
	} else if (game->event.key.code == sfKeyEscape &&
		game->current_scene == 4) {
		game->callbacks[3].callback(game);
	}
}

void handle_keys(game_t *game)
{
	handle_keys_2(game);
	if (game->current_scene == 5 && game->event.key.code == sfKeyE) {
		game->callbacks[3].callback(game);
	} else if (game->current_scene == 2 &&
		game->event.key.code == sfKeyE) {
		game->callbacks[9].callback(game);
	}
	if (game->event.key.code == sfKeyQ && game->current_scene == 2) {
		quest(game);
	} else if (game->event.key.code == sfKeyQ && game->current_scene == 8)
		goto_game(game);
	if (game->event.key.code == sfKeyM && game->current_scene == 2)
		goto_map(game);
	else if (game->event.key.code == sfKeyM && game->current_scene == 9)
		goto_game(game);
	if (game->event.key.code == sfKeySpace && game->current_scene == 10)
		goto_menu(game);
}

void cursor_handle(game_t *game)
{
	sfVector2f pos;

	pos.x = game->event.mouseMove.x - 5;
	pos.y = game->event.mouseMove.y - 5;

	sfSprite_setPosition(game->cursor, pos);
}

int event_handler(game_t *game)
{
	if (game->event.type == sfEvtClosed)
		quit(game);
	if (game->event.type == sfEvtMouseButtonPressed)
		check_buttons(game);
	if (game->event.type == sfEvtKeyPressed) {
		if (game->current_scene == 2)
			handle_player_movement(game->event, game);
		handle_keys(game);
	}
	if (game->event.type == sfEvtMouseMoved)
		cursor_handle(game);
	return (0);
}

void handle_ship_menu_anim(game_t *game)
{
	static float rotate = 0;
	static int switcher = 0;
	sfVector2f move = {0, 0};
	float sprite_rot = sfSprite_getRotation(game->scene[0].objs[1].sprite);

	if (sprite_rot >= 275)
		switcher = 0;
	if (sprite_rot <= 265)
		switcher = 1;
	if (switcher == 1)
		rotate = 0.08;
	else
		rotate = -0.08;
	move.y = -0.25;
	if (sprite_rot > 270)
		move.y = 0.25;
	for (int i = 1; i != 5; i++) {
		sfSprite_move(game->scene[0].objs[i].sprite, move);
		sfSprite_rotate(game->scene[0].objs[i].sprite, rotate);
	}
}