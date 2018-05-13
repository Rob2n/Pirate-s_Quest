/*
** EPITECH PROJECT, 2017
** getnbr
** File description:
** nbr
*/

#include "my.h"

int sign(char const *str)
{
	int n = 1;
	int i = 0;

	while (str && (str[i] == '-' || str[i] == '+')) {
		if (str[i] == '-') {
			n = n * (-1);
			i = i + 1;
		} else if (str[i] == '+') {
			i = i + 1;
		}
	}
	return (n);
}

int count(char const *str)
{
	int n = 1;
	int i = 0;

	while (str && (str[i] == '-' || str[i] == '+')) {
		if (str[i] == '-') {
			n = n * (-1);
			i = i + 1;
		} else if (str[i] == '+') {
			i = i + 1;
		}
	}
	return (i);
}

int my_getnbr(char const *str)
{
	int nb = 0;
	int neg = sign(str);
	int i = count(str);

	while (str && str[i]) {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + str[i] - 48;
			i = i + 1;
		} else {
			return (nb * neg);
		}
	}
	return (nb * neg);
}

char *my_strcat(char *dest, const char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;
	while ((*dest++ = *src++) != '\0');
	return (temp);
}

char *nbr_to_str(int nbr)
{
	char *str;
	int size = 1;
	int cpy = nbr;
	int add;

	for (; cpy >= 10; size++) {
		cpy = cpy / 10;
	}
	str = malloc (sizeof (char) * size + 1);
	str[size] = '\0';
	while (size > 0) {
		size--;
		add = nbr % 10;
		nbr = nbr / 10;
		str[size] = add + '0';
	}
	return (str);
}