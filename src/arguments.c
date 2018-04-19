/*
** EPITECH PROJECT, 2018
** arguments
** File description:
** by Epitech Developers
*/

#include "tree.h"

int	my_getnbr(char *str)
{
	int	result = 0;
	int	i = -1;
	int	signe = 1;

	while (str[++i] && (str[i] == '+' || str[i] == '-')) {
		if (str[i] == '-')
			signe = signe * -1;
	}
	i -= 1;
	while (str[++i] && str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + str[i] - 48;
		if (result < 0 && (result != -2147483648 || signe == 1))
			return (0);
	}
	return (signe * result);
}

int	check_arguments(t_tree *tree, int ac, char **av)
{
	int	i = 0;
	char	*error_level = "tree: Invalid level, must be greater than 0.\n";

	while (++i < ac) {
		if (my_strcmp(av[i], "-a") == 0)
			tree->hidden_files = 1;
		else if (my_strcmp(av[i], "-d") == 0)
			tree->only_dir = 1;
		else if (my_strcmp(av[i], "-f") == 0)
			tree->all_path = 1;
		else if (my_strcmp(av[i], "-L") == 0) {
			if (i + 1 >= ac)
				return (0);
			tree->max_denth = my_getnbr(av[i++ + 1]);
			if (tree->max_denth <= 0) {
				my_putstr_err(error_level);
				return (0);
			}
		} else {
			tree->path = av[i];
			if (tree->path[my_strlen(tree->path) - 1] == '/')
				tree->path[my_strlen(tree->path) - 1] = 0;
		}
	}
	return (1);
}
