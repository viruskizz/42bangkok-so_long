/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:08:24 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/28 23:08:26 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sprts_util(t_data *data, t_sprt *s)
{
	while (s)
	{
		if (s->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, s->img.mlx, s->v.x, s->v.y);
		s = s->next;
	}
}

void	render_sprts_fnc_util(t_data *data, t_sprt *s,
	void (*f)(t_data*, t_sprt*))
{
	while (s)
	{
		f(data, s);
		if (s->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, s->img.mlx, s->v.x, s->v.y);
		s = s->next;
	}
}

void	free_sprts_util(t_data *data, t_sprt *s)
{
	t_sprt	*tmp;

	tmp = s;
	while (s)
	{
		if (s->img.mlx)
			mlx_destroy_image(data->mlx, s->img.mlx);
		s = s->next;
	}
}