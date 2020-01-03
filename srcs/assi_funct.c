/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assi_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:38:08 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:39:52 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		assi_fonct1(char *av, t_fractol *h)
{
	if (ft_strcmp(av, "mandelbrot") == 0 || ft_strcmp(av, "1") == 0)
	{
		h->fract = 1;
		h->f = &mandelbrot_set;
		h->name = "Mandelbrot";
	}
	else if (ft_strcmp(av, "mandelbrot2") == 0 || ft_strcmp(av, "2") == 0)
	{
		h->fract = 2;
		h->f = &mandelbrot2_set;
		h->name = "Cubic mandelbrot";
	}
	else if (ft_strcmp(av, "mandelbrot3") == 0 || ft_strcmp(av, "3") == 0)
	{
		h->fract = 3;
		h->f = &mandelbrot3_set;
		h->name = "Mandelbrot 4th Order";
	}
	else
		return (1);
	return (0);
}

int		assi_fonct2(char *av, t_fractol *h)
{
	if (ft_strcmp(av, "julia") == 0 || ft_strcmp(av, "4") == 0)
	{
		h->fract = 4;
		h->f = &julia_set;
		h->name = "Julia";
	}
	else if (ft_strcmp(av, "burningship") == 0 || ft_strcmp(av, "5") == 0)
	{
		h->fract = 5;
		h->f = &burningship_set;
		h->name = "Burningship";
	}
	else if (ft_strcmp(av, "quasi_heart") == 0 || ft_strcmp(av, "6") == 0)
	{
		h->fract = 6;
		h->f = &mandelbar_5th_set;
		h->name = "Mandelbar 5th";
	}
	else
		return (1);
	return (0);
}

int		assi_fonct3(char *av, t_fractol *h)
{
	if (ft_strcmp(av, "mandelbar") == 0 || ft_strcmp(av, "7") == 0)
	{
		h->fract = 7;
		h->f = &mandelbar_set;
		h->name = "Mandelbar";
	}
	else if (ft_strcmp(av, "celtic_mandelbrot") == 0 || ft_strcmp(av, "8") == 0)
	{
		h->fract = 8;
		h->f = &celtic_mandelbrot_set;
		h->name = "Celtic mandelbrot";
	}
	else if (ft_strcmp(av, "batman") == 0 || ft_strcmp(av, "9") == 0)
	{
		h->fract = 9;
		h->f = &batman_set;
		h->name = "Batman";
	}
	else
		return (1);
	return (0);
}

int		assi_fonct4(char *av, t_fractol *h)
{
	if (ft_strcmp(av, "madelbrot_inception") == 0 || ft_strcmp(av, "10") == 0)
	{
		h->fract = 10;
		h->f = &madelbrot_inception_set;
		h->name = "Madelbrot inception";
	}
	else if (ft_strcmp(av, "double_tear_drop") == 0 || ft_strcmp(av, "11") == 0)
	{
		h->fract = 11;
		h->f = &double_tear_drop_set;
		h->name = "Double tear drop";
	}
	else if (ft_strcmp(av, "reverse_mandelbrot") == 0 ||
			ft_strcmp(av, "12") == 0)
	{
		h->fract = 12;
		h->f = &reverse_mandelbrot_set;
		h->name = "Reverse mandelbrot";
	}
	else
		return (1);
	return (0);
}
