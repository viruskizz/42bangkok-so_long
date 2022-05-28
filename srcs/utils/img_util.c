/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:57:25 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 01:57:27 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	set_img(t_data *data, char *path)
{
	t_img	img;
	char	*dir;
	char	*fpath;

	dir = "images/sprites_64x64/";
	fpath = ft_strjoin(dir, path);
	img.mlx = mlx_xpm_file_to_image(data->mlx, fpath, &img.w, &img.h);
	free(fpath);
	return (img);
}

t_img	get_number_img(t_data *data, char c)
{
	if (c == '0')
		return (set_img(data, "numbers/0.xpm"));
	if (c == '1')
		return (set_img(data, "numbers/1.xpm"));
	if (c == '2')
		return (set_img(data, "numbers/2.xpm"));
	if (c == '3')
		return (set_img(data, "numbers/3.xpm"));
	if (c == '4')
		return (set_img(data, "numbers/4.xpm"));
	if (c == '5')
		return (set_img(data, "numbers/5.xpm"));
	if (c == '6')
		return (set_img(data, "numbers/6.xpm"));
	if (c == '7')
		return (set_img(data, "numbers/7.xpm"));
	if (c == '8')
		return (set_img(data, "numbers/8.xpm"));
	if (c == '9')
		return (set_img(data, "numbers/9.xpm"));
	return (set_img(data, "numbers/0.xpm"));
}
