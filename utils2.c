#include "fractol.h"

void	check_inputs(char *argv[], t_fractol *fractol)
{
	if (is_number(argv[2]) && is_number(argv[3]))
	{
		fractol->fractal_config.julia_x = ft_atof(argv[2]);
		fractol->fractal_config.julia_y = ft_atof(argv[3]);
		if ((fractol->fractal_config.julia_x < -2 || fractol->fractal_config.julia_y < -2)
		|| (fractol->fractal_config.julia_x > 2 || fractol->fractal_config.julia_y > 2)) {
			printf("Cordinates should be btween -2 and 2\n");
			exit(0);
		}
		printf("good numbers\n");
		printf("num1 : %f\n", fractol->fractal_config.julia_x);
		printf("num2 : %f\n", fractol->fractal_config.julia_y);
	}
	else
	{
		ft_putstr_fd("Error: Invalid parameters for Julia.\n", 2);
		exit(0);
	}
}
