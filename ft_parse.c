/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:53:41 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/09 17:08:50 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_diagonal(t_root *root)
{
	t_fdf	*first;
	t_fdf	*second;
	t_fdf	*tmp_f;
	t_fdf	*tmp_s;
	
	first = root->head->right;
	second = root->head->down;
	while (second)
	{
		tmp_f = first;
		tmp_s = second;
		while (first)
		{
			first->diag = second;
			first = first->right;
			second = second->right;
		}
		first = tmp_f;
		first = first->down;
		second = tmp_s;
		second = second->down;
	}
}

void		ft_spc(size_t *x, char *f, t_fdf **head, t_fdf **node)
{
	static	t_fdf	*tmp;
	
	if (*x == 0)
	{
		tmp = *node;
		*head = *node;
		*node = NULL;
		*f &= 0x0;
		++*x;
		return ;
	}
	tmp->right = *node;
	tmp = *node;
	*node = NULL;
	*f &= 0x0;
	++*x;
}

void        ft_color(t_root *root, char **line, t_fdf **node)
{
    char    pt[BS + 1];
    int     nb;
    int     hex_len;
    int     tmp;
    
    nb = BS;
    root->status |= 0x2;
	*line += 1;
    ft_charstc(pt, BS, "0x000000");
    if (**line == '0' && *(*line + 1) == 'x')
    {
        *line += 2;
        hex_len = (int)ft_chexlen(*line);
        tmp = hex_len;
        while (--hex_len >= 0)
            pt[--nb] = *((*line)++);
        (*node)->color = ft_atoi_base(pt, 16);
    }
    else
        (*node)->color = root->err_color;
}

t_fdf		*ft_loop(char *line, int n, t_root *root)
{
	t_fdf			*node;
	t_fdf			*head;
	size_t			x;
	char			f;

	x = 0;
	f = 0;
	node = NULL;
	head = NULL;
	while (*line != '\0' && (n == 0 || (n > 0 && x < root->matrix_size)))
	{
		if (ft_isdigit(*line)  && !f && node == NULL)
		{
			node = ft_new_node(n, (int)x, ft_atoi(line), root->def_color);
			f |= 0x1;
		}
		*line == ',' && f ?	ft_color(root, &line, &node) : 0;
		*line == ' ' && f ? ft_spc(&x, &f, &head, &node) : 0;
		++line;
	}
    f == 1 ? ft_spc(&x, &f, &head, &node) : 0;
	n > 0 && x < root->matrix_size ? root->status |= 0x40 : 0;
	n == 0 ? root->matrix_size = x : 0;
	return (head);
}

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

int			ft_parse(int	fd, t_root *root)
{
	char	*line;
	int		n;
	t_fdf	*up;
	t_fdf	*down;

	n = -1;
	line = NULL;
	get_next_line(fd, &line);
	root->head = ft_loop(line, ++n, root);
    up = root->head;
	while (get_next_line(fd, &line) > 0)
	{
		down = ft_loop(line, ++n, root);
		ft_merge(&up, &down);
		up = down;
		free(line);
	}
	return (1);
}
