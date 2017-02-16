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

void	ft_change_data(char **data, int sl)
{
	char 	*t_ad;
	int		color = 0x820202;
	int		mult = 1;
	int		x = 0;
	int		y = 150;
	int		n = 500;
	
/*	while (--n)
	{
		t_ad = *data;
		t_ad += (y * sl + x * 4) * mult;
		if (x * mult > 400)
			break;
		*t_ad = color;	
		*(t_ad + 1) = color >> 8;
		*(t_ad + 2) = color >> 16;
		x++;
	}
	*/
}

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
//	image = mlx_new_image(init, 500, 500);
//	data = mlx_get_data_addr(image, &bpp, &sl, &endian);
//	ft_change_data(&data, sl);
	while (--z)
	{
		while (++x < 200)
			mlx_pixel_put(init, window, x, y, 648490);
		x = 0;
		++y;
	}
//	printf("bpp: %i\nendian: %i\n", bpp, endian);
//	mlx_put_image_to_window(init, window, image, 0, -50);
	mlx_loop(init);
	return (0);
}
