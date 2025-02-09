/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixels_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:25:51 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/18 22:18:06 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	destroy_image(t_data *data, t_pic *images)
{
	mlx_destroy_image(data->mlx_ptr, images->back);
	mlx_destroy_image(data->mlx_ptr, images->coin);
	mlx_destroy_image(data->mlx_ptr, images->door);
	mlx_destroy_image(data->mlx_ptr, images->door_last);
	mlx_destroy_image(data->mlx_ptr, images->enemy_1);
	mlx_destroy_image(data->mlx_ptr, images->enemy_2);
	mlx_destroy_image(data->mlx_ptr, images->front);
	mlx_destroy_image(data->mlx_ptr, images->left);
	mlx_destroy_image(data->mlx_ptr, images->right);
	mlx_destroy_image(data->mlx_ptr, images->rock);
	mlx_destroy_image(data->mlx_ptr, images->tile);
	mlx_destroy_image(data->mlx_ptr, images->wall_angles);
	mlx_destroy_image(data->mlx_ptr, images->wall_bottom);
	mlx_destroy_image(data->mlx_ptr, images->wall_top);
}
