/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:51:56 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/08 21:24:08 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FDF_H
# define __FT_FDF_H

#include "libft/includes/libft.h"
typedef	struct	s_fdf
{
	int			c_x;
	int			c_y;
	int			c_z;
	char		*color;	
	t_fdf		*right;
	t_fdf		*down;
}				t_fdf;
/* ft_s_fdf.h */
void	ft_mod_conn(t_fdf *node, t_fdf *right_node, t_fdf *down_node);
void	ft_mod_cord(t_fdf *node, int x, int y, int z);
t_fdf	*ft_new_node(int x, int y, int z, char *color);
/* ft_parse */
int		ft_parse(int fd, t_fdf *sp);
/*typedef	struct	s_rgb
{
	char	*red;
	char	*green;
	char	*blue;
}				t_rbg;*/
#endif

/* TO DO
 * ok, buss stoped in ft_parse.c
 * ft_loop – norm error
 * use brains
 * ft_parse – needs to be ended
 * sometimes ...
 */
