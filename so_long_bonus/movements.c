/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:37:43 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/12 15:45:52 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_movements(t_data *data, int mov)
{
	char		*num;

	num = ft_itoa(mov);
	render_top_wall(*data, 0, 2);
	render_top_wall(*data, 0, 3);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		(2 * 64), (0 * 64), 0XFFFFFF, num);
	free(num);
}

void	move_right(t_data *data, int x, int y, int *mov)
{
	if ((data->arr[x][y + 1] == 'E' && !item_count(data->arr))
		|| data->arr[x][y + 1] == 'N')
	{
		close_window(data);
	}
	else if (data->arr[x][y + 1] != 'E')
	{
		(*mov)++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->tile, y * 64, x * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->right, (y + 1) * 64, x * 64);
		update_player_position(data->arr, x, y, 2);
	}
}

void	move_left(t_data *data, int x, int y, int *mov)
{
	if ((data->arr[x][y - 1] == 'E' && !item_count(data->arr))
		|| data->arr[x][y - 1] == 'N')
	{
		close_window(data);
	}
	else if (data->arr[x][y - 1] != 'E')
	{
		(*mov)++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->tile, y * 64, x * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->left, (y - 1) * 64, x * 64);
		update_player_position(data->arr, x, y, 0);
	}
}

void	move_up(t_data *data, int x, int y, int *mov)
{
	if ((data->arr[x - 1][y] == 'E' && !item_count(data->arr))
		|| data->arr[x - 1][y] == 'N')
	{
		close_window(data);
	}
	else if (data->arr[x - 1][y] != 'E')
	{
		(*mov)++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->tile, y * 64, x * 64);
		data->image = mlx_xpm_file_to_image(data->mlx_ptr, BACK,
				&(data->width), &(data->height));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->back, y * 64, (x - 1) * 64);
		update_player_position(data->arr, x, y, 13);
	}
}

void	move_down(t_data *data, int x, int y, int *mov)
{
	if ((data->arr[x + 1][y] == 'E' && !item_count(data->arr))
		|| data->arr[x + 1][y] == 'N')
	{
		close_window(data);
	}
	else if (data->arr[x + 1][y] != 'E')
	{
		(*mov)++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->tile, y * 64, x * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->front, y * 64, (x + 1) * 64);
		update_player_position(data->arr, x, y, 1);
	}
}
