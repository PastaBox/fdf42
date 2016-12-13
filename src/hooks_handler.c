/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:25:41 by fciprian          #+#    #+#             */
/*   Updated: 2016/12/11 18:51:53 by thgeorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		hook_keys(int keycode, t_fdf *fdf)
{
	t_fdf		*cpy;

	cpy = fdf;
	if (keycode == ESC)
		errors_exit();
	return (1);
}
