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

# include "libft/includes/libft.h"
# include "minilibx/mlx.h"

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

typedef	 struct		s_root
{
	int				def_color;
	int				err_color;
	int				y_max;
	int 			x_max;
	unsigned char	status;
	void			*init;
	void			*win;
	void			*img;
	char			*i_data;
	int				size_line;
	int				w_h;
	int				w_w;
	int				mult;
	int				x_md;
	int				y_md;
	int				move_u;
	int				move_d;
	int				move_r;
	int				move_l;
	struct s_fdf	*head;
}					t_root;

typedef	 struct		s_ld
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		sx;
	int		sy;
	int		dx;
	int		dy;
	int		de;
	int		err;
	int		t_err;
	int		t_x0;
	int		cl;
	int		cl_min;
	int		cl_max;
	char	*t_i_data;
}					t_ld;

# define BS 8
/* ft_drawpixel.c */
void    ft_drawpixel(t_root *root, t_fdf *pixel);
/* ft_init_image.c */
int		ft_image(t_root *root);
int		ft_init_image(t_root *root);
void	ft_fill_image(t_root *root);
int		ft_key_hook(int keycode, t_root *root);
void	ft_rec(t_root *root, t_fdf *head, t_fdf *draw);
/* ft_drawAAline.c */
void	ft_i_put_pixel(t_root *root, int color, unsigned char opacity);
void	ft_get_pixel_pos(int x, int y, t_root *root);
void	ft_x_move(t_root *root, t_ld *ld);
void	ft_y_move(t_root *root, t_ld *ld);
void	ft_change_data(t_root *root, t_fdf *p_start, t_fdf *p_end);
/* ft_gradient.c */
int		ft_gradient(int cl_str, int cl_end, t_ld *ld);
/* ft_s_fdf.c */
void	ft_mod_cord(t_fdf *node, int x, int y, int z);
t_fdf	*ft_new_node(int x, int y, int z, int color);
void	ft_merge(t_fdf **up, t_fdf **down);
void	ft_get_root(int def_color, int err_color, t_root *new);
void	ft_get_ld(t_ld *ld, t_fdf *p_start, t_fdf *p_end, t_root *root);
/* ft_parse.c */
void	ft_diagonal(t_root *root);
void    ft_color(t_root *root, char **line, t_fdf **node);
t_fdf	*ft_loop(char *line, int n, t_root *root);
void	ft_spc(int *x, char *f, t_fdf **head, t_fdf **node);
int		ft_parse(int fd, t_root *root);
#endif

/* TO DO
 * types swap(int - double) in validating
 * look in t.c file examples of using minilibx
 * use brains sometimes ...
 */
