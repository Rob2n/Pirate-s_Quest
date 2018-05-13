/*
** EPITECH PROJECT, 2018
** my
** File description:
** rpg
*/

#include "my.h"

char ***parse_map(void)
{
	char ***map = malloc(sizeof(char **) * 110);
	FILE *fd = fopen("./src/map", "r");
	char *line = malloc(391);
	size_t size = 390;

	for (int i = 0; i < 110; i++) {
		getline(&line, &size, fd);
		line[389] = '\0';
		map[i] = conv_array(line, ' ');
	}
	free(line);
	return (map);
}

int check_buttons(game_t *game)
{
	int i = 0;
	sfVector2f mouse_pos = {game->event.mouseButton.x,
		game->event.mouseButton.y};

	while (i != game->scene[game->current_scene].nb_buttons) {
		if (button_is_clicked(game->scene[game->current_scene].
		buttons[i], mouse_pos) && game->scene[game->current_scene]
		.buttons[i].active == 0) {
			game->callbacks[game->scene[game->current_scene].
			buttons[i].callback].callback(game);
			return (0);
		}
		i++;
	}
	return (0);
}

int events(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->window, &(game->event)))
	{
		if (event_handler(game) == 84)
			return (84);
	}
	return (0);
}

int main(__attribute__ ((unused)) int ac, __attribute__ ((unused)) char **av)
{
	scene_t *scene = init_scenes();
	game_t game;

	if (scene == NULL)
		return (84);
	init_game(&game, scene);
	set_scene(&game);
	sfRenderWindow_setFramerateLimit(game.window, 60);
	sfRenderWindow_setMouseCursorVisible(game.window, sfFalse);
	while (sfRenderWindow_isOpen(game.window)) {
		if (events(&game) == 84)
			return (0);
		handle_other_funcs(&game);
		sfRenderWindow_display(game.window);
		sfRenderWindow_clear(game.window, sfBlack);
	}
	return (0);
}