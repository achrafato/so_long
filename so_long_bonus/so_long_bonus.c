/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:32:40 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/19 16:35:04 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_player_position(char **arr, int x, int y, int key)
{
	if (key == 2)
	{
		arr[x][y + 1] = 'P';
		arr[x][y] = '0';
	}
	else if (key == 0)
	{
		arr[x][y - 1] = 'P';
		arr[x][y] = '0';
	}
	else if (key == 13)
	{
		arr[x - 1][y] = 'P';
		arr[x][y] = '0';
	}
	else if (key == 1)
	{
		arr[x + 1][y] = 'P';
		arr[x][y] = '0';
	}
}

void	p_error(char *str)
{
	write(2, str, str_len(str));
}

int	check_file_extension(char *str)
{
	int	len;

	len = str_len(str);
	if (str[len - 1] != 'r' || str[len - 2] != 'e'
		|| str[len - 3] != 'b' || str[len - 4] != '.')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_lm	*map;
	char	*str;
	char	**arr;

	map = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1 || check_file_extension(argv[1]))
			(write(2, "Error: open fail\n", 17), close(fd), exit(EXIT_FAILURE));
		str = get_next_line(fd);
		if (!str)
			(write(2, "Error: empty file\n", 18), close(fd), exit (1));
		while (str)
			(push(str, &map), str = get_next_line(fd));
		if (!close(fd) && check_border(map))
			return (free_linked_list(&map), p_error("Error: borders !\n"), 1);
		if (check_rectangular_shape(map))
			return (free_linked_list(&map), p_error("Error: invld map\n"), 1);
		arr = to2arr(map);
		check_map_validity(map);
		render_pixels(arr);
	}
	return (0);
}
