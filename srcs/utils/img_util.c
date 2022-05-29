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

	if (TILE_SIZE == 32)
		dir = "images/sprites_32x32/";
	else
		dir = "images/sprites_64x64/";
	fpath = ft_strjoin(dir, path);
	img.mlx = mlx_xpm_file_to_image(data->mlx, fpath, &img.w, &img.h);
	free(fpath);
	return (img);
}

t_img	get_number_img(t_data *data, char c, t_img *img)
{
	if (img)
		mlx_destroy_image(data->mlx, img->mlx);
	if (c == '0')
		return (set_img(data, TEXT_NUMBER_0));
	if (c == '1')
		return (set_img(data, TEXT_NUMBER_1));
	if (c == '2')
		return (set_img(data, TEXT_NUMBER_2));
	if (c == '3')
		return (set_img(data, TEXT_NUMBER_3));
	if (c == '4')
		return (set_img(data, TEXT_NUMBER_4));
	if (c == '5')
		return (set_img(data, TEXT_NUMBER_5));
	if (c == '6')
		return (set_img(data, TEXT_NUMBER_6));
	if (c == '7')
		return (set_img(data, TEXT_NUMBER_7));
	if (c == '8')
		return (set_img(data, TEXT_NUMBER_8));
	if (c == '9')
		return (set_img(data, TEXT_NUMBER_9));
	return (set_img(data, TEXT_NUMBER_0));
}
