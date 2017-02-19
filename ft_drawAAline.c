/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawAAline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 17:18:46 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/19 17:18:51 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void    ft_i_put_pixel(t_root *root, int color, unsigned char opacity)
{
	*(root->i_data) = color;
	*(root->i_data + 1) = color >> 8;
	*(root->i_data + 2) = color >> 16;
	*(root->i_data + 3) = opacity;
}

void    ft_get_pixel_pos(int x, int y, t_root *root)
{
	root->i_data += (y * root->size_line) + (x * 4);
}

void	ft_x_move(t_root *root, t_ld *ld)
{
	if (ld->t_err + ld->dy < ld->de)
	{
		root->i_data = ld->t_i_data;
		ft_get_pixel_pos(ld->x0, ld->y0 + ld->sy, root);
		ft_i_put_pixel(root, 16777215, 255*(ld->t_err + ld->dy) / ld->de);
	}
	ld->err -= ld->dy;
	ld->x0 += ld->sx;
}

void	ft_y_move(t_root *root, t_ld *ld)
{
	if (ld->dx - ld->t_err < ld->de)
	{
		root->i_data = ld->t_i_data;
		ft_get_pixel_pos(ld->t_x0 + ld->sx, ld->y0, root);
		ft_i_put_pixel(root, 16777215, 255*(ld->dx - ld->t_err) / ld->de);
	}
	ld->err += ld->dx;
	ld->y0 += ld->sy;
}

void	ft_change_data(t_root *root, t_fdf *p_start, t_fdf *p_end)
{
	t_ld	ld;
	
	ld.x0 = p_start->c_x;
	ld.y0 = p_start->c_y;
	ld.x1 = p_end->c_x;
	ld.y1 = p_end->c_y;
	ld.sx = ld.x0 < ld.x1 ? 1 : -1;
	ld.sy = ld.y0 < ld.y1 ? 1 : -1;
	ld.dx = abs(ld.x1 - ld.x0);
	ld.dy = abs(ld.y1 - ld.y0);
	ld.de = ld.dx + ld.dy == 0 ? 1 : sqrtf(ld.dx * ld.dx + ld.dy * ld.dy);
	ld.err = ld.dx - ld.dy;
	ld.t_i_data = root->i_data;
	while (ld.x0 <= ld.x1 || ld.y0 <= ld.y1)
	{
		root->i_data = ld.t_i_data;
		ft_get_pixel_pos(ld.x0, ld.y0, root);
		ft_i_put_pixel(root, 16777215, 255*abs(ld.err - ld.dx + ld.dy) / ld.de);
		ld.t_err = ld.err;
		ld.t_x0 = ld.x0;
		2 * ld.t_err >= -ld.dx ? ft_x_move(root, &ld) : 0;
		2 * ld.t_err <= ld.dy ? ft_y_move(root, &ld) : 0;
	}
}
