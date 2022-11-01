/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:11:20 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/01 13:05:14 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_coordinates
**
**		Stores the coordinates of the dots in arrays
**
**
*/

void	ft_coordinates(t_dt *sc)
{
	ft_allocate_ij(sc);
	ft_fill_j(sc);
	ft_fill_i(sc);
	ft_fill_depth(sc);
	ft_roatation(sc);
}

void	ft_allocate_ij(t_dt *sc)
{
	int	i;

	i = 0;
	sc->i = malloc(sizeof(double*) * (sc->size_y));
	sc->j = malloc(sizeof(double *) * (sc->size_y));
	while (i < sc->size_y)
	{
		sc->i[i] = malloc(sizeof(double) * sc->size_x);
		sc->j[i] = malloc(sizeof(double) * sc->size_x);
		++i;
	}
}


void	ft_fill_j(t_dt *sc)
{
	int i;
	int j;
	double margin;

	i = 0;
	j = 1;
	margin = 50;
	if (sc->fullcreen_vertical)
		margin = (1920 / 2) - (sc->size_y * sc->line_width);
	
	sc->j[0][0] = margin;
	while (i < sc->size_y)
	{
		while (j < sc->size_x)
		{
			sc->j[i][j] = sc->j[i][j - 1] + sc->line_width;
			++j;
		}
		++i;
		if (i < sc->size_y)
		{
			j = 0;
			margin += sc->line_width; 
			sc->j[i][j] = margin;
			j = 1;
		}
	}
/*
	int x;
	int	y;

	x = 0;
	y = 0;

	printf("\n\nJ Coords:\n");
	while (y < sc->size_y)
	{
		while (x < sc->size_x)
		{
			printf("%f\n", sc->j[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		++y;
	}
*/
}




void	ft_fill_i(t_dt *sc)
{
	int i;
	int j;
	double margin;

	i = 0;
	j = 1;
	margin = sc->highest_y + 50;
	sc->i[0][0] = margin;
	while (i < sc->size_y)
	{
		while (j < sc->size_x)
		{
			sc->i[i][j] = sc->i[i][j - 1] - sc->line_height;
			++j;
		}
		++i;
		if (i < sc->size_y)
		{
			j = 0; //remove this one
			margin += sc->line_height; 
			sc->i[i][j] = margin;	//and place the 0 on the j
			j = 1;
		}
	}
/*
	printf("\n\ni Coords:\n");

	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < sc->size_y)
	{
		while (x < sc->size_x)
		{
			printf("%d ", sc->i[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		++y;
	}
*/
}



void	ft_fill_depth(t_dt *sc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < sc->size_y)
	{
		while (j < sc->size_x)
		{
			sc->i[i][j] = sc->i[i][j] - (sc->lines[i][j] * sc->line_depth);
			++j;
		}
		j = 0;
		++i;
	}

/*
	printf("\n\nAfter Depth:\n");
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < sc->size_y)
	{
		while (x < sc->size_x)
		{
			printf("%d ", sc->i[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		++y;
	}
*/
}



void	ft_roatation(t_dt *sc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < sc->size_y)
	{
		while (j < sc->size_x)
		{
			//sc->i[i][j] += cos(sc->angle);
			//sc->j[i][j] +=3;
			++j;
			sc->angle++;
		}
		j = 0;
		++i;
	}


	
}
