/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:53:58 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/09 20:42:07 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		main(int ac, char **av)
{
	t_root	root;

	if (ac == 2)
	{
		ft_get_root(0xffffff, 0xffffff, &root);
		if (ft_parse(open(*(++av), O_RDONLY), &root))
		{
			if (root.status & 0x80)
				exit(ft_printf("Empty file\n"));
			if (root.status & 0x2)
				ft_diagonal(&root);
			ft_printf("return: validated\n");
		}
		ft_init_image(&root);
	}
	return (ft_printf("return: main\n"));
}
