
#include "fractol.h"
void error_msg() {
	ft_putstr_fd("Enter \"Mandelbrot\", or \"Julia\" + Cordinates\n", 1);
	exit(0);
}

int	ft_close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_con, fractol->image.img_ptr);
	mlx_destroy_window(fractol->mlx_con, fractol->mlx_window);
	exit(EXIT_FAILURE);
}

void	ft_init_window(t_fractol *fractol)
{
	fractol->mlx_con = mlx_init();
	if (!fractol->mlx_con)
		exit(1);
	fractol->mlx_window = mlx_new_window(fractol->mlx_con, HEIGHT, WIDTH, fractol->title);
	if (!fractol->mlx_window)
		exit(1);
	fractol->image.img_ptr = mlx_new_image(&fractol->image, HEIGHT, WIDTH);
	if (!fractol->image.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_con, fractol->mlx_window);
		exit(1);
	}
	fractol->image.addr = mlx_get_data_addr(fractol->image.img_ptr,
			&fractol->image.bits_per_pixel,
			&fractol->image.line_length,
			&fractol->image.endian);
	if (!fractol->image.addr)
		ft_close_window(fractol);
}

int	main(int ac, char *av[])
{
	t_fractol	fractol;

	if (ac == 2 || ac == 4) {
		if (ac == 4 && !ft_strncmp(av[1], "Julia", 5)) {
			check_inputs(av, &fractol);
		}
		else if ((ac == 2 && ft_strncmp(av[1], "Mandelbrot", 10))
		|| (ac == 5 && ft_strncmp(av[1], "Julia", 5)))
		{
			error_msg();
		}
		fractol.zoom = 1;
		fractol.max_iterations = 100;
	} else
		error_msg();
	fractol.title = av[1];
	ft_init_window(&fractol);
	ft_setup_hooks(&fractol);
	mlx_loop(fractol.mlx_con);
	ft_close_window(&fractol);
	return (0);
}
