

#include "fractol.h"

int	handle_max_int(char *str)
{
	int	nb;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if ((nb * sign) > 2 || (nb * sign) < -2)
			return (0);
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;
    int dot;

    i = 0;
    dot = 0;
    while (str[i])
    {
		if (str[i] <= 32 || str[0] == '.')
			return (0);
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9') && str[i + 1] != '\0' && str[i + 1] != '.')
                return (0);
        }
		else if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (0);
		}
        else if (str[i] == '.') {
            dot++;
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '\0')
                return (0);
        }
		else
            return (0);
		i++;
	}
	if (dot > 1 || !handle_max_int(str))
		return (0);
	return (1);
}

void	check_inputs(char *argv[], t_fractol *fractol)
{
	if (is_number(argv[2]) && is_number(argv[3]))
	{
		fractol->julia_args.julia_x = ft_atof(argv[2]);
		fractol->julia_args.julia_y = ft_atof(argv[3]);
		if ((fractol->julia_args.julia_x < -2 || fractol->julia_args.julia_y < -2)
		|| (fractol->julia_args.julia_x > 2 || fractol->julia_args.julia_y > 2)) {
			printf("Cordinates should be btween -2 and 2\n");
			exit(0);
		}
		printf("good numbers\n");
		printf("num1 : %f\n", fractol->julia_args.julia_x);
		printf("num2 : %f\n", fractol->julia_args.julia_y);
	}
	else
	{
		ft_putstr_fd("Error: Invalid parameters for Julia.\n", 2);
		exit(0);
	}
}
