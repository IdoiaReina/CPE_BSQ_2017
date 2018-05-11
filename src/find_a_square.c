/*
** EPITECH PROJECT, 2017
** square
** File description:
** square
*/

#include "bsq.h"

void maybe_a_square(Entities **e)
{
	while ((*e)->py < (*e)->y && (*e)->px < (*e)->x
		   && (*e)->size < (*e)->y && (*e)->size < (*e)->x) {
		if (find_square(e) == 0 && (*e)->py < (*e)->y
			&& (*e)->px < (*e)->x)
			(*e)->size += 1;
		if (find_square(e) == 1 && (*e)->py < (*e)->y
			&& (*e)->px < (*e)->x) {
			(*e)->size = 1;
			(*e)->px += 1;
		}
		if (find_square(e) == 1 && (*e)->py < (*e)->y
			&& (*e)->px == (*e)->x){
			(*e)->size = 1;
			(*e)->px = 0;
			(*e)->py += 1;
		}
	}
}

int check_line(Entities **e)
{
	int i = 0;

	while (i != (*e)->size) {
		if ((*e)->px + i > (*e)->x - 1)
			return (1);
		if ((*e)->tab[(*e)->py][(*e)->px + i] != '.'
			|| check_col(e, i) == 1)
			return (1);
		i += 1;
	}
	return (0);
}

int check_col(Entities **e, int j)
{
	int i = 0;

	while (i != (*e)->size) {
		if ((*e)->py + i > (*e)->y - 1)
			return (1);
		if ((*e)->tab[(*e)->py + i][(*e)->px + j] != '.')
			return (1);
		i += 1;
	}
	return (0);
}

int find_square(Entities **e)
{
	if (check_line(e) == 1)
		return (1);
	if ((*e)->size > (*e)->save_size) {
		(*e)->save_size = (*e)->size;
		(*e)->save_y = (*e)->py;
		(*e)->save_x = (*e)->px;
	}
	return (0);
}
