/*
** EPITECH PROJECT, 2018
** handle
** File description:
** handle2
*/

#include "my.h"

void menu_stat2(game_t *game, int i)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
	sfVector2f pos_f = {0, 0};

	if (game->current_scene == 1 && i == 0)
		sfSprite_setTexture(game->cursor,
		game->cursor_stat->cursor_stat_red, sfTrue);
	if (game->current_scene == 1 && i == 1) {
		sfSprite_setTexture(game->cursor,
		game->cursor_stat->cursor_stat_green, sfTrue);
		pos_f.x = pos.x - 350;
		pos_f.y = pos.y;
		sfSprite_setPosition(game->cursor, pos_f);
	}
}

void menu_stat(game_t *game, int i)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
	sfVector2f pos_f;

	menu_stat2(game, i);
	if (game->current_scene == 1 && i == 2)
		sfSprite_setTexture(game->cursor,
		game->cursor_stat->cursor_stat_yellow, sfTrue);
	if (game->current_scene == 1 && i == 3) {
		sfSprite_setTexture(game->cursor,
		game->cursor_stat->cursor_stat_blue,
		sfTrue);
		pos_f.x = pos.x - 350;
		pos_f.y = pos.y;
		sfSprite_setPosition(game->cursor, pos_f);
	}
}

int handle_hovering(game_t *game)
{
	sfSprite_setTexture(game->cursor, game->cursor_text, sfTrue);
	if (game->scene[game->current_scene].nb_buttons == 0)
		return (1);
	for (int i = 0; i != game->scene[game->current_scene].
	nb_buttons; i++) {
		sfSprite_setTexture(game->scene[game->current_scene].
		buttons[i].sprite, game->scene[game->current_scene].
		buttons[i].texture, sfTrue);
		if (button_is_hovered(game->scene[game->current_scene].
			buttons[i],
			sfMouse_getPositionRenderWindow(game->window)) && game
			->scene[game->current_scene].buttons[i].active == 0) {
			sfSprite_setTexture(game->scene[game->current_scene].
				buttons[i].sprite,
				game->scene[game->current_scene].buttons[i].
				texture_hovered, sfTrue);
				menu_stat(game, i);
			}
	}
	return (0);
}

void handle_other_funcs_2(game_t *game)
{
	if (game->boat[0].life <= 65) {
		sfSprite_setTexture(game->scene[6].objs[1].sprite,
		game->boat[0].first, sfTrue);
		sfSprite_setTexture(game->scene[5].objs[3].sprite,
		game->boat[0].first, sfTrue);
		sfSprite_setTexture(game->scene[2].objs[1].sprite,
		game->boat[0].third, sfTrue);
	}
	if (game->boat[0].life <= 40) {
		sfSprite_setTexture(game->scene[6].objs[1].sprite,
		game->boat[0].second, sfTrue);
		sfSprite_setTexture(game->scene[5].objs[3].sprite,
		game->boat[0].second, sfTrue);
		sfSprite_setTexture(game->scene[2].objs[1].sprite,
		game->boat[0].fourth, sfTrue);
	}
	fight_draw(game);
	handle_fight_turns(game);
	check_end_fight(game);
}

void handle_other_funcs(game_t *game)
{
	handle_hovering(game);
	if (game->current_scene == 2)
		apply_inertia(game);
	if (game->current_scene == 0)
		handle_parallax(game, 0, 0, 0);
	if (game->boat[0].life > 65) {
		sfSprite_setTexture(game->scene[6].objs[1].sprite,
		game->boat[0].init, sfTrue);
		sfSprite_setTexture(game->scene[5].objs[3].sprite,
		game->boat[0].init, sfTrue);
		sfSprite_setTexture(game->scene[2].objs[1].sprite,
		game->boat[0].small_init, sfTrue);
	}
	handle_other_funcs_2(game);
	draw_scene(*game);
	update_inventory(game);
	do_anim(game);
	handle_cinematics(game);
	handle_boss_cinematic(game);
}