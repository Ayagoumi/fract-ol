/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 09:18:36 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/27 12:31:25 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rgb(int r, int g, int b)
{
	return (r * 65536 + g * 256 + b);
}

int		rgb1(int max, int n, t_fractol *h)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (((double)max) / ((double)n)) + h->color;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (rgb(r, g, b));
}
