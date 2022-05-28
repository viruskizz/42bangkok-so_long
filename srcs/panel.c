/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:59:32 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/28 22:59:34 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_number(t_data *data, int i);

void	load_panel(t_data *data)
{
	int		gx;
	int		gy;
	t_sprt	*bg;

	gx = 0;
	gy = data->map.grid_y;
	bg = data->panel.bg;
	data->panel.h = TILE_SIZE;
	data->panel.w = data->map.width;
	data->panel.v.x = 0;
	data->panel.v.y = data->map.height;
	data->panel.bg = NULL;
	while (gx < data->map.grid_x)
	{
		bg = malloc(sizeof(t_sprt));
		bg->img = set_img(data, OBJECT_GRASS_PATH);
		bg->v.x = gx * TILE_SIZE;
		bg->v.y = gy * TILE_SIZE;
		bg->next = NULL;
		if (!data->panel.bg)
			data->panel.bg = bg;
		else
			add_sprt_list(data->panel.bg, bg);
		gx++;
	}
}

void	load_score(t_data *data)
{
	int		i;

	data->panel.score = NULL;
	i = 0;
	while (i < 4)
		init_number(data, i++);
}

void	update_score(t_data *data)
{
	char	*txt;
	int		len;
	int		i;
	t_sprt	*s;

	txt = ft_itoa(data->player.moved);
	len = ft_strlen(txt);
	s = data->panel.score;
	i = 0;
	while (i < SCORE_LEN)
	{
		if (i == 3 && len >= 1)
			s->img = get_number_img(data, txt[len - 1]);
		else if (i == 2 && len >= 2)
			s->img = get_number_img(data, txt[len - 2]);
		else if (i == 1 && len >= 3)
			s->img = get_number_img(data, txt[len - 3]);
		else if (i == 0 && len == 4)
			s->img = get_number_img(data, txt[len - 4]);
		i++;
		s = s->next;
	}
}

static void	init_number(t_data *data, int i)
{
	int		sx;
	t_sprt	*s;

	// sx = (data->w / 2) - TILE_SIZE * 2;
	// sx = 0;
	sx = data->w - SCORE_LEN * TILE_SIZE;
	s = malloc(sizeof(t_sprt));
	s->v.x = sx + i * TILE_SIZE;
	s->v.y = data->map.height;
	s->img = get_number_img(data, '0');
	s->next = NULL;
	if (!data->panel.score)
		data->panel.score = s;
	else
		add_sprt_list(data->panel.score, s);
}
