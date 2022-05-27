/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:50:18 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/26 02:50:20 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inspect_map(t_data *data, char attr)
{
	t_map	map;

	map = data->map;
	if (attr == 'F')
		ft_printf("%s\n", map.filedata);
	ft_printf("== [%d] x [%d] ==\n", map.grid_x, map.grid_y);
	ft_printf("== %d x %d ==\n", map.width, map.height);
	ft_printf("[C] = %d\n", map.item);
	ft_printf("[E] = %d\n", map.exit);
	ft_printf("[P] = %d\n", map.player);
}
