/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:39:12 by abnaciri          #+#    #+#             */
/*   Updated: 2024/06/08 20:50:36 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_atoi(const char *s)
{
	int	nb;
	int	sign;
	int	i;

	sign = 1;
	nb = 0;
	i = 0;
	while (s[i] && s[i] <= 13)
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	return (nb * sign);
}

double	ft_fractional_part(const char *str)
{
	double	fractional;
	int		divisor;

	fractional = 0.0;
	divisor = 1;
	while (*str != '\0')
	{
		fractional = fractional * 10 + (*str - '0');
		divisor *= 10;
		str++;
	}
	return (fractional / divisor);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	integer_part;
	double	fractional_part;

	sign = 1;
	fractional_part = 0.0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	integer_part = (double)ft_atoi(str);
	while (*str != '\0' && *str != '.')
		str++;
	if (*str == '.')
	{
		str++;
		fractional_part = ft_fractional_part(str);
	}
	return (sign * (integer_part + fractional_part));
}
