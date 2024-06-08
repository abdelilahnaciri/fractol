#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>
# include <stdbool.h>

// Window
# define WIDTH 800
# define HEIGHT 800

// keys
# define KEY_ESC 53

// Mouse
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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_julia_args
{
	char	type;
	double	julia_x;
	double	julia_y;
}	t_julia_args;

typedef struct s_fractol
{
	// Window and image info
	void				*mlx_con;
	void				*mlx_win;
	char 				*title;
	t_image image;
	// complex numbers
	t_complex			c;
	t_complex			pixel;
	// Fractal specific parameters
	int					max_it;
	double				zoom;
	t_point				offset;
	t_julia_args	julia_args;
}	t_fractol;


// Graphics
// void	ft_setup_window(t_fractol *fractol);
void	ft_init_win(t_fractol *fractol);
int		ft_close_win(t_fractol *fractol);

// Coloring and Drawing
int		set_color(int iterations, int max_it);
void	ft_put_pixel_to_image(t_fractol *fractol, int x, int y, int color);
double	calc_coordinate_x(t_fractol *fractol, int x);
double	calc_coordinate_y(t_fractol *fractol, int y);
void	set_fractol(t_fractol *fractol, int x, int y);

// Rendring and fractal sets
int		ft_fractol(t_fractol *fractol);
int		calc_iteration(t_complex z, t_complex c, int max_it);
int		calc_mandelbrot(t_fractol *fractol, int max_it);
int		calc_julia(t_fractol *fractol, int max_it);

// Events
void	set_hooks(t_fractol *fractol);
int		esc_key_press(int key, t_fractol *fractol);
int		mouse_scroll(int scroll, int x, int y, t_fractol *fractol);

// libft
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *s);
double	ft_process_fractional_part(const char *str);
double	ft_atof(const char *str);

// utils
int is_number(char *str);
void	check_inputs(char *argv[], t_fractol *fractol);
int ft_strncmp(const char *str1, const char *str2, size_t n);

#endif
