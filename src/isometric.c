/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgeorge <thgeorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:02:09 by thgeorge          #+#    #+#             */
/*   Updated: 2016/12/11 18:45:36 by thgeorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			get_grid_w(int *tab, int len)
{
	int		max;
	int		min;
	int		i;

	i = -1;
	min = 2147483647;
	max = -2147483648;
	while (++i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		if (tab[i] < min)
			min = tab[i];
	}
	return ((max - min) + 1);
}

int			get_grid_h(int *tab, int len)
{
	int		max;
	int		min;
	int		i;

	i = -1;
	min = 2147483647;
	max = -2147483648;
	while (++i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		if (tab[i] < min)
			min = tab[i];
	}
	return ((max - min) + 1);
}

void		isometric_cords_center(t_iso *iso)
{
	int		i;

	i = -1;
	while (++i < iso->len)
	{
		iso->px_x[i] += iso->st_x;
		iso->px_y[i] += iso->st_y;
	}
}

t_iso		*get_isometric_cords(int *pos_x, int *pos_y, int len)
{
	int			*tb_x;
	int			*tb_y;
	t_iso		*iso;
	int			i;

	iso = NULL;
	if (		!(tb_x = (int *)malloc(sizeof(int) * len))
			||	!(tb_y = (int *)malloc(sizeof(int) * len))
			||	!(iso = (t_iso *)malloc(sizeof(t_iso) * 1)))
		return (iso);
	i = -1;
	while (++i < len)
	{
		tb_x[i] = ((pos_x[i] - pos_y[i]) * (TILE_X / 2));
		tb_y[i] = ((pos_x[i] + pos_y[i]) * (TILE_Y / 2));
	}
	iso->st_x = (WIN_W - get_grid_w(tb_x, len)) / 2;
	iso->st_y = (WIN_H - get_grid_h(tb_y, len)) / 2;
	iso->px_x = tb_x;
	iso->px_y = tb_y;
	iso->len = len;
	isometric_cords_center(iso);
	return (iso);
}
