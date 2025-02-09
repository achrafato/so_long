/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:32:38 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/07 12:25:16 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_data(t_data *data, char **arr)
{
	if ((str_len(arr[0]) - 1) > 40 || map_height(arr) > 22)
		(write(2, "Error: Invalid map dimensions\n", 30),
			free_to_d_arr(arr), exit(1));
	data->arr = arr;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		(free_to_d_arr(arr), exit(EXIT_FAILURE));
	data->width = ((str_len(arr[0]) - 1) * 64);
	data->height = (map_height(arr) * 64);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width,
			data->height, "so_long");
	if (!data->win_ptr)
		(free(data->mlx_ptr), free_to_d_arr(arr), exit(EXIT_FAILURE));
}

int	check_border(t_lm *head)
{
	t_lm	*last;
	int		len;

	len = head->len;
	last = last_node(head);
	if (last->line[last->len - 1] == '\n')
		return (1);
	last->len += 1;
	while (head)
	{
		if (head->line[0] != '1' || head->line[head->len - 2] != '1')
			return (1);
		if (head->len != len)
			return (1);
		head = head->next;
	}
	return (0);
}

int	all_wall(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\n' && str[i])
	{
		if (str[i++] != '1')
			return (0);
	}
	return (1);
}

int	line_validity(char *str, int *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		if (str[i] == 'E')
			p[0] += 1;
		if (str[i] == 'C')
			p[1] += 1;
		if (str[i] == 'P')
			p[2] += 1;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (i < (str_len(str) - 1))
			if (str[i] != 'E' && str[i] != 'C' && str[i] != 'P' && str[i] != '0'
				&& str[i] != '1' && str[i] != 'N')
				return (1);
		i++;
	}
	return (0);
}

int	check_rectangular_shape(t_lm *head)
{
	t_lm		*top;
	t_lm		*last_line;
	static int	arr[3];

	top = head;
	last_line = last_node(head);
	while (head)
	{
		if (head == top || head == last_line)
		{
			if (!all_wall(head->line))
				return (1);
			head = head->next;
			if (!head)
				break ;
		}
		if (line_validity(head->line, arr))
			return (1);
		head = head->next;
	}
	if (arr[0] != 1 || arr[1] < 1 || arr[2] != 1)
		return (1);
	return (0);
}
