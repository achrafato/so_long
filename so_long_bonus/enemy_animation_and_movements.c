/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation_and_movements.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:43:15 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/12 15:47:25 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	adjust_vars(char **arr, int *r, int *l, int ind[2])
{
	if (arr[ind[0]][ind[1] - 1] == 'E' || arr[ind[0]][ind[1] - 1] == '1'
		|| arr[ind[0]][ind[1] - 1] == 'C' || arr[ind[0]][ind[1] - 1] == 'N')
	{
		*l = 1;
		*r = 1;
	}
	else if (arr[ind[0]][ind[1] + 1] == 'E' || arr[ind[0]][ind[1] + 1] == '1'
		|| arr[ind[0]][ind[1] + 1] == 'C' || arr[ind[0]][ind[1] + 1] == 'N')
	{
		*r = 0;
		*l = 0;
	}
}

void	random_move_enemy(t_data data, char **arr, int i, int *j)
{
	static int	l[21];
	static int	r[21];
	int			in[2];

	in[0] = i;
	in[1] = *j;
	adjust_vars(arr, &r[i], &l[i], in);
	if (!l[i] && arr[i][*j - 1] != 'E' && arr[i][*j - 1] != '1'
		&& arr[i][*j - 1] != 'C' && arr[i][*j - 1] != 'N')
	{
		if (arr[i][*j - 1] == 'P')
			close_window(&data);
		arr[i][*j] = '0';
		arr[i][*j - 1] = 'N';
	}
	if (r[i] && arr[i][*j + 1] != 'E' && arr[i][*j + 1] != '1'
		&& arr[i][*j + 1] != 'C' && arr[i][*j + 1] != 'N')
	{
		if (arr[i][*j + 1] == 'P')
			close_window(&data);
		arr[i][*j] = '0';
		arr[i][*j + 1] = 'N';
	}
	render_path(data, i, *j);
	(*j)++;
}

void	move_enemy(t_data data, char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'N')
				random_move_enemy(data, arr, i, &j);
			j++;
		}
		i++;
	}
}

void	render_enemy_animation(t_data *data, int i, int j)
{
	static int	count;

	if (count < 50)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->enemy_1, j * 64, i * 64);
		count++;
	}
	else if (count < 100)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pic->enemy_2, j * 64, i * 64);
	}
	if (count >= 100)
		(move_enemy(*data, data->arr), count = 0);
	count++;
}

int	enemy_loop(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->arr[i])
	{
		j = 0;
		while (data->arr[i][j])
		{
			if (data->arr[i][j] == 'N')
				render_enemy_animation(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
