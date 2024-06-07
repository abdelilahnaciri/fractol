

#include "fractol.h"

int	ft_determine_color(int iterations, int max_iterations)
{
	int	red;
	int	green;
	int	blue;

	if (iterations == max_iterations)
		return (0x000000);
	else
	{
		red = (iterations * 5) % 255;
		green = (iterations * 3) % 255;
		blue = (iterations * 7) % 255;
		return ((red << 16) | (green << 8) | blue);
	}
}
