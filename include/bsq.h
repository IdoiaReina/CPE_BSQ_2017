/*
** EPITECH PROJECT, 2017
** .h
** File description:
** .h
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef STRUCT_LIST_
#define STRUCT_LIST_

typedef struct s_Entities
{
	char **tab;
	char *buf;
	size_t count;
	int save_x;
	int save_y;
	int size;
	int save_size;
	int x;
        int y;
        int px;
        int py;

}Entities;

/*Malloc and Free*/
void malloc_one(Entities **elem);
void free_one(Entities **elem);

/*Square*/
void maybe_a_square(Entities **e);
int check_line(Entities **e);
int check_col(Entities **e, int j);
int find_square(Entities **e);

/*Main*/
void tableau(char **av, Entities **elem);
void display_map(Entities **elem);
void my_putstr(char const *str);

#endif
