/*
** EPITECH PROJECT, 2018
** conv
** File description:
** array
*/

#include "my.h"

int my_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int my_putstr(char *str)
{
	int i = -1;

	while (str[++i])
		my_putchar(str[i]);
	return (0);
}

int word_len(char *str, int i, char var)
{
	int cmp = 0;

	for (; str[i] && str[i] != var; cmp++, i++);
	return (cmp);
}

int word_count(char *str, char var)
{
	int cmp = 1;

	for (int i = 0; str[i]; i++) {
		if ((str[i] == var) && str[i + 1] != var)
			cmp++;
	}
	return (cmp);
}

char **conv_array(char *s, char var)
{
	char **bat = malloc((word_count(s, var) + 1) * sizeof(char *));
	int i = 0;
	int j = 0;
	int k = 0;

	for (; s[i]; j++) {
		k = 0;
		for (; s[i] == var; i++);
		bat[j] = malloc((word_len(s, i, var) + 1) * sizeof(char));
		for (; s[i] && s[i] != var; k++, i++)
			bat[j][k] = s[i];
		bat[j][k] = '\0';
		for (; s[i] == var; i++);
	}
	bat[j] = NULL;
	return (bat);
}