/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 08:45:44 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/25 15:12:54 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	homothetic_transformation(double start, double end, double k)
{
	return (start + ((end - start) * k));
}

void	zoom(t_fractol *h, double x, double y)
{
	double	new_x;
	double	new_y;

	new_x = map(x, WIN_WIDTH, h->re_min, h->re_max);
	new_y = map(y, WIN_WIDTH, h->im_min, h->im_max);
	h->re_min = homothetic_transformation(new_x, h->re_min, h->zoom_fract);
	h->im_min = homothetic_transformation(new_y, h->im_min, h->zoom_fract);
	h->re_max = homothetic_transformation(new_x, h->re_max, h->zoom_fract);
	h->im_max = homothetic_transformation(new_y, h->im_max, h->zoom_fract);
}
