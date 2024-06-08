/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:38:55 by abnaciri          #+#    #+#             */
/*   Updated: 2024/06/08 20:43:08 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia(t_fractol *fractol, int max_it)
{
	fractol->c.real = fractol->julia_args.julia_x;
	fractol->c.img = fractol->julia_args.julia_y;
	return (calc_iteration(fractol->pixel, fractol->c, max_it));
}

int	calc_mandelbrot(t_fractol *fractol, int max_it)
{
	fractol->c.real = 0;
	fractol->c.img = 0;
	return (calc_iteration(fractol->c, fractol->pixel, max_it));
}

int	calc_iteration(t_complex z, t_complex c, int max_it)
{
	int		iterations;
	double	real;
	double	img;

	iterations = 0;
	while (iterations < max_it)
	{
		real = z.real * z.real - z.img * z.img + c.real;
		img = 2 * z.real * z.img + c.img;
		z.real = real;
		z.img = img;
		if (z.real * z.real + z.img * z.img > 4)
			break ;
		iterations++;
	}
	return (iterations);
}
