/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:35:50 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/26 17:36:10 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_keycode_angle(int keycode, t_root *root)
{
	if (keycode == 6)
		root->x_an += 10;
	else if (keycode == 7)
		root->x_an -= 10;
	else if (keycode == 8)
		root->y_an += 10;
	else if (keycode == 9)
		root->y_an -= 10;
	else if (keycode == 11)
		root->z_an += 10;
	else if (keycode == 45)
		root->z_an -= 10;
	mlx_destroy_image(root->init, root->img);
	ft_image(root);
	mlx_clear_window(root->init, root->win);
	mlx_put_image_to_window(root->init, root->win, root->img, 0, 0);
}

void	ft_keycode_moves(int keycode, t_root *root)
{
	if (keycode == 125)
		root->move_u += 10;
	else if (keycode == 126)
		root->move_d += 10;
	else if (keycode == 124)
		root->move_r += 10;
	else if (keycode == 123)
		root->move_l += 10;
	mlx_destroy_image(root->init, root->img);
	ft_image(root);
	mlx_clear_window(root->init, root->win);
	mlx_put_image_to_window(root->init, root->win, root->img, 0, 0);
}

void	ft_multiply(t_root *root, int keycode)
{
	if (keycode == 24)
		root->mult = root->mult + 10;
	else if (keycode == 27)
		root->mult = root->mult - 10 < 0 ? 1 : root->mult - 10;
	mlx_destroy_image(root->init, root->img);
	ft_image(root);
	mlx_clear_window(root->init, root->win);
	mlx_put_image_to_window(root->init, root->win, root->img, 0, 0);
}

void	ft_kittens_killa(t_root *root)
{
	mlx_destroy_image(root->init, root->img);
	mlx_clear_window(root->init, root->win);
	root->move_u = 0;
	root->move_d = 0;
	root->move_l = 0;
	root->move_r = 0;
	root->x_an = 0;
	root->y_an = 0;
	root->z_an = 0;
	root->mult = 1;
}

void	ft_matrix_control(int keycode, t_root *root)
{
	if (keycode == 53 || keycode == 49)
		exit(ft_printf("Kill pid\n"));
	if (keycode == 34)
	{
		ft_image(root);
		mlx_put_image_to_window(root->init, root->win, root->img, 0, 0);
	}
	if (keycode == 2)
		ft_kittens_killa(root);
	if (keycode == 24 || keycode == 27)
		ft_multiply(root, keycode);
}
