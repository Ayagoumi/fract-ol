/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:43:50 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:45:21 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_set(int x, int y, int m, t_fractol *h)
{
	t_ll	l;
	int		n;
	double	a;
	double	b;
	double	tmp;

	h->x = x;
	h->y = y;
	a = h->a[m];
	b = h->b[m];
	l.cr = h->a[m];
	l.ci = h->b[m];
	n = 0;
	while (n < h->nmax)
	{
		tmp = a * a - b * b + l.cr;
		b = 2 * a * b + l.ci;
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	return (n);
}

int		mandelbrot2_set(int x, int y, int m, t_fractol *h)
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
		tmp = a * a * a - 3 * a * b * b + l.cr;
		b = 3 * a * a * b - b * b * b + l.ci;
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}

int		mandelbrot3_set(int x, int y, int m, t_fractol *h)
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
		tmp = a * a * a * a - 6 * (a * a * b * b) + (b * b * b * b);
		b = 4 * a * a * a * b - 4 * a * b * b * b + l.ci;
		a = tmp + l.cr;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}

int		burningship_set(int x, int y, int m, t_fractol *h)
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
		tmp = a * a - b * b + l.cr;
		b = 2 * fabs(a * b) + l.ci;
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}
