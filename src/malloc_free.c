/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** free
*/

#include "bsq.h"

void malloc_one(Entities **elem)
{
	(*elem) = (Entities *)malloc(sizeof(Entities));
	if (elem == NULL)
		exit (1);
	(*elem)->buf = malloc(sizeof(char) * 30000 * 30000);
	(*elem)->count = 30000 * 30000;
	(*elem)->tab = malloc(sizeof(char *) * 30000 * 30000);
	(*elem)->x = 0;
	(*elem)->y = 0;
	(*elem)->px = 0;
	(*elem)->py = 0;
	(*elem)->size = 1;
	(*elem)->save_size = 0;
}

void free_one(Entities **elem)
{
	int y = 0;

	free((*elem)->buf);
	while (y < (*elem)->y) {
		free((*elem)->tab[y]);
		y += 1;
	}
	free((*elem)->tab);
}
