/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** by Epitech Developers
*/

#include "tree.h"

int	my_put_nbr(int nb)
{
	if (nb < -2147483647) {
		my_putstr("-2147483648");
		return (0);
	}
	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 10) {
		my_put_nbr(nb / 10);
		my_putchar((nb % 10) + 48);
	} else
		my_putchar(nb + 48);
	return (0);
}
