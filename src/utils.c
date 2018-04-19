/*
** EPITECH PROJECT, 2018
** utils
** File description:
** by Epitech Developers
*/

#include "tree.h"

int	my_strlen(char *str)
{
	int	i = -1;

	while (str[++i]);
	return (i);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

char	*my_strtolow(char *str)
{
	int	i = -1;
	char	*res = malloc(my_strlen(str) + 1);
	
	while (str[++i]) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			res[i] = str[i] + 32;
		else
			res[i] = str[i];
	}
	res[i] = 0;
	return (res);
}

int	my_strcmp(char *s1, char *s2)
{
	int	i = 0;
	char	*t1 = my_strtolow(s1);
	char	*t2 = my_strtolow(s2);
	int	diff;
	
	while (t1[i] == t2[i] && t1[i] && t2[i])
		i++;
	diff = t1[i] - t2[i];
	free(t1);
	free(t2);
	return (diff);
}

