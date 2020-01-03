/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:45:29 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:48:12 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbar_5th_set(int x, int y, int m, t_fractol *h)
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
		tmp = a * ((a * a * a * a) - 10 * (a * a * b * b)
				+ 5 * (b * b * b * b)) + l.cr;
		b = -b * (5 * (a * a * a * a) - 10 * (a * a * b * b)
				+ (b * b * b * b)) + l.ci;
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}

int		mandelbar_set(int x, int y, int m, t_fractol *h)
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
		b = -2 * a * b + l.ci;
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}

int		celtic_mandelbrot_set(int x, int y, int m, t_fractol *h)
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
		tmp = fabs(a * a - b * b) + l.cr;
		b = 2 * a * b + l.ci;
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}

int		batman_set(int x, int y, int m, t_fractol *h)
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
	n = 0;
	while (n < h->nmax)
	{
		tmp = cos(a) * cosh(b) + l.cr;
		b = -sin(a) * sinh(b) + l.ci;
		a = tmp;
		if (a * a + b * b > 100)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}

int		madelbrot_inception_set(int x, int y, int m, t_fractol *h)
{
	t_ll	l;
	int		n;
	double	a;
	double	b;
	double	tmp;

	a = h->a[m];
	b = h->b[m];
	l.cr = a * a * a - 3 * b * b * a;
	l.ci = 3 * (a * a * b) - (b * b * b);
	a = 0;
	b = 0;
	n = 0;
	while (n < h->nmax)
	{
		tmp = a * a - b * b + l.cr;
		b = 2 * a * b + l.ci;
		a = tmp - 1.401155;
		if (a * a + b * b > 5)
			break ;
		n++;
	}
	h->x = x;
	h->y = y;
	return (n);
}
