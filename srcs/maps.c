/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:36:41 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:39:50 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(int position, int max_wh, double new_min_scope
		, double new_max_scope)
{
	double range;

	range = new_max_scope - new_min_scope;
	return (new_min_scope + position * (range / max_wh));
}
