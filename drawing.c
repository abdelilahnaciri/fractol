
#include "fractol.h"

void	ft_put_pixel_to_image(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fractol->image.addr + (y * fractol->image.line_length
				+ x * (fractol->image.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

double	ft_scale_coordinate_x(t_fractol *fractol, int x)
{
	double	center_x;

	center_x = WIDTH / 2.0;
	return ((x - center_x) * (4.0 * fractol->zoom) / WIDTH);
}

double	ft_scale_coordinate_y(t_fractol *fractol, int y)
{
	double	center_y;
	double	inverted_y;

	center_y = HEIGHT / 2.0;
	inverted_y = HEIGHT - y;
	y = inverted_y - center_y;
	return (y * (4.0 * fractol->zoom) / HEIGHT);
}

void	ft_draw_fractal_pixel(t_fractol *fractol, int x, int y)
{
	int	color;
	int	iterations;

	iterations = 0;
	fractol->pixel.real = ft_scale_coordinate_x(fractol, x);
	fractol->pixel.imaginary = ft_scale_coordinate_y(fractol, y);
	if (!ft_strncmp(fractol->title, "Mandelbrot", 10))
		iterations = ft_calculate_mandelbrot(fractol, fractol->max_iterations);
	else if (!ft_strncmp(fractol->title, "Julia", 5))
		iterations = ft_calculate_julia(fractol, fractol->max_iterations);
	color = ft_determine_color(iterations, fractol->max_iterations);
	ft_put_pixel_to_image(fractol, x, y, color);
}
