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
	t_img 	img;
	char	*dir;
	char	*fpath;

	dir = "images/sprites_64x64/";
	fpath = ft_strjoin(dir, path);
	img.mlx = mlx_xpm_file_to_image(data->mlx, fpath, &img.w, &img.h);
	free(fpath);
	return (img);
}
