/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:23:01 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/16 15:23:03 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_rec(t_root *root, t_fdf *head, t_fdf *draw)
{
	if (draw->right != NULL && draw->down != NULL && draw->diag != NULL)
		return ;
	if (draw->right != NULL)
		ft_rec(root, head, draw->right);
	else if (draw->right == NULL && draw->down != NULL)
		ft_rec(root, head->down, head->down);
	if (draw->right != NULL)
		ft_change_data(root, draw, draw->right);
	if (draw->down != NULL)
		ft_change_data(root, draw, draw->down);
	if (draw->diag != NULL)
		ft_change_data(root, draw, draw->diag);
}

void	ft_fill_image(t_root *root)
{
	t_fdf	*head;
	t_fdf	*draw;
	
	head = root->head;
	draw = head;
	if (draw != NULL)
		ft_rec(root, head, draw);
}

int		ft_image(t_root *root)
{
	int		bpp;
	int		en;
	
	root->img = mlx_new_image(root->init, root->w_w + 100, root->w_w + 100);
	root->i_data = mlx_get_data_addr(root->img, &bpp, &root->size_line, &en);
	ft_fill_image(root);
	printf("here\n");
	mlx_put_image_to_window(root->init, root->win, root->img, 0, 0);
	return (1);
}

int		ft_key_hook(int keycode, t_root *root)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == 53 || keycode == 49)
		exit(ft_printf("Kill pid\n"));
	if (keycode == 34)
		ft_image(root);
	return (0);
}

int		ft_init_image(t_root *root)
{
	root->init = mlx_init();
	if (root->init == NULL)
		exit(ft_printf("Couldn't establish connection\n"));
	root->win = mlx_new_window(root->init, root->w_h, root->w_w, "fil de fer");
	if (root->win == NULL)
		exit(ft_printf("Couldn't create window\n"));
	mlx_key_hook(root->win, ft_key_hook, root);
	mlx_loop(root->init);
	return (0);
}
