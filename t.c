/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:04:12 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/20 17:05:11 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <mlx.h>

int		my_key_beer(int	keycode, void *window)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53 || keycode == 49)
		exit(printf("Escape\n"));
	return (0);
}

void    ft_i_put_pixel(char **data, int color, unsigned char opacity)
{
    **data = color;
    *(*data + 1) = color >> 8;
    *(*data + 2) = color >> 16;
    *(*data + 3) = opacity;
}

void    ft_get_pixel_pos(int x, int y, char **data, int sl)
{
    *data += (y * sl) + (x * 4);
}

int		ft_get_color(int c0, int c1, int n, int x)
{
	static unsigned char	bt[7];
	static short			lt[3];
	static int				max;
	int						res;
	
	if (n == 0)
	{
		bt[0] = c0;
		bt[1] = c0 >> 8;
		bt[2] = c0 >> 16;
		bt[3] = c1;
		bt[4] = c1 >> 8;
		bt[5] = c1 >> 16;
		lt[0] = bt[0] - bt[3];
		lt[1] = bt[1] - bt[4];
		lt[2] = bt[2] - bt[5];
		max = x != 1 ? x - 1 : x;
	}
	res = 0;
	res += (bt[0] - lt[0] * n / max);
	res += (int)((bt[1] - lt[1] * n / max) << 8);
	res += (int)((bt[2] - lt[2] * n / max) << 16);
	return (res);
}

/* Xiaolin Wu's line algo */
void    ft_change_data(char **data, int sl)
{
	int color_0 = 0x820202;
	int	color_1 = 0xffffff;

	int x0 = 0;
    int y0 = 0;
    int x1 = 1;
    int y1 = 1;

/*
	int x0 = 10;
	int y0 = 10;
	int x1 = 300;
	int y1 = 10;
*/
/*
	int x0 = 10;
	int y0 = 10;
	int x1 = 300;
	int y1 = 300;
*/
	int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int     dx = abs(x1 - x0);
    int     dy = abs(y1 - y0);
	int x;
	if (dy > dx)
		x = dy;
	if (dx >= dy)
		x = dx;
    int     err = dx - dy;
    int     t_err;
    int     x2;
    int     ed = dx + dy == 0 ? 1 : sqrtf(pow(dx, 2) + pow(dy, 2));
    char    *tmp = *data;
	int		n = 0;
	int change /*= ft_get_color(color_0, color_1, 0, dx)*/;
	
	
    while (x0 != x1 || y0 != y1)
    {
        *data = tmp;
        ft_get_pixel_pos(x0, y0, data, sl);
		change = ft_get_color(color_0, color_1, n, x);
		ft_i_put_pixel(data, change, 255*abs(err - dx + dy) / ed);
		t_err = err;
        x2 = x0;
        if (t_err << 1 >= -dx)
        {
            if (t_err + dy < ed)
            {
                *data = tmp;
                ft_get_pixel_pos(x0, y0 + sy, data, sl);
                ft_i_put_pixel(data, change, 255*(t_err + dy) / ed);
            }
            err -= dy;
            x0 += sx;
			
		}
        if (t_err << 1 <= dy)
        {
            if (dx - t_err < ed)
            {
                *data = tmp;
                ft_get_pixel_pos(x2 + sx, y0, data, sl);
                ft_i_put_pixel(data, change, 255*(dx - t_err) / ed);
            }
            err += dx;
            y0 += sy;
        }
		++n;
    }
}


/*   alised Bresenham's algo
void    ft_change_data(char **data, int sl)
{
    int x0 = 1;
    int y0 = 1;
    int x1 = 8;
    int y1 = 150;
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int     dx = abs(x1 - x0);
    int     dy = -abs(y1 - y0);
    int     err = dx + dy;
    int     t_err;
    char    *tmp = *data;
 
    while (x0 != x1 && y0 != y1)
    {
        *data = tmp;
        ft_get_pixel_pos(x0, y0, data, sl);
        ft_i_put_pixel(data, 16777215, 0);
        t_err = 2 * err;
        if (t_err >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (t_err <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
*/
int		main(void)
{
	void	*init;
	void	*image;
	void 	*window;
	char 	*data;
	int		x = 0;
	int		y = 0;
	int		z = 400;
	int 	bpp;
	int		sl;
	int		endian;

	if ((init = mlx_init()) == NULL)
		return (-1);
	printf("init: %p\n", init);
	if ((window = mlx_new_window(init, 400, 400, "window")) == NULL)
		return (-2);
	printf("window: %p\n", window);
	mlx_key_hook(window, my_key_beer, window);
	image = mlx_new_image(init, 400, 400);
	data = mlx_get_data_addr(image, &bpp, &sl, &endian);
	ft_change_data(&data, sl);
	printf("bpp: %i\nendian: %i\n", bpp, endian);
	mlx_put_image_to_window(init, window, image, 0, 0);
	mlx_loop(init);
	return (0);
}
