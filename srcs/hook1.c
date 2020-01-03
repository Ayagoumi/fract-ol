/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:42:22 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:42:53 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_sets1(int key, t_fractol *h)
{
	h->nb = 0;
	if (key == 83 || key == 84 || key == 85 || key == 86
			|| key == 87 || key == 88 || key == 89)
	{
		init_struct(h);
		destroy_image(h);
		h->nb = 1;
		if (key == 83)
			assi_fonct("1", h);
		else if (key == 84)
			assi_fonct("2", h);
		else if (key == 85)
			assi_fonct("3", h);
		else if (key == 86)
			assi_fonct("4", h);
		else if (key == 87)
			assi_fonct("5", h);
		else if (key == 88)
			assi_fonct("6", h);
		else if (key == 89)
			assi_fonct("7", h);
		threading(h);
	}
	return (1);
}

int		hook_sets2(int key, t_fractol *h)
{
	h->nb = 0;
	if (key == 91 || key == 92 || key == 14 || key == 13 || key == 12)
	{
		init_struct(h);
		destroy_image(h);
		h->nb = 1;
		if (key == 91)
			assi_fonct("8", h);
		else if (key == 92)
			assi_fonct("9", h);
		else if (key == 14)
			assi_fonct("10", h);
		else if (key == 13)
			assi_fonct("11", h);
		else if (key == 12)
			assi_fonct("12", h);
		threading(h);
	}
	return (1);
}

int		hook_sets3(int key, t_fractol *h)
{
	h->nb = 0;
	if (key == 69)
		h->nmax += 10;
	else if (key == 78)
		(h->nmax > 5) ? (h->nmax -= 10) : (h->nmax = 5);
	threading(h);
	return (1);
}

int		hook_sets4(int key, t_fractol *h)
{
	h->nb = 0;
	if (key == 123)
	{
		h->mv_x_im += 0.125 * (0.1 / h->m);
		h->mv_x_re += 0.125 * (0.1 / h->m);
	}
	else if (key == 124)
	{
		h->mv_x_im -= 0.125 * (0.1 / h->m);
		h->mv_x_re -= 0.125 * (0.1 / h->m);
	}
	else if (key == 125)
	{
		h->mv_y_im -= 0.125 * (0.1 / h->m);
		h->mv_y_re -= 0.125 * (0.1 / h->m);
	}
	else if (key == 126)
	{
		h->mv_y_im += 0.125 * (0.1 / h->m);
		h->mv_y_re += 0.125 * (0.1 / h->m);
	}
	return (1);
}

int		hook_sets5(int key, t_fractol *h)
{
	h->nb = 0;
	if (key == 8 || key == 9)
	{
		if (key == 8)
		{
			h->color += 20;
			threading(h);
		}
		else if (key == 9)
		{
			h->color -= 20;
			threading(h);
		}
	}
	return (1);
}
