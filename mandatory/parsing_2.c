/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:18:40 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/16 15:45:40 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char **arr, int x, int y)
{
	if (arr[x][y] == '1' || arr[x][y] == '.' || arr[x][y] == 'E'
		|| arr[x][y] == 'N')
		return ;
	arr[x][y] = '.';
	check_path(arr, x + 1, y);
	check_path(arr, x, y + 1);
	check_path(arr, x - 1, y);
	check_path(arr, x, y - 1);
}

void	check_path_2(char **arr, int x, int y)
{
	if (arr[x][y] == '1' || arr[x][y] == '.' || arr[x][y] == 'N')
		return ;
	arr[x][y] = '.';
	check_path_2(arr, x + 1, y);
	check_path_2(arr, x, y + 1);
	check_path_2(arr, x - 1, y);
	check_path_2(arr, x, y - 1);
}

int	check_characters_existence(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'E')
			{
				if ((arr[i + 1][j] == '1') && (arr[i - 1][j] == '1')
					&& (arr[i][j + 1] == '1') && (arr[i][j - 1] == '1'))
					return (0);
			}
			if (arr[i][j] == 'P' || arr[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_e_existence(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map_validity(t_lm *map)
{
	char	**arr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	arr = to2arr(map);
	position_cordination(arr, &x, &y);
	check_path(arr, x, y);
	if (!check_characters_existence(arr))
		(write(2, "Error: Invalid map\n", 19), free_linked_list(&map),
			free_to_d_arr(arr), exit(EXIT_FAILURE));
	free_to_d_arr(arr);
	arr = to2arr(map);
	check_path_2(arr, x, y);
	if (check_e_existence(arr))
		(write(2, "Error: Invalid map\n", 19), free_linked_list(&map),
			free_to_d_arr(arr), exit(EXIT_FAILURE));
	free_linked_list(&map);
	free_to_d_arr(arr);
}
