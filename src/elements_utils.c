/*
** EPITECH PROJECT, 2018
** elements_utils
** File description:
** by Epitech Developers
*/

#include "tree.h"

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
