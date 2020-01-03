/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:04:29 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:38:26 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		assi_fonct(char *av, t_fractol *h)
{
	if (assi_fonct1(av, h) == 0 || assi_fonct2(av, h) == 0)
		return (0);
	else if (assi_fonct3(av, h) == 0 || assi_fonct4(av, h) == 0)
		return (0);
	return (1);
}

void	one_arg(char *av, t_fractol *h)
{
	int	m;

	m = 0;
	if ((m = assi_fonct(av, h)) == 1)
		error_msg(1, av);
	else
	{
		init_struct(h);
		h->mlx.mlx_ptr = mlx_init();
		h->mlx.win = mlx_new_window(h->mlx.mlx_ptr,
				WIN_WIDTH, WIN_HEIGTH, "Fract'ol");
		h->mlx.img.img_ptr = mlx_new_image(h->mlx.mlx_ptr,
				WIN_WIDTH, WIN_HEIGTH);
		h->mlx.img.data = (int *)mlx_get_data_addr(h->mlx.img.img_ptr,
				&h->mlx.img.bpp, &h->mlx.img.size_l, &h->mlx.img.endian);
		threading(h);
		mlx_put_image_to_window(h->mlx.mlx_ptr,
				h->mlx.win, h->mlx.img.img_ptr, 0, 0);
		mlx_hook(h->mlx.win, 2, 0, hook, h);
		mlx_hook(h->mlx.win, 4, 0, zoom_in_hook, h);
		mlx_hook(h->mlx.win, 6, 0, thread_hook, h);
		show_infos(h);
		mlx_loop(h->mlx.mlx_ptr);
	}
}

void	sub_arg_two(t_fractol *h1, t_fractol *h2)
{
	h2->mlx.mlx_ptr = h1->mlx.mlx_ptr;
	h1->mlx.win = mlx_new_window(h1->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGTH, "Fract'ol");
	h2->mlx.win = mlx_new_window(h2->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGTH, "Fract'ol");
	h1->mlx.img.img_ptr = mlx_new_image(h1->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGTH);
	h2->mlx.img.img_ptr = mlx_new_image(h2->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGTH);
	h1->mlx.img.data = (int *)mlx_get_data_addr(h1->mlx.img.img_ptr,
			&h1->mlx.img.bpp, &h1->mlx.img.size_l, &h1->mlx.img.endian);
	h2->mlx.img.data = (int *)mlx_get_data_addr(h2->mlx.img.img_ptr,
			&h2->mlx.img.bpp, &h2->mlx.img.size_l, &h2->mlx.img.endian);
	threading(h1);
	threading(h2);
	mlx_put_image_to_window(h1->mlx.mlx_ptr,
			h1->mlx.win, h1->mlx.img.img_ptr, 0, 0);
	mlx_put_image_to_window(h2->mlx.mlx_ptr,
			h2->mlx.win, h2->mlx.img.img_ptr, 0, 0);
	mlx_hook(h1->mlx.win, 2, 0, hook, h1);
	mlx_hook(h2->mlx.win, 2, 0, hook, h2);
	mlx_hook(h1->mlx.win, 4, 0, zoom_in_hook, h1);
	mlx_hook(h2->mlx.win, 4, 0, zoom_in_hook, h2);
}

void	two_arg(char *av1, char *av2, t_fractol *h1, t_fractol *h2)
{
	int m;

	if ((m = assi_fonct(av1, h1)) == 1)
		error_msg(1, av1);
	if ((m = assi_fonct(av2, h2)) == 1)
		error_msg(1, av2);
	else
	{
		init_struct(h1);
		init_struct(h2);
		h1->mlx.mlx_ptr = mlx_init();
		sub_arg_two(h1, h2);
		show_infos(h1);
		show_infos(h2);
		mlx_loop(h1->mlx.mlx_ptr);
	}
}

int		main(int ac, char **av)
{
	int			i;
	int			j;
	t_fractol	fra;
	t_fractol	fra2;

	i = 0;
	j = 0;
	if (ac == 1)
		error_msg(0, NULL);
	else if (ac == 2)
		one_arg(av[1], &fra);
	else if (ac == 3)
		two_arg(av[1], av[2], &fra, &fra2);
	else
		error_msg(2, NULL);
	return (0);
}
