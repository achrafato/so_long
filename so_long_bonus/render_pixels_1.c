/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixels_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:25:51 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/19 16:32:28 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_exit(t_data data, int i, int j)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.pic->door, j * 64, i * 64);
}

void	render_collectibles(t_data data, int i, int j)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.pic->coin, j * 64, i * 64);
}

void	render_person(t_data data, int i, int j)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.pic->front, j * 64, i * 64);
}

void	render_path(t_data data, int i, int j)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.pic->tile, j * 64, i * 64);
}

void	end_game(t_data *data)
{
	free_to_d_arr(data->arr);
	exit(0);
}
