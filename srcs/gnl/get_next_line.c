/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:03:04 by araiva            #+#    #+#             */
/*   Updated: 2022/03/13 15:06:44 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_file	*find_line(t_file *f);
t_file	*readline(int fd, t_file *f);
t_file	initial(t_file file);

char	*get_next_line(int fd)
{
	static t_file	file;
	t_file			*f;

	if ((fd < 0 || fd > 999) && !(read(fd, "\0", 0)))
		return (NULL);
	if (file.is_end == -1)
		return (NULL);
	file = initial(file);
	if (!file.str)
		return (NULL);
	f = &file;
	if (!find_line(f))
		return (NULL);
	if (f->line)
		return (f->line);
	if (!readline(fd, f))
		return (NULL);
	if (f->line)
		return (f->line);
	f->is_end = -1;
	free(f->line);
	if (f->str[0])
		return (f->str);
	free(f->str);
	return (NULL);
}

t_file	initial(t_file file)
{
	if (file.str == NULL)
	{
		file.str = malloc(BUFFER_SIZE + 1);
		if (!file.str)
			return (file);
		file.str[0] = 0;
	}
	return (file);
}

t_file	*find_line(t_file *f)
{
	int		i;
	int		n;
	char	*tmp;

	n = my_strlen(f->str);
	i = 0;
	while (i < n)
	{
		if (f->str[i++] == '\n')
		{
			tmp = my_strcat(NULL, f->str);
			if (!tmp)
				return (NULL);
			f->line = my_substr(tmp, 0, i);
			if (!f->line)
				return (NULL);
			f->str = my_substr(f->str, my_strlen(f->line), my_strlen(f->str));
			if (!f->str)
				return (NULL);
			return (f);
		}
	}
	f->line = NULL;
	return (f);
}

t_file	*readline(int fd, t_file *f)
{
	int				ret;
	char			*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[0] = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = 0;
		f->str = my_strcat(f->str, buf);
		if (!f->str)
			return (NULL);
		if (!find_line(f))
			return (NULL);
		if (f->line)
		{
			free(buf);
			return (f);
		}
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (f);
}
