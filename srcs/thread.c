/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 09:50:24 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:43:32 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thread1(void *h1)
{
	int			i;
	int			j;
	t_fractol	*h;
	int			n;

	h = (t_fractol *)h1;
	i = 0;
	while (i < WIN_WIDTH / 2)
	{
		j = -1;
		while (++j < WIN_HEIGTH / 2)
		{
			h->a[0] = map(i, WIN_WIDTH, h->re_min + (h->mv_x_re / h->fract),
					h->re_max + (h->mv_x_re / h->fract));
			h->b[0] = map(j, WIN_HEIGTH, h->im_min + (h->mv_y_im / h->fract),
					h->im_max + (h->mv_y_im / h->fract));
			n = h->f(h->x, h->y, 0, h);
			if (n == h->nmax)
				h->mlx.img.data[j * WIN_WIDTH + i] = rgb(0, 0, 0);
			else
				h->mlx.img.data[j * WIN_WIDTH + i] = rgb1(n, h->nmax, h);
		}
		i++;
	}
	pthread_exit(0);
}

void	*thread2(void *h1)
{
	int			i;
	int			j;
	t_fractol	*h;
	int			n;

	h = (t_fractol *)h1;
	i = WIN_WIDTH / 2;
	while (i < WIN_WIDTH)
	{
		j = -1;
		while (++j < WIN_HEIGTH / 2)
		{
			h->a[1] = map(i, WIN_WIDTH, h->re_min + (h->mv_x_re / h->fract),
					h->re_max + (h->mv_x_re / h->fract));
			h->b[1] = map(j, WIN_HEIGTH, h->im_min + (h->mv_y_im / h->fract),
					h->im_max + (h->mv_y_im / h->fract));
			n = h->f(h->x, h->y, 1, h);
			if (n == h->nmax)
				h->mlx.img.data[j * WIN_WIDTH + i] = rgb(0, 0, 0);
			else
				h->mlx.img.data[j * WIN_WIDTH + i] = rgb1(n, h->nmax, h);
		}
		i++;
	}
	pthread_exit(0);
}

void	*thread3(void *h1)
{
	int			i;
	int			j;
	t_fractol	*h;
	int			n;

	h = (t_fractol *)h1;
	i = 0;
	while (i < WIN_WIDTH / 2)
	{
		j = WIN_HEIGTH / 2 - 1;
		while (++j < WIN_HEIGTH)
		{
			h->a[2] = map(i, WIN_WIDTH, h->re_min + (h->mv_x_re / h->fract),
					h->re_max + (h->mv_x_re / h->fract));
			h->b[2] = map(j, WIN_HEIGTH, h->im_min + (h->mv_y_im / h->fract),
					h->im_max + (h->mv_y_im / h->fract));
			n = h->f(h->x, h->y, 2, h);
			if (n == h->nmax)
				h->mlx.img.data[j * WIN_WIDTH + i] = rgb(0, 0, 0);
			else
				h->mlx.img.data[j * WIN_WIDTH + i] = rgb1(n, h->nmax, h);
		}
		i++;
	}
	pthread_exit(0);
}

void	*thread4(void *h1)
{
	int			i;
	int			j;
	t_fractol	*h;
	int			n;

	h = (t_fractol *)h1;
	i = WIN_WIDTH / 2;
	while (i < WIN_WIDTH)
	{
		j = WIN_HEIGTH / 2 - 1;
		while (++j < WIN_HEIGTH)
		{
			h->a[3] = map(i, WIN_WIDTH, h->re_min + (h->mv_x_re / h->fract),
					h->re_max + (h->mv_x_re / h->fract));
			h->b[3] = map(j, WIN_HEIGTH, h->im_min + (h->mv_y_im / h->fract),
					h->im_max + (h->mv_y_im / h->fract));
			n = h->f(h->x, h->y, 3, h);
			if (n == h->nmax)
				h->mlx.img.data[j * WIN_WIDTH + i] = rgb(0, 0, 0);
			else
				h->mlx.img.data[j * WIN_WIDTH + i] = rgb1(n, h->nmax, h);
		}
		i++;
	}
	pthread_exit(0);
}
