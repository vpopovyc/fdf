/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:51:56 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/10 15:04:07 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FDF_H
# define __FT_FDF_H

#include "libft/includes/libft.h"

typedef	struct		s_fdf
{
	int				c_x;
	int				c_y;
	int             c_z;
	int				color;
    struct s_fdf	*right;
    struct s_fdf	*diag;
	struct s_fdf	*down;
}					t_fdf;

typedef struct		s_root
{
	int				def_color;
	int				err_color;
	size_t			matrix_size;
	unsigned char	status;
	struct s_fdf	*head;
}					t_root;

# define BS 8
/* ft_s_fdf.h */
void	ft_mod_cord(t_fdf *node, int x, int y, int z);
t_fdf	*ft_new_node(int x, int y, int z, int color);
void	ft_get_root(int def_color, int err_color, t_root *new);
/* ft_parse */
void    ft_color(t_root *root, char **line, t_fdf **node);
t_fdf	*ft_loop(char *line, int n, t_root *root);
void	ft_merge(t_fdf **up, t_fdf **down);
void	ft_spc(size_t *y, char *f, t_fdf **head, t_fdf **node);
int		ft_parse(int fd, t_root *root);
#endif

/* TO DO
 * almost done parsing and validating
 * hehehe, fix reversed color saving :)
 * use brains sometimes ...
 */
