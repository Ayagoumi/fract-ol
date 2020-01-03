/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:37:31 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:39:49 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(int nb, char *av)
{
	if (nb == 0)
	{
		ft_putendl("\033[41m ERROR :\033[0m ./fractol <name_of_fractal>");
		ft_putendl("\033[41m ERROR :\033[0m ./fractol <nb_of_the_fractal>\n");
	}
	else if (nb == 1)
	{
		ft_putstr("Fractal ");
		ft_putstr(av);
		ft_putendl(" don't exist");
		exit(EXIT_FAILURE);
	}
	else if (nb == 2)
		ft_putendl("\033[41m ERROR :\033[0m Wrong number of argument");
}
