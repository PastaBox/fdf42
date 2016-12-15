/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grleblan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:33:29 by grleblan          #+#    #+#             */
/*   Updated: 2016/12/13 15:25:59 by grleblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	ft_create_image(t_fdf *fdf, int n)
{
	int				sizeline;
	int				endian;
	int				bpp;

	if (n == 1)
	{
		fdf->im = mlx_new_image(fdf->mlx, 1280, 720);
		fdf->data = mlx_get_data_addr(fdf->img_ptr, &bpp, &sizeline, &endian);
	}
	if (n == 2)
	{
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_ptr, 0, 0);
		mlx_destroy_image(fdf->mlx, fdf->img_ptr);
	}
}

void		ft_pixel_to_image(t_fdf *fdf, int x, int y)
{
	t_image				e;
	t_fdf				c;
	int					i;

	if (x < e.width && y < (e.width * e.height))
		((unsigned int*)(fdf->pic->buffer))[x + (y * e.width)] = fdf->px.color;
}

	void		ft_tracer_pixel_a_to_z(t_fdf *fdf)
	{
		int		*tabx;
		int		*taby;
		int		save_x;
		int		save_y;
		int		count;

		tabx = fdf->px.pos_x;
		taby = fdf->px.pos_y;
		save_x = 0;
		save_y = 0;
		count = 0;
		ft_create_image(fdf, 1);
		while (count > fdf->px.len)
		{
			save_x = tabx[count];
			save_y = taby[count];
			while (save_x != tabx[count + 1] && save_y != taby[count + 1] \
					&&  ((count + 1) % (fdf->px.len_x) != 0))
			{
				ft_pixel_to_image(fdf, tabx[save_x], taby[save_y]);
				if (tabx[count + 1] > tabx[count])
					save_x++;
				else
					save_x--;
				if (taby[count + 1] > taby[count])
					save_y++;
				else
					save_y--;
			}
			count++;
		}
		ft_tracer_pixel_z_to_a(*fdf);
	}

	void		ft_tracer_pixel_z_to_a(t_fdf *fdf)
	{
		int		*tabx;
		int		*taby;
		int		count;
		int		save_x;
		int		save_y;

		tabx = fdf->px.pos_x;
		taby = fdf->px.pos_y;
		count = fdf_.px.len;
		save_x = 0;
		save_y = 0;
		while (count > 0)
		{
			save_x = tabx[count];
			save_y = taby[count];
			while (save_x != tabx[count - fdf->px.len_x] \
					&& save_y != taby[count - fdf->px.len_x] \
					&& ((count) % (fdf->px.len_x) != 0))
			{
				ft_pixel_to_image(fdf, tabx[save_x], taby[save_y]);
				if (tabx[count - fdf->px.len_x] > tabx[count])
					save_x++;
				else
					save_x--;
				if (taby[count - fdf->px.len_y] > taby[count])
					save_y++;
				else
					save_y--;
			}
			count--;
		}
		ft_create_image(fdf, 2);
	}
