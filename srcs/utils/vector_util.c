/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:06:44 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/28 23:06:45 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vtr	set_vtr(int x, int y)
{
	t_vtr	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vtr	add_vtr(t_vtr v1, t_vtr v2)
{
	t_vtr	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	return (v3);
}

t_vtr	get_move_vtr(int drct, int msize)
{
	t_vtr	v;
	int		m;

	v.x = 0;
	v.y = 0;
	if (msize == 0)
		m = TILE_SIZE;
	else
		m = msize;
	if (drct == DIRCT_LEFT)
		v.x = m * -1;
	if (drct == DIRCT_RIGHT)
		v.x = m;
	if (drct == DIRCT_UP)
		v.y = m * -1;
	if (drct == DIRCT_DOWN)
		v.y = m;
	return (v);
}
