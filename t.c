/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:27:45 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/09 20:40:32 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_fdf	*ft_loop(char *line, int n)
{
	t_fdf			*node;
	t_fdf			*head;
	unsigned int    y;
	unsigned char   f;
	
	y = 0;
	f = 0;
	node = NULL;
	head = NULL;
	while (*line != '\0')
	{
		if (ft_isdigit(*line)  && !f && node == NULL)
		{
			node = ft_new_node(n, y, ft_atoi(line), NULL);
			f = 1;
		}
		*line == ',' && f ? node->color = ft_strndup(line + 1, 8) : 0;
		*line == ' ' && f ? ft_spc(&y, &f, &head, &node) : 0;
		++line;
	}
	return (head);
}

int		main(void)
{
	t_fdf *t;

	t = ft_loop("1,0xffabcd 2,0x09AAFF 3 4 5", 0);
	printf("x: %i\ny: %i\nz: %i\ncolor: %s\n", t->c_x, t->c_y, t->c_z, t->color);
	printf("\nx: %i\ny: %i\nz: %i\ncolor: %s\n", t->right->c_x, t->right->c_y, t->right->c_z, t->right->color);
	printf("\nx: %i\ny: %i\nz: %i\ncolor: %s\n", t->right->right->c_x, t->right->right->c_y, t->right->right->c_z, t->right->right->color);
	return (0);
}
