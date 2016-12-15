/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:37:11 by fciprian          #+#    #+#             */
/*   Updated: 2016/12/13 15:27:00 by grleblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
**		Defines
*/

# define WIN_H 1280
# define WIN_W 720

# define TILE_X 30
# define TILE_Y 30
# define TILE_Z 10

# define ESC 53

/*
**		Includes
*/

# include "../libft/libft.h"
# include "../minilibx_macos_sierra/mlx.h"

# include "keys.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct  s_point
{
	int			*pos_x;
	int			*pos_y;
	int			*pos_z;
}				t_point;

typedef struct  s_iso
{
	int			*px_x;
	int			*px_y;
	int 		len;
	int			st_x;
	int			st_y;
}				t_iso;

typedef	struct 	s_string
{
	t_point		**array;
	int 		length;
}				t_string;

typedef struct  s_map
{
	t_string	**lines;
	int 		length;
}				t_map;

typedef struct 	s_fdf
{
	void			*mlx;
	void			*win;
	t_map			*map;
}				t_fdf;

/*
**		Functions
*/

t_iso		*get_isometric_cords(int *pos_x, int *pos_y, int len);
void		isometric_cords_center(t_iso *iso);
int			get_grid_w(int *tab, int len);
int			get_grid_h(int *tab, int len);

void		print_grid_points(void *mlx, void *win, t_iso *iso);

int			fdf_hook(int keycode, void *param);

void		errors_exit(void);
void		errors_handler(char *string, int type);
void		errors_usage(void);

int			hook_keys(int keycode, t_fdf *fdf);

#endif
