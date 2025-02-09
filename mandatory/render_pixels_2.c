/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixels_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:28:55 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/12 15:10:48 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_rock(t_data data, int i, int j)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.pic->rock, j * 64, i * 64);
}

void	render_top_wall(t_data data, int i, int j)
{
	(void)i;
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.pic->wall_top, j * 64, 0 * 64);
}

void	render_bottom_wall(t_data data, int i, int j)
{
	(void)i;
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.pic->wall_bottom, j * 64, (map_height(data.arr) - 1) * 64);
}

void	render_wall_angles_left_right(t_data data, int i, int j)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.pic->wall_angles, j * 64, i * 64);
}

void	render_open_door(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	door_cordination(data->arr, &x, &y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->pic->door_last, y * 64, x * 64);
}
