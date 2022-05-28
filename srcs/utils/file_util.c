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
#include <fcntl.h>
#include "so_long.h"

static char	*read_file(t_data *data, char *filename);
static void	init_map_data(t_data *data, char *file);
static int	valid_file_ext(t_data *data, char *filename);
static char	*ft_str_concat(char *dest, char *src);

void	load_file(t_data *data, char *filename)
{
	char	*file;
	char	*f;

	file = read_file(data, filename);
	f = file;
	init_map_data(data, NULL);
	while (*f)
	{
		while (*f && *f != '\n')
		{
			if (data->map.grid_y == 0)
				data->map.grid_x++;
			if (*f == 'C')
				data->map.item++;
			else if (*f == 'E')
				data->map.exit++;
			else if (*f == 'P')
				data->map.player++;
			else if (*f == 'M')
				data->map.enemy++;
			f++;
		}
		data->map.grid_y++;
		f++;
	}
	init_map_data(data, file);
}

static char	*read_file(t_data *data, char *filename)
{
	int		fd;
	int		ret;
	char	*buf;
	char	*file;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_game(data, ERROR_FILE_OPEN, "file not found.");
	if (!valid_file_ext(data, filename))
		error_game(data, ERROR_FILE_OPEN, "file extension is not `.ber`");
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

static void	init_map_data(t_data *data, char *file)
{
	if (!file)
	{
		data->map.grid_x = 0;
		data->map.grid_y = 0;
		data->map.item = 0;
		data->map.exit = 0;
		data->map.player = 0;
		data->map.boss = 1;
		data->map.enemy = 1;
	}
	else
	{
		data->map.filedata = file;
		data->map.width = data->map.grid_x * TILE_SIZE;
		data->map.height = data->map.grid_y * TILE_SIZE;
	}
}

static int	valid_file_ext(t_data *data, char *filename)
{
	int		len;
	char	*ext;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	ext = filename + (len - 4);
	return (!ft_strncmp(".ber", ext, 4));
}

static char	*ft_str_concat(char *dest, char *src)
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
