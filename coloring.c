/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:38:26 by abnaciri          #+#    #+#             */
/*   Updated: 2024/06/08 20:41:49 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_color(int iterations, int max_it)
{
	int	red;
	int	green;
	int	blue;

	if (iterations == max_it)
		return (0x000000);
	else
	{
		red = ((iterations % 250) * iterations / 10);
		green = ((iterations % 250) * (iterations));
		blue = ((iterations % 250) * iterations / 6);
		return ((red << 16) | (green << 8) | blue);
	}
}
