/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:58:28 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/21 19:58:30 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_gradient(int cl_str, int cl_end, t_ld *ld)
{
	int						res;
	static unsigned char	bt[7];
	static short			lt[3];
	static int				max;

	if (ld->cl_min == 0)
	{
		bt[0] = cl_str;
		bt[1] = cl_str >> 8;
		bt[2] = cl_str >> 16;
		bt[3] = cl_end;
		bt[4] = cl_end >> 8;
		bt[5] = cl_end >> 16;
		lt[0] = bt[0] - bt[3];
		lt[1] = bt[1] - bt[4];
		lt[2] = bt[2] - bt[5];
		max = ld->cl_max != 1 ? ld->cl_max - 1 : ld->cl_max;
	}
	res = 0;
	res += (bt[0] - lt[0] * ld->cl_min / max);
	res += (int)((bt[1] - lt[1] * ld->cl_min / max) << 8);
	res += (int)((bt[2] - lt[2] * ld->cl_min / max) << 16);
	return (res);
}
