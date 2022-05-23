#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "so_long.h"

// char	*my_strcat(char *str, char *dest)
// {
// 	int		len;
// 	int 	i;
// 	int		j;
// 	char	*new;

// 	i = 0;
// 	new = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(dest) + 1));
// 	while (str[i])
// 	{
// 		new[i] = str[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (dest[j])
// 	{
// 		new[i] = dest[j];
// 		i++;
// 		j++;
// 	}
// 	new[i] = '\0';
// 	free(str);
// 	return (new);
// }

void	read_file(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	char	*buf;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	buf = ft_calloc(sizeof(char), 1);
	data->map.tile_x = ft_strlen(line) - 1;
	while(line && *line)
	{
		data->map.tile_y++;
		tmp = buf;
		buf = ft_strjoin(tmp, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	data->map.width = data->map.tile_x * TILE_SIZE;
	data->map.height = data->map.tile_y * TILE_SIZE;
	data->map.filedata = buf;
}