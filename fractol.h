/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:39:01 by abnaciri          #+#    #+#             */
/*   Updated: 2024/06/09 15:53:23 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800

# define KEY_ESC 53
# define SCROLL_IN_KEY 4
# define SCROLL_OUT_KEY 5

typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_julia_args
{
	double	julia_x;
	double	julia_y;
}	t_julia_args;

typedef struct s_fractol
{
	void			*mlx_con;
	void			*mlx_win;
	char			*title;
	t_image			image;
	t_complex		c;
	t_complex		pixel;
	int				max_it;
	double			zoom;
	t_julia_args	julia_args;
}	t_fractol;

void	ft_init_win(t_fractol *fractol);
int		ft_close_win(t_fractol *fractol);

int		set_color(int iterations, int max_it);
void	ft_put_pixel_to_image(t_fractol *fractol, int x, int y, int color);
double	calc_coordinate_x(t_fractol *fractol, int x);
double	calc_coordinate_y(t_fractol *fractol, int y);
void	set_fractol(t_fractol *fractol, int x, int y);

int		ft_fractol(t_fractol *fractol);
int		calc_iteration(t_complex z, t_complex c, int max_it);
int		calc_mandelbrot(t_fractol *fractol, int max_it);
int		calc_julia(t_fractol *fractol, int max_it);

void	set_hooks(t_fractol *fractol);
int		esc_key_press(int key, t_fractol *fractol);
int		mouse_scroll(int scroll, int x, int y, t_fractol *fractol);

void	ft_putstr_fd(char *s, int fd);
double	ft_atof(const char *str);
int		is_number(char *str);
void	check_inputs(char *argv[], t_fractol *fractol);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

#endif
