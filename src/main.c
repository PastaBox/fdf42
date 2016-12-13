/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:54:47 by fciprian          #+#    #+#             */
/*   Updated: 2016/12/11 18:58:09 by thgeorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			main(void)
{
	t_fdf		fdf;
	t_iso		*iso;

	int		pos_x[18] = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5};
	int		pos_y[18] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	//if (!(fdf = (t_fdf)malloc(sizeof(t_fdf) * 1)))
	//	return (NULL);
	//fdf = (t_fdf)malloc(sizeof(t_fdf) * 1);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIN_W, WIN_H, "FdF Main Frame");

	iso = get_isometric_cords(pos_x, pos_y, 18);
	print_grid_points(fdf.mlx, fdf.win, iso);
	mlx_key_hook(fdf.win, hook_keys, &fdf);

	mlx_loop(fdf.mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	t_map 	*map;
	t_fdf	fdf;
	int 	fd;

	fd = 0;
	if (argc == 2)
	{
		map = fdf_parse_map(argv[1], fd);
		fdf.map = map;
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, WIN_W, WIN_H, "FdF Main Frame");
		mlx_key_hook(fdf.win, hook_keys, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		fdf_usage();
	return (0);
}
