/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:18:46 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/23 14:50:51 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void    ft_drawpixel(t_root *root, t_fdf *pixel)
{
    char    *i_tmp;
    
    root->x_md = (root->x_max + root->head->c_x) / 2;
    root->y_md = (root->y_max + root->head->c_y) / 2;
    i_tmp = root->i_data;
    ft_get_pixel_pos(((pixel->c_x - root->x_md) * root->mult) + root->move_r - root->move_l, ((pixel->c_y  - root->y_md) * root->mult) + root->move_u - root->move_d, root);
    ft_i_put_pixel(root, pixel->color, 0);
    root->i_data = i_tmp;
}
