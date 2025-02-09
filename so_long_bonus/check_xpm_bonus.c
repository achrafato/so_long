/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:35:25 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/19 15:56:14 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_xmp(t_data *data, char *str)
{
	data->image = mlx_xpm_file_to_image(data->mlx_ptr, str,
			&(data->width), &(data->height));
	if (!data->image)
		return (write(2, "Error: invalid xpm\n", 20), 0);
	return (1);
}

int	check_xpms(t_data *data)
{
	if (!check_xmp(data, RIGHT) || !check_xmp(data, LEFT)
		|| !check_xmp(data, BACK) || !check_xmp(data, FRONT)
		|| !check_xmp(data, OPENED_DOOR) || !check_xmp(data, CLOSED_DOOR)
		|| !check_xmp(data, ENEMY_1) || !check_xmp(data, ENEMY_2)
		|| !check_xmp(data, COIN) || !check_xmp(data, TILE)
		|| !check_xmp(data, WALL_CENTER) || !check_xmp(data, ANGLES_WALL)
		|| !check_xmp(data, WALL_BOTTOM) || !check_xmp(data, WALL_TOP))
		return (1);
	return (0);
}

void	*load_image(char *path, t_data *data)
{
	void	*image;

	image = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&(data->width), &(data->height));
	if (image == NULL)
	{
		write(2, "Error loading image\n", 20);
		(close_window(data), exit(EXIT_FAILURE));
	}
	return (image);
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
