/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:38 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/18 22:13:53 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_movements(t_data *data, int mov)
{
	char	*num;

	(void)data;
	num = ft_itoa(mov);
	write(1, num, str_len(num));
	write(1, "\n", 1);
	free(num);
}

void	move_right(t_data *data, int x, int y, int *mov)
{
	if ((data->arr[x][y + 1] == 'E' && !item_count(data->arr)))
	{
		(*mov)++;
		display_movements(data, *mov);
		(close_window(data), exit(0));
	}
	else if (data->arr[x][y + 1] != 'E')
	{
		(*mov)++;
		display_movements(data, *mov);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->tile, y * 64, x * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->right, (y + 1) * 64, x * 64);
		update_player_position(data->arr, x, y, 2);
	}
}

void	move_left(t_data *data, int x, int y, int *mov)
{
	if ((data->arr[x][y - 1] == 'E' && !item_count(data->arr)))
	{
		(*mov)++;
		display_movements(data, *mov);
		(close_window(data), exit(0));
	}
	else if (data->arr[x][y - 1] != 'E')
	{
		(*mov)++;
		display_movements(data, *mov);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->tile, y * 64, x * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->left, (y - 1) * 64, x * 64);
		update_player_position(data->arr, x, y, 0);
	}
}

void	move_up(t_data *data, int x, int y, int *mov)
{
	if ((data->arr[x - 1][y] == 'E' && !item_count(data->arr)))
	{
		(*mov)++;
		display_movements(data, *mov);
		(close_window(data), exit(0));
	}
	else if (data->arr[x - 1][y] != 'E')
	{
		(*mov)++;
		display_movements(data, *mov);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->tile, y * 64, x * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->back, y * 64, (x - 1) * 64);
		update_player_position(data->arr, x, y, 13);
	}
}

void	move_down(t_data *data, int x, int y, int *mov)
{
	if ((data->arr[x + 1][y] == 'E' && !item_count(data->arr)))
	{
		(*mov)++;
		display_movements(data, *mov);
		(close_window(data), exit(0));
	}
	else if (data->arr[x + 1][y] != 'E')
	{
		(*mov)++;
		display_movements(data, *mov);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->tile, y * 64, x * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->front, y * 64, (x + 1) * 64);
		update_player_position(data->arr, x, y, 1);
	}
}
