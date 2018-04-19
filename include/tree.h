/*
** EPITECH PROJECT, 2018
** tree
** File description:
** by Epitech Developers
*/

#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

typedef struct s_read
{
	struct dirent	*read;
	struct s_read	*prev;
	struct s_read	*next;
}	t_read;

typedef struct
{
	int	hidden_files;
	int	only_dir;
	int	max_denth;
	int	all_path;
	int	count_files;
	int	count_dir;
	char	*path;
	int	tri;
}	t_tree;

int	my_strlen(char*);
void	my_putchar(char);
void	my_putstr(char*);
char	*my_strtolow(char*);
int	my_strcmp(char*, char*);

void	my_putstr_err(char*);
void	free_reader(t_read*);
char	*my_strconcat(char *, char *);

int	my_put_nbr(int);
int	check_arguments(t_tree *, int, char **);

int	has_next(t_tree	*, t_read *);
void	start_program(t_tree *);

void	print_elements(t_tree *, t_read *, int, char*);
t_read	*add_element(t_read *, struct dirent *);
t_read  *order_elements(t_tree *, t_read *);

void	print_level(int, int);
void	list_dir(t_tree *, char *, int);
int	has_next(t_tree *, t_read *);

#endif
