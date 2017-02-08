/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:53:41 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/08 21:24:10 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_fdf		*ft_loop(char *line, int n)
{
	t_fdf			*node;
	t_fdf			*head;
	unsigned int	y;
	char			c;

	y = 0;
	f = 0;
	node = NULL;
	head = node;
	while (*line != '\0')
	{
		if (ft_isdigit(*line)  && !f && node == NULL)
		{
			node = ft_new_node(n, y, ft_atoi(line), NULL);
			++f;
		}
		if (*line == ',' && f)
			node->color = ft_strndup(line + 1, 8); /* to do */
		if (*line == ' ' && f)
		{
			y == 0 ? head = node : 0;
			node = node->right;
			--f;
			++y;
		}
		++line;
	}
	return (head);
}

int		ft_parse(int	fd, t_fdf *sp)
{
	char	*line;
	int		n;
	t_fdf	*tmp;

	n = -1;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_loop(line, sp, ++n);
		if (n > 0)
			ft_merge()
	}
	return (1);
}
