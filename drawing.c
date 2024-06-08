
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

double	calc_coordinate_x(t_fractol *fractol, int x)
{
	double	center_x;

	center_x = WIDTH / 2.0;
	return ((x - center_x) * (4.0 * fractol->zoom) / WIDTH);
}

double	calc_coordinate_y(t_fractol *fractol, int y)
{
	double	center_y;
	double	inverted_y;

	center_y = HEIGHT / 2.0;
	inverted_y = HEIGHT - y;
	y = inverted_y - center_y;
	return (y * (4.0 * fractol->zoom) / HEIGHT);
}

void	set_fractol(t_fractol *fractol, int x, int y)
{
	int	color;
	int	iterations;

	iterations = 0;
	fractol->pixel.real = calc_coordinate_x(fractol, x);
	fractol->pixel.img = calc_coordinate_y(fractol, y);
	if (!ft_strncmp(fractol->title, "Mandelbrot", 10))
		iterations = calc_mandelbrot(fractol, fractol->max_it);
	else if (!ft_strncmp(fractol->title, "Julia", 5))
		iterations = calc_julia(fractol, fractol->max_it);
	color = set_color(iterations, fractol->max_it);
	ft_put_pixel_to_image(fractol, x, y, color);
}

int	ft_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			set_fractol(fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_con, fractol->mlx_win,
		fractol->image.img_ptr, 0, 0);
	return (0);
}