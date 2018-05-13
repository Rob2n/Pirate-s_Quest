/*
** EPITECH PROJECT, 2018
** callback
** File description:
** callback4
*/

#include "my.h"

void change_volume_2(int *volume, game_t *game)
{
	if (*volume == 30) {
		game->scene[3].buttons[1].texture =
		sfTexture_createFromFile("assets/volume_2.png", NULL);
		game->scene[3].buttons[1].texture_hovered =
		sfTexture_createFromFile("assets/volume_2_h.png", NULL);
		*volume = 60;
	} else if (*volume == 60) {
		game->scene[3].buttons[1].texture =
		sfTexture_createFromFile("assets/volume_max.png", NULL);
		game->scene[3].buttons[1].texture_hovered =
		sfTexture_createFromFile("assets/volume_max_h.png", NULL);
		*volume = 90;
	}
}

void apply_volume(game_t *game, int volume)
{
	sfMusic_setVolume(game->music->menu, volume);
	sfMusic_setVolume(game->music->boss, volume);
	sfMusic_setVolume(game->music->fight, volume);
	sfMusic_setVolume(game->music->end, volume);
	sfMusic_setVolume(game->music->canon, volume);
	sfMusic_setVolume(game->music->boarding, volume);
	sfMusic_setVolume(game->music->repair, volume);
	sfMusic_setVolume(game->music->mortar, volume);
}

void change_volume(game_t *game)
{
	static int volume = 90;

	if (volume == 90) {
		game->scene[3].buttons[1].texture =
		sfTexture_createFromFile("assets/volume_0.png", NULL);
		game->scene[3].buttons[1].texture_hovered =
		sfTexture_createFromFile("assets/volume_0_h.png", NULL);
		volume = 0;
	} else if (volume == 0) {
		game->scene[3].buttons[1].texture =
		sfTexture_createFromFile("assets/volume_1.png", NULL);
		game->scene[3].buttons[1].texture_hovered =
		sfTexture_createFromFile("assets/volume_1_h.png", NULL);
		volume = 30;
	} else
		change_volume_2(&volume, game);
	apply_volume(game, volume);
}

void change_bool(int *my_bool, game_t *game)
{
	if (*my_bool == 1) {
		game->scene[3].buttons[0].texture =
		sfTexture_createFromFile("assets/smooth_graphics_on.png",
		NULL);
		game->scene[3].buttons[0].texture_hovered =
		sfTexture_createFromFile("assets/smooth_graphics_on_h.png",
		NULL);
		*my_bool = 0;
	} else {
		game->scene[3].buttons[0].texture =
		sfTexture_createFromFile("assets/smooth_graphics_off.png",
		NULL);
		game->scene[3].buttons[0].texture_hovered =
		sfTexture_createFromFile("assets/smooth_graphics_off_h.png",
		NULL);
		*my_bool = 1;
	}
}

void change_graphics(game_t *game)
{
	sfTexture *texture;
	static int my_bool = 1;

	for (int i = 0; i != NB_SCENES; i++) {
		for (int j = 0; j != game->scene[i].nb_buttons; j++) {
			sfTexture_setSmooth(game->scene[i].buttons[j].texture,
			my_bool);
			sfTexture_setSmooth(
			game->scene[i].buttons[j].texture_hovered,
			my_bool);
		}
		for (int k = 0; k != game->scene[i].nb_objs ; k++) {
			texture = sfTexture_createFromFile(
			game->scene[i].objs[k].texture_path, NULL);
			sfTexture_setSmooth(texture, my_bool);
			sfSprite_setTexture(game->scene[i].objs[k].sprite,
			texture, sfTrue);
		}
	}
	change_bool(&my_bool, game);
}