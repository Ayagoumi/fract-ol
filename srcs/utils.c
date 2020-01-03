/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 09:20:29 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/28 22:49:06 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_struct(t_fractol *h)
{
	h->color = 0;
	h->im_max = 2;
	h->im_min = -2;
	h->re_max = 2;
	h->re_min = -2;
	h->nmax = 65;
	h->nb = 0;
	h->x = 0;
	h->y = 0;
	h->m = 1;
}

void	destroy_image(t_fractol *h)
{
	mlx_clear_window(h->mlx.mlx_ptr, h->mlx.win);
	ft_bzero(h->mlx.mlx_ptr, 0);
}
