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
	tree->path = NULL;
	tree->count_files = 0;
	tree->count_dir = 0;
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
		my_putstr(" [error opening dir]\n");
		free(path_concat);
		return;
	} else if (level == 1)
		my_putstr("\n");
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

void	start_program(t_tree *tree)
{
	my_putstr(tree->path);
	list_dir(tree, my_strconcat("", ""), 1);
}

void	print_result(t_tree *tree)
{
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
	if (tree->path == NULL) {
		tree->path = ".";
		start_program(tree);
	}
	print_result(tree);
	free(tree);
	return (0);
}
