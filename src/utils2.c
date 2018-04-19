/*
** EPITECH PROJECT, 2018
** utils2
** File description:
** by Epitech Developers
*/

#include "tree.h"

void	my_putstr_err(char *str)
{
	write(2, str, my_strlen(str));
}

void	free_reader(t_read *first)
{
	t_read	*next = first;
	t_read	*tmp;

	while (next != NULL) {
		tmp = next;
		next = next->next;
		free(tmp);
	}
}

char	*my_strconcat(char *s1, char *s2)
{
	char	*res = malloc(my_strlen(s1) + my_strlen(s2) + 2);
	int	i = 0;
	int	a = -1;

	if (res == NULL)
		return (NULL);
	while (s1[++a])
		res[i++] = s1[a];
	a = -1;
	res[i++] = '/';
	while (s2[++a])
		res[i++] = s2[a];
	res[i] = 0;
	return (res);
}
