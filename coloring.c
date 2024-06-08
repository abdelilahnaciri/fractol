#include "fractol.h"

int	set_color(int iterations, int max_it)
{
	int	red;
	int	green;
	int	blue;

	if (iterations == max_it)
		return (0x000000);
	else
	{
		red = (iterations * 5) % 255;
		green = (iterations * 5) % 255;
		blue = (iterations * 2) % 255;
		return ((red << 8) | (green << 8) | blue);
	}
}
