/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:11:36 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/08 21:24:16 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_merge(t_fdf **up, t_fdf **down)
{
    t_fdf	*head;
    t_fdf	*tail;
    
    head = *up;
    tail = *down;
    while (*up)
    {
        (*up)->down = *down;
        *up = (*up)->right;
        *down = (*down)->right;
    }
    *up = head;
    *down = tail;
}

void	ft_mod_cord(t_fdf *node, int x, int y, int z)
{
	node->c_x = x;
	node->c_y = y;
	node->c_z = z;
}

void    ft_get_root(int def_color, int err_color, t_root *new)
{
    new->def_color = def_color;
    new->err_color = err_color;
    new->head = NULL;
    new->matrix_size = 0;
    new->status = 0;
	new->w_h = 400;
	new->w_w = 400;
}

t_fdf	*ft_new_node(int y, int x, int z, int color)
{
	t_fdf   *new;
	
	new = (t_fdf*)malloc(sizeof(t_fdf));
	new->c_x = x;
	new->c_y = y;
	new->c_z = z;
	new->color = color;
	new->right = NULL;
	new->down = NULL;
    new->diag = NULL;
	return (new);
}
