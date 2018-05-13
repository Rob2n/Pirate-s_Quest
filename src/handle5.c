/*
** EPITECH PROJECT, 2018
** handle
** File description:
** handle3
*/

#include "my.h"

void update_inventory(game_t *game)
{
	sfVector2f pos = {0, 0};
	sfTime time = sfClock_getElapsedTime(game->clock);
	float secs = (time.microseconds / 1000000.0);

	handle_level_up(game);
	if (game->current_scene != 6 && secs > 1 && game->food != 0 &&
	game->boat[0].life < 100 && game->current_scene != 3 &&
	game->current_scene != 4) {
		sfClock_restart(game->clock);
		game->food -= 1;
		game->boat[0].life += 2;
	}
	if (game->current_scene == 5) {
		update_inventory2(game, pos);
		update_inventory3(game, pos);
	}
	update_inventory4(game);
}

void handle_cinematics2(game_t *game, sfVector2f decal, float rot,
int move_title)
{
	sfText_setString(game->scene[10].objs[8].text,
	"Press SPACEBAR to skip ...");
	for (int i = 1; i != 8; i++) {
		sfSprite_move(game->scene[10].objs[i].sprite, decal);
		sfSprite_setRotation(game->scene[10].objs[i].sprite,
		rot);
	}
	if (move_title == 1)
		sfSprite_move(game->scene[10].objs[9].sprite, decal);
}

void handle_cinematics(game_t *game)
{
	static sfVector2f decal = {5, 0};
	sfVector2f pos = {1300, 170};
	static int limit = 1150;
	static float rot = -90;
	static int move_title = 0;

	if (game->current_scene == 10) {
		handle_cinematics2(game, decal, rot, move_title);
		if (sfSprite_getPosition(game->scene[10].objs[1].sprite).x >
		limit && move_title == 0) {
			limit = -920;
			rot = 90;
			decal.x = -6;
			move_title = 1;
			sfSprite_setPosition(game->scene[10].objs[9].sprite, pos);
		}
		if (sfSprite_getPosition(game->scene[10].objs[1].sprite).x <
		limit && limit == -920)
			goto_menu(game);
	}
}

void handle_fight_turns(game_t *game)
{
	if (game->fight_turn != 0 && game->anim == 0) {
		play_ai(game);
	}
}
void stat_att(game_t *game)
{
	if (game->boat[0].attack < 10 && game->boat[0].skill_token != 0) {
		game->boat[0].attack++;
		game->boat[0].skill_token--;
	}
}