/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:53:44 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:42:48 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		zoom_in_hook(int button, int x, int y, t_fractol *h)
{
	if ((button == 5 || button == 4))
	{
		h->nb = 0;
		if (button == 5)
		{
			h->zoom_fract = 1.0 / 1.1;
			h->m += 2;
		}
		else if (button == 4)
		{
			h->zoom_fract = 1.0 * 1.1;
			h->m -= 2;
		}
		zoom(h, x, y);
		threading(h);
	}
	if (button == 1 && h->fract == 4)
	{
		h->nb++;
		h->nb %= 2;
	}
	return (0);
}

int		hook(int key, t_fractol *h)
{
	hook_sets1(key, h);
	hook_sets2(key, h);
	hook_sets5(key, h);
	if (key == 53)
	{
		mlx_clear_window(h->mlx.mlx_ptr, h->mlx.win);
		mlx_destroy_image(h->mlx.mlx_ptr, h->mlx.img.img_ptr);
		mlx_destroy_window(h->mlx.mlx_ptr, h->mlx.win);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (key == 69 || key == 78)
			hook_sets3(key, h);
		else if (key == 123 || key == 124 || key == 125 || key == 126)
		{
			hook_sets4(key, h);
			threading(h);
		}
	}
	return (1);
}
