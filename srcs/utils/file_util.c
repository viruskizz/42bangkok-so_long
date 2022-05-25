/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:57:34 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 01:57:36 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "so_long.h"

char	*ft_str_concat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(dest + i))
		i++;
	while (*src)
	{
		*(dest + i) = *src;
		i++;
		src++;
	}
	*(dest + i) = '\0';
	return (dest);
}

static char	*read_file(t_data *data, char *filename)
{
	int		fd;
	int		ret;
	char	*buf;
	char	*file;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_game(data, ERROR_FILE_OPEN);
	buf = malloc((BUF_SIZE + 1) * sizeof(char));
	file = malloc(sizeof(char) * 10000);
	ret = read(fd, buf, BUF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		ft_str_concat(file, buf);
		ret = read(fd, buf, BUF_SIZE);
	}
	free(buf);
	close(fd);
	return (file);
}

void	load_file(t_data *data, char *filename)
{
	int		i;
	char	*file;

	file = read_file(data, filename);
	i = 0;
	data->map.tile_x = 0;
	data->map.tile_y = 0;
	data->map.n_item = 0;
	data->map.n_exit = 0;
	data->map.n_sprt = 0;
	while (file[i])
	{
		while (file[i] != '\0' && file[i] != '\n')
		{
			if (data->map.tile_y == 0)
				data->map.tile_x++;
			if (file[i] == 'C')
				data->map.n_item++;
			else if (file[i] == 'E')
				data->map.n_exit++;
			else if (file[i] == 'P')
				data->map.n_sprt++;
			i++;
		}
		data->map.tile_y++;
		i++;
	}
	data->map.filedata = file;
	data->map.width = data->map.tile_x * TILE_SIZE;
	data->map.height = data->map.tile_y * TILE_SIZE;
}

int	valid_file(t_data *data)
{
	t_map	m;

	m = data->map;
	if (ft_strlen(m.filedata) != m.tile_x * m.tile_y)
		error_game(data, ERROR_MAP_INVALID);
	return (0);
}
