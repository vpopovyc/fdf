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

t_fdf	*ft_move_down(t_fdf *sp, int n)
{
	t_fdf 	*tmp;

	tmp = sp == NULL ? ft_new_node(0, 0, 0, NULL) : sp;
	while (--n > 0)
		tmp = tmp->down;
	return (tmp);
}

void	ft_mod_conn(t_fdf *node, t_fdf *right_node, t_fdf *down_node)
{
	node->right = right_node;
	node->down = down_node;
}

void	ft_mod_cord(t_fdf *node, int x, int y, int z)
{
	node->c_x = x;
	node->c_y = y;
	node->c_z = z;
}

t_fdf	*ft_new_node(int x, int y, int z, char *color)
{
	t_fdf	*new;
	
	new = (t_fdf*)malloc(sizeof(t_fdf));
	new->c_x = x;
	new->c_y = y;
	new->c_z = z;
	new->color = color;
	new->right = NULL;
	new->down = NULL;
	return (new);
}
