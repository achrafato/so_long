/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixels_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:31:34 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/19 16:23:36 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_each_image(char **arr, t_data data, int i, int j)
{
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (j == 0 || j == (str_len(arr[i]) - 2)
				|| (j == (str_len(arr[i]) - 1) && i == map_height(arr) - 1))
				render_wall_angles_left_right(data, i, j);
			if (j != 0 && arr[map_height(arr) - 1][j] == '1'
			&& j != (str_len(arr[0]) - 2))
				render_bottom_wall(data, i, j);
			if (j != 0 && arr[0][j] == '1' && j != (str_len(arr[0]) - 2))
				render_top_wall(data, i, j);
			if (i != 0 && i != (map_height(arr) - 1) && j != 0
				&& j != (str_len(arr[0]) - 2) && arr[i][j] == '1')
				render_rock(data, i, j);
			if (arr[i][j] == '0')
				render_path(data, i, j);
			if (arr[i][j] == 'C')
				render_collectibles(data, i, j);
			j++;
		}
		i++;
	}
}

int	on_keypress(int keysym, t_data *data)
{
	int			x;
	int			y;
	static int	mov;

	x = 0;
	y = 0;
	if (keysym == 53 || keysym == 12)
		(close_window(data), exit(0));
	position_cordination(data->arr, &x, &y);
	if (data->arr[x][y + 1] != '1' && keysym == 2)
		move_right(data, x, y, &mov);
	else if (data->arr[x][y - 1] != '1' && keysym == 0)
		move_left(data, x, y, &mov);
	else if (data->arr[x - 1][y] != '1' && keysym == 13)
		move_up(data, x, y, &mov);
	else if (data->arr[x + 1][y] != '1' && keysym == 1)
		move_down(data, x, y, &mov);
	if (!item_count(data->arr))
		render_open_door(data);
	return (0);
}

int	close_window(t_data *data)
{
	destroy_image(data, data->pic);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	free_to_d_arr(data->arr);
	exit(0);
}

void	init_images(t_data *data)
{
	data->pic = (t_pic *)malloc(sizeof(t_pic));
	if (!data->pic)
		close_window(data);
	data->pic->enemy_1 = load_image(ENEMY_1, data);
	data->pic->enemy_2 = load_image(ENEMY_2, data);
	data->pic->back = load_image(BACK, data);
	data->pic->front = load_image(FRONT, data);
	data->pic->left = load_image(LEFT, data);
	data->pic->right = load_image(RIGHT, data);
	data->pic->coin = load_image(COIN, data);
	data->pic->door = load_image(CLOSED_DOOR, data);
	data->pic->door_last = load_image(OPENED_DOOR, data);
	data->pic->tile = load_image(TILE, data);
	data->pic->wall_angles = load_image(ANGLES_WALL, data);
	data->pic->wall_bottom = load_image(WALL_BOTTOM, data);
	data->pic->wall_top = load_image(WALL_TOP, data);
	data->pic->rock = load_image(WALL_CENTER, data);
}

void	render_pixels(char **arr)
{
	t_data	data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fill_data(&data, arr);
	if (check_xpms(&data))
		(end_game(&data), exit(1));
	init_images(&data);
	exit_cordination(arr, &i, &j);
	render_exit(data, i, j);
	position_cordination(arr, &i, &j);
	render_person(data, i, j);
	i = 0;
	j = 0;
	render_each_image(arr, data, i, j);
	mlx_hook(data.win_ptr, 2, 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
	free_to_d_arr(arr);
}
