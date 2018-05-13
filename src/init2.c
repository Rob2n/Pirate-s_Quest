/*
** EPITECH PROJECT, 2018
** init
** File description:
** init2
*/

#include "my.h"

void init_objs_2(game_object_t *objs, char **line)
{
	sfVector2f pos = {my_getnbr(line[1]), my_getnbr(line[2])};

	objs->sprite = sfSprite_create();
	objs->texture_path = line[0];
	sfSprite_setTexture(objs->sprite,
	sfTexture_createFromFile(line[0], NULL), sfTrue);
	sfSprite_setPosition(objs->sprite, pos);
}

void init_objs(game_object_t *objs, char **line)
{
	int count = 0;
	sfVector2f pos = {my_getnbr(line[1]), my_getnbr(line[2])};

	init_objs_2(objs, line);
	if (line[3])
		sfSprite_setRotation(objs->sprite, my_getnbr(line[3]));
	for (; line[count]; count++);
	objs->str = NULL;
	if (count == 5) {
		objs->str = line[4];
		objs->text = sfText_create();
		sfText_setFont(objs->text ,
		sfFont_createFromFile("assets/roboto.ttf"));
		sfText_setCharacterSize(objs->text , 25);
		sfText_setString(objs->text , line[4]);
		sfText_setPosition(objs->text , pos);
	}
}

void init_button(button_t *button, char **line)
{
	sfVector2f pos = {my_getnbr(line[2]), my_getnbr(line[3])};

	button->texture = sfTexture_createFromFile(line[0], NULL);
	button->texture_hovered = sfTexture_createFromFile(line[1], NULL);
	button->sprite = sfSprite_create();
	button->callback = my_getnbr(line[4]);
	sfSprite_setTexture(button->sprite, button->texture, sfTrue);
	sfSprite_setPosition(button->sprite, pos);
	button->active = 0;
}

void create_my_scene_bis(scene_t *scene, FILE *stream)
{
	char **parsed_line = NULL;
	char *line = NULL;
	size_t len = 0;
	int read = 0;

	for (int i = 0; i != scene->nb_objs; i++) {
		read = getline(&line, &len, stream);
		line[read - 1] = '\0';
		parsed_line = conv_array(line, ' ');
		init_objs(&(scene->objs[i]), parsed_line);
	}
	for (int i = 0; i != scene->nb_buttons; i++) {
		read = getline(&line, &len, stream);
		line[read - 1] = '\0';
		parsed_line = conv_array(line, ' ');
		init_button(&(scene->buttons[i]), parsed_line);
	}
}

int create_my_scene(scene_t *scene, FILE *stream)
{
	char *line = NULL;
	char **parsed_line = NULL;
	size_t len = 0;

	if (stream == NULL)
		return (1);
	getline(&line, &len, stream);
	parsed_line = conv_array(line, ' ');
	scene->nb_objs = my_getnbr(parsed_line[0]);
	scene->nb_buttons = my_getnbr(parsed_line[1]);
	scene->objs = malloc(sizeof(game_object_t) * scene->nb_objs);
	scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons);
	create_my_scene_bis(scene, stream);
	return (0);
}