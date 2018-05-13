/*
** EPITECH PROJECT, 2018
** conv
** File description:
** array
*/

#include "my.h"

void draw_cell(char ***map, sfRenderWindow *wd, draw_t *md)
{
	md->path[34] = map[md->draw[1]][md->draw[0]][0];
	md->path[35] = map[md->draw[1]][md->draw[0]][1];
	if (md->path[34] != '0' || md->path[35] != '0') {
		sfTexture_destroy(md->text);
		md->text = sfTexture_createFromFile(md->path, NULL);
		sfSprite_setTexture(md->sprite, md->text, sfTrue);
		sfSprite_setPosition(md->sprite, md->pos);
		sfRenderWindow_drawSprite(wd, md->sprite, NULL);
	}
}
void draw_line(char ***map, sfRenderWindow *wd, draw_t *md)
{
	for (; md->pos.x < 816; md->pos.x += 48) {
		if (md->draw[1] < 0 || md->draw[1] > 109)
			break;
		if (md->draw[0] >= 0 && md->draw[0] < 130)
			draw_cell(map, wd, md);
		md->draw[0]++;
	}
}

void draw_foreground(char ***map, double *perso, sfRenderWindow *wd,
draw_t *md)
{
	for (; md->pos.y < 720; md->pos.y += 48) {
		md->pos.x = (perso[0] - (int)perso[0]) * -48;
		md->pos.x = (md->pos.x > 0) ? -md->pos.x + 48 : md->pos.x;
		draw_line(map, wd, md);
		md->draw[0] = perso[0] - 8;
		md->draw[0] -= (perso[0] < 8 && (perso[0] -
		(int)perso[0]) != 0) ? 1 : 0;
		md->draw[1]++;
	}
}

draw_t *init_draw(double *perso)
{
	draw_t *my_draw = malloc (sizeof (draw_t) * 1);
	sfVector2f pos = {0, 0};
	char path[40] = "./src/PNG/Default\040size/Tiles/tile_73.png";

	my_draw->draw = malloc (sizeof(int) * 2);
	my_draw->draw[0] = perso[0] - 8;
	my_draw->draw[1] = perso[1] - 7;
	my_draw->pos = pos;
	my_draw->path = malloc (41);
	for (int i = 0; i < 40; i++)
		(my_draw->path)[i] = path[i];
	(my_draw->path)[40] = '\0';
	my_draw->text = sfTexture_createFromFile(path, NULL);
	my_draw->sprite = sfSprite_create();
	return (my_draw);
}

void draw_map(char ***map, double *prs, sfRenderWindow *wd)
{
	draw_t *md = init_draw(prs);

	(md->draw)[0] -= (prs[0] < 8 && (prs[0] - (int)prs[0]) != 0) ? 1 : 0;
	(md->draw)[1] -= (prs[1] < 7 && (prs[1] - (int)prs[1]) != 0) ? 1 : 0;
	sfSprite_setTexture(md->sprite, md->text, sfTrue);
	md->pos.y = (prs[1] - (int)prs[1]) * -48;
	md->pos.y = (md->pos.y > 0) ? -md->pos.y + 48 : md->pos.y;
	draw_foreground(map, prs, wd, md);
	sfSprite_destroy(md->sprite);
	sfTexture_destroy(md->text);
}