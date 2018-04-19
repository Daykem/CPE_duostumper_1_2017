/*
** EPITECH PROJECT, 2018
** elements
** File description:
** by Epitech Developers
*/

#include "tree.h"

void	print_name_element(t_tree *tree, char *name, char *path)
{
	char	*str = my_strconcat(path, name);

	str[0] = '.';
	if (tree->all_path)
		my_putstr(str);
	else
		my_putstr(name);
	free(str);
}

void	print_elements(t_tree *tree, t_read *first, int level, char *path)
{
	t_read	*tmp = first;

	while (tmp != NULL) {
		if (tmp->read->d_type != DT_DIR && tree->only_dir) {
			tmp = tmp->next;
			continue;
		}
		print_level(level, !has_next(tree, tmp->next));
		print_name_element(tree, tmp->read->d_name, path);
		my_putstr("\n");
		if (tmp->read->d_type == DT_DIR) {
			list_dir(tree, my_strconcat(path,
						tmp->read->d_name), level + 1);
			tree->count_dir++;
		} else
			tree->count_files++;
		tmp = tmp->next;
	}
}

t_read	*add_element(t_read *first, struct dirent *read)
{
	t_read	*element = malloc(sizeof(t_read));
	t_read	*tmp;
	
	element->read = read;
	element->prev = NULL;
	element->next = NULL;
	if (first == NULL)
		return (element);
	else {
		tmp = first;
		while (tmp->next != NULL)
			tmp = tmp->next;
		element->prev = tmp;
		tmp->next = element;		
	}
	return (first);
}

t_read	*order_elements(t_tree *tree, t_read *first)
{
	t_read	*old = first;
	t_read	*tmp = (first != NULL ? first->next : NULL);
	t_read	*prev_old;
	t_read	*next_tmp;

	if (old == NULL || tmp == NULL) {
		tree->tri = 0;
		return (first);
	}
	while (old != NULL && tmp != NULL
			&& my_strcmp(old->read->d_name, tmp->read->d_name) < 0) {
		old = old->next;
		tmp = tmp->next;
	}
	if (old == NULL || tmp == NULL || my_strcmp(old->read->d_name, tmp->read->d_name) < 0) {
		tree->tri = 0;
		return (first);
	}
	prev_old = old->prev;
	next_tmp = tmp->next;
	if (prev_old != NULL) {
		prev_old->next = tmp;
	} else
		first = tmp;
	old->prev = tmp;
	old->next = next_tmp;
	tmp->prev = prev_old;
	tmp->next = old;
	if (next_tmp != NULL)
		next_tmp->prev = old;
	else
		old->next = NULL;
	return (first);
}
