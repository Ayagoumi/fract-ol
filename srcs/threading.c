/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:43:13 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:43:35 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		threading(t_fractol *h)
{
	pthread_t	thread[4];
	int			i;

	i = 0;
	pthread_create(&thread[0], NULL, thread1, (void *)h);
	pthread_create(&thread[1], NULL, thread2, (void *)h);
	pthread_create(&thread[2], NULL, thread3, (void *)h);
	pthread_create(&thread[3], NULL, thread4, (void *)h);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	destroy_image(h);
	mlx_put_image_to_window(h->mlx.mlx_ptr, h->mlx.win,
			h->mlx.img.img_ptr, 0, 0);
	show_infos(h);
	return (0);
}

int		thread_hook(int x, int y, t_fractol *h)
{
	if (h->fract == 4 && h->nb == 1)
	{
		h->f = julia_update;
		h->x = x;
		h->y = y;
	}
	else if (h->fract == 4 && h->nb == 0 && h->l == 0)
		h->f = julia_set;
	threading(h);
	return (0);
}
