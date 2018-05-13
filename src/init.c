/*
** EPITECH PROJECT, 2018
** init
** File description:
** init1
*/

#include "my.h"

void init_callbacks_2(callback_t *callbacks)
{
	callbacks[15].callback = &bordage;
	callbacks[16].callback = &defence;
	callbacks[17].callback = &focus_boat_1;
	callbacks[18].callback = &focus_boat_2;
	callbacks[19].callback = &focus_boat_3;
	callbacks[20].callback = &stat_att;
	callbacks[21].callback = &stat_def;
	callbacks[22].callback = &stat_speed;
	callbacks[23].callback = &quest;
	callbacks[24].callback = &goto_map;
	callbacks[25].callback = &goto_menu;
	callbacks[26].callback = &goto_boss_cinematic;
	callbacks[27].callback = &goto_how_to;
	callbacks[28].callback = &the_how_to;
	callbacks[29].callback = &goto_credits;
}

callback_t *init_callbacks(void)
{
	callback_t *callbacks = malloc(sizeof(callback_t) * NB_CALLBACKS);

	callbacks[0].callback = &quit;
	callbacks[1].callback = &goto_game;
	callbacks[2].callback = &goto_options;
	callbacks[3].callback = &goto_last_scene;
	callbacks[4].callback = &goto_pause;
	callbacks[5].callback = &goto_select_player;
	callbacks[6].callback = &goto_game_red;
	callbacks[7].callback = &goto_game_blue;
	callbacks[8].callback = &goto_game_yellow;
	callbacks[9].callback = &goto_inventory;
	callbacks[10].callback = &change_volume;
	callbacks[11].callback = &change_graphics;
	callbacks[12].callback = &fight;
	callbacks[13].callback = &canon;
	callbacks[14].callback = &mortier;
	init_callbacks_2(callbacks);
	return (callbacks);
}

scene_t *init_scenes(void)
{
	FILE *stream = fopen("./src/my_sprite_info", "r");
	scene_t *scene = malloc(sizeof(scene_t) * NB_SCENES);

	my_putstr("Loading graphical assets...\n");
	if (scene == NULL)
		return (NULL);
	for (int i = 0; i != NB_SCENES; i++) {
		if (create_my_scene(&(scene[i]), stream) == 1)
			return (NULL);
	}
	return (scene);
}

music_t *init_music(void)
{
	music_t *music = malloc(sizeof(music_t));

	music->menu = sfMusic_createFromFile("assets/music/Port-Royal.ogg");
	sfMusic_setLoop(music->menu, sfTrue);
	music->end = sfMusic_createFromFile("assets/music/end.ogg");
	sfMusic_setLoop(music->end, sfTrue);
	music->fight = sfMusic_createFromFile("assets/music/The-Hunt.ogg");
	music->boss = sfMusic_createFromFile("assets/music/BOSS.ogg");
	sfMusic_setLoop(music->boss, sfTrue);
	if (music->menu != NULL)
		sfMusic_play(music->menu);
	music->canon = sfMusic_createFromFile("assets/music/canon.ogg");
	music->mortar = sfMusic_createFromFile("assets/music/mortar.ogg");
	music->boarding = sfMusic_createFromFile("assets/music/boarding.ogg");
	music->repair = sfMusic_createFromFile("assets/music/repair.ogg");
	return (music);
}

void init_stat_game_1(game_t *game)
{
	game->attack_stat = malloc(sizeof(int*) * 3);
	for (int i = 0; i != 3; i++) {
		game->attack_stat[i] = malloc(sizeof(int) * 3);
		for (int j = 0; j != 3; j++)
			game->attack_stat[i][j] = 0;
	}
	game->boss = 1;
}