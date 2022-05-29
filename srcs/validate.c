/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:36:09 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/28 23:36:10 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_wall(t_map map);

int	validate_file_ext(char *filename)
{
	int		len;
	char	*ext;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	ext = filename + (len - 4);
	return (!ft_strncmp(".ber", ext, 4));
}

void	validate_map(t_data *data)
{
	t_map	m;

	m = data->map;
	if (m.grid_x * m.grid_y < 4 * 4)
		error_game(data, ERROR_MAP_INVALID, "map is small.");
	if (ft_strlen(m.filedata) != m.grid_x * m.grid_y + m.grid_y - 1)
		error_game(data, ERROR_MAP_INVALID, "map is not rect.");
	if (m.item == 0 || m.player == 0 || m.exit != 1)
		error_game(data, ERROR_MAP_INVALID, "map not meet minimun requirement");
	if (valid_wall(data->map) == 0)
		error_game(data, ERROR_MAP_INVALID, "map not covered with wall.");
}

static int	valid_wall(t_map map)
{
	int		i;
	int		x;
	int		y;
	char	*f;

	i = 0;
	x = 0;
	y = 0;
	f = map.filedata;
	while (f[i])
	{
		x = 0;
		while (f[i] && f[i] != '\n')
		{
			if ((x == 0 || x == map.grid_x - 1) && f[i] != '1')
				return (0);
			if ((y == 0 || y == map.grid_y -1) && f[i] != '1')
				return (0);
			i++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}
