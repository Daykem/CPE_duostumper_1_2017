/*
** EPITECH PROJECT, 2018
** tree
** File description:
** by Epitech Developers
*/

#include "tree.h"

void	init_program(t_tree *tree)
{
	tree->hidden_files = 0;
	tree->only_dir = 0;
	tree->max_denth = -1;
	tree->all_path = 0;
	tree->count_files = 0;
	tree->count_dir = 0;
	tree->path = ".";
}

void	print_level(int level, int last)
{
	int	tmp = level;

	my_putstr(last && level <= 1 ? "`" : "|");
	while (tmp > 1) {
		my_putstr("   ");
		tmp--;
	}
	if (level > 1)
		my_putstr(last ? "`" : "|");
	my_putstr("-- ");
}

void	list_dir(t_tree *tree, char *path, int level)
{
	DIR		*dir;
	struct dirent	*read;
	t_read		*list = NULL;
	char		*path_concat;

	if (tree->max_denth != -1 && level > tree->max_denth)
		return;
	path_concat = my_strconcat(tree->path, path);
	dir = opendir(path_concat);
	if (dir == NULL) {
		free(path_concat);
		return;
	}
	while ((read = readdir(dir)) != NULL) {
		if (my_strcmp(read->d_name, ".") == 0
		    || my_strcmp(read->d_name, "..") == 0)
			continue;
		if (read->d_name[0] == '.' && !tree->hidden_files)
			continue;
		list = add_element(list, read);
	}
	tree->tri = 1;
	while (tree->tri)
		list = order_elements(tree, list);
	print_elements(tree, list, level, path);
	closedir(dir);
	free_reader(list);
	free(path_concat);
	free(path);
}

int	has_next(t_tree	*tree, t_read *tmp)
{
	if (tmp == NULL)
		return (0);
	while (tmp != NULL) {
		if (tmp->read->d_type != DT_DIR && tree->only_dir) {
			tmp = tmp->next;
			continue;
		}
		return (1);
	}
	return (0);
}

void	start_program(t_tree *tree)
{
	my_putstr(tree->path);
	my_putstr("\n");
	list_dir(tree, my_strconcat("", ""), 1);
	my_putstr("\n");
	my_put_nbr(tree->count_dir);
	if (tree->count_dir == 1)
		my_putstr(" directory");
	else
		my_putstr(" directories");
	if (!tree->only_dir) {
		my_putstr(", ");
		my_put_nbr(tree->count_files);
		my_putstr(" file");
		if (tree->count_files > 1)
			my_putstr("s");
	}
	my_putstr("\n");
}

int	main(int ac, char **av)
{
	t_tree	*tree = malloc(sizeof(t_tree));

	if (tree == NULL)
		return (84);
	init_program(tree);
	if (!check_arguments(tree, ac, av))
		return (1);
	start_program(tree);
	free(tree);
	return (0);
}
