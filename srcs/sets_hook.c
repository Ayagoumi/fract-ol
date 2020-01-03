/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 13:16:20 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 01:25:03 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_infos(t_fractol *h)
{
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 5, 0, 16777215,
			"Mouse X = ");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 110, 0, 16777215,
			ft_itoa(h->x));
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 5, 20, 16777215,
			"Mouse Y = ");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 110, 20, 16777215,
			ft_itoa(h->y));
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 180, 3, 16777215,
			"|");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 180, 25, 16777215,
			"|");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 0, 40, 16777215,
			"------------------");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, WIN_WIDTH - 70,
			WIN_HEIGTH - 30, 16777215, ft_itoa(h->nmax));
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, WIN_WIDTH - 190,
			WIN_HEIGTH - 30, 16777215, "Iteration = ");
	show_infos2(h);
	show_infos3(h);
}

void	show_infos2(t_fractol *h)
{
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 5, WIN_HEIGTH - 60, 16777215,
			"Move X = ");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 90, WIN_HEIGTH - 60, 16777215,
			ft_itoa(h->mv_x_re));
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 110, WIN_HEIGTH - 60, 16777215,
			"+");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 130, WIN_HEIGTH - 60, 16777215,
			ft_itoa(h->mv_x_im));
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 150, WIN_HEIGTH - 60, 16777215,
			"i");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 5, WIN_HEIGTH - 30, 16777215,
			"Move Y = ");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 90, WIN_HEIGTH - 30, 16777215,
			ft_itoa(h->mv_y_re));
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 110, WIN_HEIGTH - 30, 16777215,
			"+");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 130, WIN_HEIGTH - 30, 16777215,
			ft_itoa(h->mv_y_im));
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 150, WIN_HEIGTH - 30, 16777215,
			"i");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, WIN_WIDTH / 2 - 150, 10,
			16777215, "Fract'ol name : ");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, WIN_WIDTH / 2, 10, 16777215,
			h->name);
}

void	show_infos3(t_fractol *h)
{
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 4 * (WIN_WIDTH / 6) - 20
			, 30, 16777215, "Press (1-9): Change fractols");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 4 * (WIN_WIDTH / 6) - 20
			, 60, 16777215, "Press (q-w-e): Change fractols");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 4 * (WIN_WIDTH / 6) - 20
			, 90, 16777215, "Press (+/-): Inc/Dec iterations");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 4 * (WIN_WIDTH / 6) - 20
			, 120, 16777215, "Press arrows: Movement");
	mlx_string_put(h->mlx.mlx_ptr, h->mlx.win, 4 * (WIN_WIDTH / 6) - 20
			, 150, 16777215, "Press (c|v): Change colors");
	show_infos2(h);
}
