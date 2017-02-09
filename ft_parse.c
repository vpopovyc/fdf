/* ************************************************************************** */

/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:53:41 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/09 17:08:50 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"


void		ft_spc(unsigned int *y, unsigned char *f, t_fdf **head, t_fdf **node)
{
	static	t_fdf	*tmp;
	
	if (*y == 0)
	{
		tmp = *node;
		*head = *node;
		*node = NULL;
		--*f;
		++*y;
		return ;
	}
	tmp->right = *node;
	tmp = *node;
	*node = NULL;
	--*f;
	++*y;
}

t_fdf		*ft_loop(char *line, int n)
{
	t_fdf			*node;
	t_fdf			*head;
	unsigned int	y;
	unsigned char	f;

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
		*line == ',' && f ?	node->color = ft_strndup(line + 1, 8) : 0; 
		*line == ' ' && f ? ft_spc(&y, &f, &head, &node) : 0;
		++line;
	}
	return (head);
}

int		ft_parse(int	fd, t_fdf **sp)
{
	char	*line;
	int		n;
	t_fdf	*up;
	t_fdf	*down;

	n = -1;
	line = NULL;
	get_next_line(fd, &line);
	*sp = ft_loop(line, ++n);
	up = *sp;
	while (get_next_line(fd, &line) > 0)
	{
		down = ft_loop(line, ++n);
		ft_merge(&up, &down);                      /* use static here for y */
		up = down;
		free(line);
	}
	return (1);
}
