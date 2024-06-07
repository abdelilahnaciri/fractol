

#include "fractol.h"

int	ft_handle_keypress(int key, t_fractol *fractol)
{
	if (key == KEY_ESC)
		ft_close_window(fractol);
	return (0);
}

int	ft_handle_mouse(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == ZOOM_IN_KEY)
		fractol->zoom *= 1.1;
	else if (button == ZOOM_OUT_KEY)
		fractol->zoom /= 1.1;
	return (0);
}

void	ft_setup_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_window, ft_handle_keypress, fractol);
	mlx_mouse_hook(fractol->mlx_window, ft_handle_mouse, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, ft_close_window, fractol);
	mlx_loop_hook(fractol->mlx_con, ft_render_fractal, fractol);
}
