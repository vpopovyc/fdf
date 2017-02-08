/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:53:58 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/08 21:21:54 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		main(int ac, char **av)
{
	t_fdf	*sp;

	if (ac == 2)
	{
		sp = ft_new_node(0, 0, 0, NULL);
		if (ft_parse(open(*(++av), O_RDONLY), sp))
		{
			printf("x: %i\ny: %i\nz: %i\ncolor: %s\n", sp->c_x, sp->c_y, sp->c_z, sp->color);
			return (printf("return: validated\n"));
		}
	}
	return (printf("return: main\n"));
}
