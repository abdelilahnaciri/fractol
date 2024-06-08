#include "fractol.h"

int	esc_key_press(int key, t_fractol *fractol)
{
	if (key == KEY_ESC)
		ft_close_win(fractol);
	return (0);
}

int	mouse_scroll(int scroll, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (scroll == SCROLL_IN_KEY)
		fractol->zoom *= 1.1;
	else if (scroll == SCROLL_OUT_KEY)
		fractol->zoom /= 1.1;
	return (0);
}

void	set_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, esc_key_press, fractol);
	mlx_mouse_hook(fractol->mlx_win, mouse_scroll, fractol);
	mlx_hook(fractol->mlx_win, 17, 0, ft_close_win, fractol);
	mlx_loop_hook(fractol->mlx_con, ft_fractol, fractol);
}
