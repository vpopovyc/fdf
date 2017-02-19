/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:04:12 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/16 21:08:57 by vpopovyc         ###   ########.fr       */
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
	unsigned char	b1_b = c0;
	unsigned char	b1_g = c0 >> 8;
	unsigned char	b1_r= c0 >> 16;
	printf("b1_0: %i\n", b1_b);
	printf("b1_1: %i\n", b1_g);
	printf("b1_2: %i\n", b1_r);
	unsigned char	b2_b = c1;
	unsigned char	b2_g = c1 >> 8;
	unsigned char	b2_r = c1 >> 16;
	printf("* b2_0: %i\n", b2_b);
	printf("* b2_1: %i\n", b2_g);
	printf("* b2_2: %i\n", b2_r);
	unsigned char	b3_b = (b1_b - (b1_b - b2_b) * n / x);
	unsigned char	b3_g = (b1_g - (b1_g - b2_g) * n / x);
	unsigned char	b3_r = (b1_r - (b1_r - b2_r) * n / x);
	printf("b3_0: %i\n", b3_b);
	printf("b3_1: %i\n", b3_g);
	printf("b3_2: %i\n", b3_r);
	
	int		res = 0;
	res += b3_b;
	res += (int)(b3_g << 8);
	res += (int)(b3_r << 16);
	/*res |= (res << 8 | b3_r); 
	res |= (res << 16 | b3_g);
	res |= (res << 24 | b3_b);*/
	printf ("res in hex %x\n\n\n\n", res);
	return (res);
}

/* Xiaolin Wu's line algo */
void    ft_change_data(char **data, int sl)
{
	int color_0 = 0xffffff;
	int	color_1 = 0x000000;
    int x0 = 1;
    int y0 = 1;
    int x1 = 200;
    int y1 = 300;
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int     dx = abs(x1 - x0);
    int     dy = abs(y1 - y0);
    int     err = dx - dy;
    int     t_err;
    int     x2;
    int     ed = dx + dy == 0 ? 1 : sqrtf(pow(dx, 2) + pow(dy, 2));
    char    *tmp = *data;
	int change = ft_get_color(color_0, color_1, x0, x1);
	int n = 1;
	
    while (x0 <= x1 || y0 <= y1)
    {
		change = ft_get_color(color_0, color_1, x0, x1);
        *data = tmp;
        ft_get_pixel_pos(x0, y0, data, sl);
        ft_i_put_pixel(data, change, 255*abs(err - dx + dy) / ed);
        t_err = err;
        x2 = x0;
        if (2 * t_err >= -dx)
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
        if (2 * t_err <= dy)
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
