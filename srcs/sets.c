/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:54:42 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:46:51 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		double_tear_drop_set(int x, int y, int m, t_fractol *h)
{
	t_ll	l;
	int		n;
	double	a;
	double	b;
	double	tmp;

	a = h->a[m];
	b = h->b[m];
	l.cr = h->a[m] / (h->a[m] * h->a[m] + h->b[m] * h->b[m]);
	l.ci = h->b[m] / (h->a[m] * h->a[m] + h->b[m] * h->b[m]);
	a = 0;
	b = 0;
	n = 0;
	while (n < h->nmax)
	{
		tmp = (a * a * a - 3 * b * b * a) * exp(cos(a)) + l.cr;
		b = (3 * (a * a * b) - (b * b * b)) * exp(cos(b)) + l.ci;
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}

int		reverse_mandelbrot_set(int x, int y, int m, t_fractol *h)
{
	t_ll	l;
	int		n;
	double	a;
	double	b;
	double	tmp;

	a = h->a[m];
	b = h->b[m];
	l.cr = a;
	l.ci = b;
	n = 0;
	while (n < h->nmax)
	{
		tmp = (a * a - b * b) / ((a * a + b * b) * (a * a + b * b)) + l.cr;
		b = (-2 * a * b) / ((a * a + b * b) * (a * a + b * b)) + l.ci;
		a = tmp;
		if (a * a + b * b > 100)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}

int		julia_set(int x, int y, int m, t_fractol *h)
{
	t_ll	l;
	int		n;
	double	a;
	double	b;
	double	tmp;

	h->l = 1;
	a = h->a[m];
	b = h->b[m];
	l.cr = h->a[m];
	l.ci = h->b[m];
	n = 0;
	while (n < h->nmax)
	{
		tmp = a * a - b * b;
		b = 2 * a * b;
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}

int		julia_update(int x, int y, int m, t_fractol *h)
{
	t_ll	l;
	int		n;
	double	a;
	double	b;
	double	tmp;

	a = h->a[m];
	b = h->b[m];
	l.cr = h->a[m];
	l.ci = h->b[m];
	n = 0;
	while (n < h->nmax)
	{
		tmp = a * a - b * b + map(x, WIN_WIDTH, -2, 2);
		b = 2 * a * b + map(y, WIN_WIDTH, -2, 2);
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}
