/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include "bsq.h"

int maximum_map(Entities **elem)
{
	int x = 0;
	int nb1 = 0;
	int nb2 = 0;

	while ((*elem)->buf[x] != 'x' && (*elem)->buf[x] != '\n') {
		nb1 = nb1 * 10 + (*elem)->buf[x] - 48;
		x += 1;
	}
	x += 1;
	while ((*elem)->buf[x] != '\n') {
		nb2 += 1;
		x += 1;
	}
	return (nb1 * nb2 * 2 + 3);
}

void tableau(char **av, Entities **elem)
{
	int fd = open(av[1], O_RDONLY);
	int i = 0;
	int max = 0;

	read(fd, (*elem)->buf, (*elem)->count);
	max = maximum_map(elem);
	while ((*elem)->buf[i] != '\0' && i < max) {
		(*elem)->tab[(*elem)->y] = malloc(sizeof(char) * 10000);
		(*elem)->x = 0;
		while ((*elem)->buf[i] != '\n' && i < max) {
			(*elem)->tab[(*elem)->y][(*elem)->x] = (*elem)->buf[i];
			(*elem)->x += 1;
			i += 1;
		}
		(*elem)->y += 1;
		i += 1;
	}
	maybe_a_square(elem);
	display_map(elem);
}

void display_map(Entities **e)
{
	int y = 0;
	int j = 0;
	int i = 0;

	while (i < (*e)->save_size) {
		(*e)->tab[(*e)->save_y][(*e)->save_x + i] = 'x';
		j = 0;
		while (j < (*e)->save_size) {
			(*e)->tab[(*e)->save_y + j][(*e)->save_x + i] = 'x';
			j += 1;
		}
		i += 1;
	}
	while (y != (*e)->y) {
		my_putstr((*e)->tab[y]);
		write(1, "\n", 1);
		y += 1;
	}
}

int main(int ac, char **av)
{
	Entities *elem;

	if (ac < 2)
		return (84);
	malloc_one(&elem);
	tableau(av, &elem);
	free_one(&elem);
	free(elem);
	return (0);
}
