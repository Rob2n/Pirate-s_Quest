/*
** EPITECH PROJECT, 2018
** my
** File description:
** rpg
*/

#include "my.h"

int my_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

int my_strcmp(char *s1, char *s2)
{
	if (my_strlen(s1) != my_strlen(s2))
		return (1);
	for (int i = 0; s1[i]; i++) {
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}